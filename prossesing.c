/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prossesing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:10:12 by udraugr-          #+#    #+#             */
/*   Updated: 2019/02/18 14:40:09 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ls.h"

static void		ft_compose_files(struct dirent *entry, t_fl *flags,
		t_vector **files, char **dir)
{
	t_file				*content;
	char				*tmp;
	char				*tmp2;

	if (!(content = (t_file *)malloc(sizeof(t_file))))
		return ;
	content->name = ft_strdup(entry->d_name);
	content->type = entry->d_type;
	content->all = 0;
	tmp = ft_strjoin(*dir, "/");
	tmp2 = tmp;
	tmp = ft_strjoin(tmp, entry->d_name);
	if (flags->t || flags->l)
	{
		content->all = (struct stat *)malloc(sizeof(struct stat));
		if (lstat(tmp, content->all) == -1)
			content->all = 0;
	}
	content->full_name = tmp;
	ft_strdel(&tmp2);
	if (!((*files) = ft_add_vector((*files), content)))
		return ;
}

static void		ft_compose_folds(struct dirent *entry, t_fl *flags,
		t_vector **folders, char **dir)
{
	char		*tmp;

	if (flags->upper_r &&
		(entry->d_type == 4 || !ft_strcmp(entry->d_name, "fd")) &&
		ft_strcmp(entry->d_name, "..") && ft_strcmp(entry->d_name, "."))
	{
		if (*dir[0] == '/' && ft_strlen(*dir) == 1)
			tmp = ft_strdup("/");
		else
			tmp = ft_strjoin(*dir, "/");
		if (!((*folders) = ft_add_vector((*folders),
						ft_strjoin(tmp, entry->d_name))))
			return ;
		free(tmp);
	}
}

static void		ft_prosessing_upper_r(t_fl *flags, t_vector **folders,
		int all, int lvl)
{
	if (!flags->upper_r || !folders || !(*folders))
		return ;
	ft_sort_folds(*folders, flags);
	while ((*folders) && (*folders)->next)
	{
		ft_prosessing((char **)&(*folders)->content, flags, all + 1, lvl + 1);
		(*folders) = (*folders)->next;
	}
	if (*folders)
	{
		ft_prosessing((char **)&(*folders)->content, flags, all + 1, lvl + 1);
		ft_delall_vector(folders);
	}
}

void			ft_prosessing(char **dir, t_fl *flags, int all, int lvl)
{
	DIR					*dir_stream;
	struct dirent		*entry;
	t_vector			*files;
	t_vector			*folders;

	if (lvl)
		write(1, "\n", 1);
	if (all > 1)
		ft_printf("%s:\n", *dir);
	if (ft_strstr(*dir, "42/munki") || !(dir_stream = open_dir(dir)))
		return ;
	files = 0;
	folders = 0;
	while ((entry = readdir(dir_stream)))
	{
		if (flags->a || entry->d_name[0] != '.')
		{
			ft_compose_files(entry, flags, &files, dir);
			ft_compose_folds(entry, flags, &folders, dir);
		}
	}
	ft_printf_out(files, flags, 1);
	ft_strdel(dir);
	closedir(dir_stream);
	ft_prosessing_upper_r(flags, &folders, all, lvl);
}
