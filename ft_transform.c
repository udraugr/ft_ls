/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:30:54 by udraugr-          #+#    #+#             */
/*   Updated: 2019/02/18 14:38:43 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ls.h"

static int		ft_type_detected(mode_t mode)
{
	int			ans;

	ans = 8;
	if (S_ISLNK(mode))
		ans = 10;
	else if (S_ISBLK(mode))
		ans = 6;
	else if (S_ISCHR(mode))
		ans = 2;
	else if (S_ISDIR(mode))
		ans = 4;
	else if (S_ISFIFO(mode))
		ans = 14;
	else if (S_ISSOCK(mode))
		ans = 12;
	return (ans);
}

static void		add_stat_in_vector(t_file *content, t_fl *flags)
{
	if (flags->l || flags->t)
	{
		content->all = (struct stat *)malloc(sizeof(struct stat));
		lstat(content->name, content->all);
		content->type = ft_type_detected(content->all->st_mode);
	}
	else
		content->all = 0;
}

void			ft_transform(char **file_names, int numb_all_files,
		t_fl *flags, char *dir)
{
	t_file		*content;
	t_vector	*begin;
	int			i;

	i = -1;
	begin = 0;
	while (++i < numb_all_files)
	{
		if (file_names[i])
		{
			if (!(content = (t_file *)malloc(sizeof(t_file))))
				return ;
			content->name = ft_strdup(file_names[i]);
			content->full_name = ft_strdup(file_names[i]);
			add_stat_in_vector(content, flags);
			begin = ft_add_vector(begin, content);
			ft_strdel(&file_names[i]);
		}
	}
	free(file_names);
	file_names = 0;
	if (begin)
		ft_printf_out(begin, flags, 0);
	if (dir && begin)
		write(1, "\n", 1);
}
