/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 10:37:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/02/17 15:21:38 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ls.h"

char					type_file(t_vector *begin)
{
	int					type;

	type = ((t_file *)begin->content)->type;
	if (type == 4 || !type)
		return ('d');
	else if (type == 6)
		return ('b');
	else if (type == 2)
		return ('c');
	else if (type == 10)
		return ('l');
	else if (type == 8)
		return ('-');
	else if (type == 12)
		return ('s');
	else
		return ('p');
}

t_precision				*make_precision(void)
{
	t_precision			*ans;

	if (!(ans = (t_precision *)malloc(sizeof(t_precision))))
		return (0);
	ans->numb_link = 0;
	ans->len_uid = 0;
	ans->len_grd = 0;
	ans->size_file = 0;
	return (ans);
}

void					take_time(char **tmp, char **time_or_year,
		t_vector *begin)
{
	*tmp = ctime(&((t_file *)begin->content)->all->st_mtime);
	*tmp += 4;
	(*tmp)[6] = 0;
	if ((((t_file *)begin->content)->all->st_mtime - time(0) > 0) ||
		(((t_file *)begin->content)->all->st_mtime - time(0) <
				(-60 * 60 * 24 * 182.5)))
	{
		*time_or_year = *tmp + 15;
		(*tmp)[20] = 0;
	}
	else
	{
		*time_or_year = *tmp + 7;
		(*tmp)[12] = 0;
	}
}

static int				ft_max_major_minor(t_vector *begin)
{
	int					tmp;
	int					ans;

	tmp = 0;
	while (begin)
	{
		if (S_ISBLK(((t_file *)begin->content)->all->st_mode) ||
				S_ISCHR(((t_file *)begin->content)->all->st_mode))
		{
			tmp = ((int)major(((t_file*)begin->content)->all->st_rdev) > tmp) ?
				major(((t_file*)begin->content)->all->st_rdev) : tmp;
			tmp = ((int)minor(((t_file*)begin->content)->all->st_rdev) > tmp) ?
				minor(((t_file*)begin->content)->all->st_rdev) : tmp;
		}
		begin = begin->next;
	}
	ans = (!tmp) ? 1 : 0;
	while (tmp)
	{
		++ans;
		tmp = tmp / 10;
	}
	return (ans);
}

void					prove_on_device(t_vector *begin, t_precision *ans)
{
	t_vector			*tmp;
	int					device_on;
	int					max;

	tmp = begin;
	device_on = 0;
	while (tmp)
	{
		if (S_ISBLK(((t_file *)tmp->content)->all->st_mode) ||
				S_ISCHR(((t_file *)tmp->content)->all->st_mode))
		{
			device_on = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (device_on)
	{
		max = ft_max_major_minor(begin);
		ans->size_file = (max * 2 + 2 > (int)ans->size_file) ? max * 2 + 2
			: ans->size_file;
	}
}
