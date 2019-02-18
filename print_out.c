/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:50:08 by udraugr-          #+#    #+#             */
/*   Updated: 2019/02/18 14:41:09 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ls.h"

void				ft_clear_tfile(t_file *content)
{
	if (content->name)
		free(content->name);
	if (content->full_name)
		free(content->full_name);
	content->name = 0;
	content->full_name = 0;
	content->type = 0;
	if (content->all)
	{
		free(content->all);
		content->all = 0;
	}
}

static int			max_str(t_vector *begin)
{
	unsigned long	max;

	if (!begin)
		return (1);
	max = 0;
	while (begin)
	{
		if (ft_strlen(((t_file *)begin->content)->name) > max)
			max = ft_strlen(((t_file *)begin->content)->name);
		begin = begin->next;
	}
	return (max + 1);
}

static void			print_column(t_vector *begin, int max_s, int width)
{
	t_vector		*tmp;
	int				len;

	while (begin && begin->index < max_s)
	{
		tmp = begin;
		while (tmp)
		{
			len = ft_strlen(((t_file *)tmp->content)->name);
			ft_printf("%s", ((t_file *)tmp->content)->name);
			ft_printf("%*", width - len + 1);
			ft_clear_tfile((t_file *)tmp->content);
			tmp = ft_take_vector(tmp, tmp->index + max_s);
		}
		write(1, "\n", 1);
		begin = begin->next;
	}
}

static void			print_one(t_vector *begin)
{
	while (begin)
	{
		ft_printf("%s\n", ((t_file *)begin->content)->name);
		ft_clear_tfile((t_file *)begin->content);
		begin = begin->next;
	}
}

void				ft_printf_out(t_vector *begin, t_fl *flags, int dir)
{
	struct winsize	sz;
	int				max_s;
	int				width;
	int				n_column;

	ft_sort_files(begin, flags);
	if (flags->l)
		ft_difficult_print(begin, dir);
	else if (flags->one)
		print_one(begin);
	else
	{
		ioctl(0, TIOCGWINSZ, &sz);
		width = max_str(begin);
		n_column = (sz.ws_col / width > 0) ? sz.ws_col / width : 1;
		max_s = ft_count_vector(begin) / n_column;
		if (ft_count_vector(begin) % n_column)
			++max_s;
		print_column(begin, max_s, width);
	}
	ft_delall_vector(&begin);
}
