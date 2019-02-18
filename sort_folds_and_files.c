/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 13:26:37 by udraugr-          #+#    #+#             */
/*   Updated: 2019/02/08 16:35:31 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ls.h"

static int			ft_check_file(t_vector *tmp_i, t_vector *tmp_y, t_fl *flags)
{
	int				raznica_str;
	int				raznica_mtime;

	raznica_str = ft_strcmp(((t_file *)tmp_i->content)->name,
							((t_file *)tmp_y->content)->name);
	raznica_mtime = 0;
	if (flags->t || flags->l)
		raznica_mtime = ((t_file *)tmp_i->content)->all->st_mtime -
						((t_file *)tmp_y->content)->all->st_mtime;
	if ((!flags->t && !flags->r && raznica_str > 0) ||
		(!flags->t && flags->r && raznica_str < 0) ||
		(flags->t && !flags->r &&
			(raznica_mtime < 0 || (!raznica_mtime && raznica_str > 0))) ||
		(flags->t && flags->r &&
			(raznica_mtime > 0 || (!raznica_mtime && raznica_str < 0))))
		return (1);
	return (0);
}

static int			ft_check_dir(t_vector *tmp_i, t_vector *tmp_y, t_fl *flags)
{
	int				raznica_str;
	int				raznica_mtime;
	struct stat		stat1;
	struct stat		stat2;

	raznica_str = ft_strcmp(((char *)tmp_i->content),
							((char *)tmp_y->content));
	raznica_mtime = 0;
	if (flags->t || flags->l)
	{
		lstat((char *)tmp_i->content, &stat1);
		lstat((char *)tmp_y->content, &stat2);
		raznica_mtime = stat1.st_mtime - stat2.st_mtime;
	}
	if ((!flags->t && !flags->r && raznica_str > 0) ||
		(!flags->t && flags->r && raznica_str < 0) ||
		(flags->t && !flags->r &&
			(raznica_mtime < 0 || (!raznica_mtime && raznica_str > 0))) ||
		(flags->t && flags->r &&
			(raznica_mtime > 0 || (!raznica_mtime && raznica_str < 0))))
		return (1);
	return (0);
}

void				ft_sort_folds(t_vector *folders, t_fl *flags)
{
	t_vector		*tmp_i;
	t_vector		*tmp_y;

	tmp_i = folders;
	while (tmp_i)
	{
		tmp_y = tmp_i->next;
		while (tmp_y)
		{
			if (ft_check_dir(tmp_i, tmp_y, flags))
				ft_swap_vector(tmp_i, tmp_y);
			tmp_y = tmp_y->next;
		}
		tmp_i = tmp_i->next;
	}
}

void				ft_sort_files(t_vector *files, t_fl *flags)
{
	t_vector		*tmp_i;
	t_vector		*tmp_y;

	tmp_i = files;
	while (tmp_i)
	{
		tmp_y = tmp_i->next;
		while (tmp_y)
		{
			if (ft_check_file(tmp_i, tmp_y, flags))
				ft_swap_vector(tmp_i, tmp_y);
			tmp_y = tmp_y->next;
		}
		tmp_i = tmp_i->next;
	}
}
