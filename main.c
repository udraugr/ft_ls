/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:39:17 by udraugr-          #+#    #+#             */
/*   Updated: 2019/02/16 14:54:23 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ls.h"

static void		pack_dirs(char **file_names, int numb_all_files,
		char ***dirs, struct stat *arr)
{
	int					i;
	int					j;
	unsigned short int	numb_dirs;

	i = -1;
	numb_dirs = 0;
	while (++i < numb_all_files)
		if (file_names[i] && S_ISDIR(arr[i].st_mode))
			++numb_dirs;
	if (!(*dirs = (char **)malloc(sizeof(char *) * (numb_dirs + 1))))
		return ;
	(*dirs)[numb_dirs] = 0;
	i = -1;
	j = -1;
	while (++i < numb_all_files)
		if (file_names[i] && S_ISDIR(arr[i].st_mode))
		{
			(*dirs)[++j] = ft_strdup(file_names[i]);
			ft_strdel(&file_names[i]);
		}
}

static void		sort_dirs(char **file_names, int numb_all_files,
		t_fl *flags, struct stat *arr)
{
	int			i;
	int			j;
	struct stat	tmp;

	if (!file_names || !flags || !arr || (!flags->r && !flags->t))
		return ;
	i = -1;
	while (++i < numb_all_files)
	{
		j = i;
		while (++j < numb_all_files)
		{
			if ((file_names[i] && file_names[j]) &&
			((flags->r && !flags->t &&
				ft_strcmp(file_names[i], file_names[j]) < 0) ||
			(!flags->r && flags->t && arr[i].st_mtime < arr[j].st_mtime) ||
			(flags->r && flags->t && arr[i].st_mtime > arr[j].st_mtime)))
			{
				ft_swap_str(&file_names[i], &file_names[j]);
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

static void		ft_packing(char **file_names, int numb_all_files,
		char ***dirs, t_fl *flags)
{
	unsigned short int	i;
	struct stat			*arr;

	if (!(arr = (struct stat *)malloc(sizeof(struct stat) * numb_all_files)))
		return ;
	i = 0;
	while (file_names[i])
	{
		if (lstat(file_names[i], &arr[i]) == -1)
		{
			error_errno(file_names[i]);
			ft_strdel(&file_names[i]);
		}
		++i;
	}
	sort_dirs(file_names, numb_all_files, flags, arr);
	pack_dirs(file_names, numb_all_files, dirs, arr);
	free(arr);
}

int				main(int argc, char **argv)
{
	t_fl				*flags;
	char				**file_names;
	char				**dirs;
	int					numb_all_files;
	int					i;

	file_names = ft_parcing(argc, argv, &flags, &numb_all_files);
	if (!numb_all_files)
	{
		free(file_names);
		if (!(file_names = (char **)malloc(sizeof(char *) * 2)))
			return (0);
		file_names[0] = ft_strdup(".");
		file_names[1] = 0;
		numb_all_files = 1;
	}
	ft_packing(file_names, numb_all_files, &dirs, flags);
	ft_transform(file_names, numb_all_files, flags, dirs[0]);
	i = -1;
	while (dirs[++i])
		ft_prosessing(&dirs[i], flags, numb_all_files, i);
	free(dirs);
	free(flags);
	flags = 0;
	return (0);
}
