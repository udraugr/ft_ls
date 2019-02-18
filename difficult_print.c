/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difficult_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:53:20 by udraugr-          #+#    #+#             */
/*   Updated: 2019/02/18 15:01:52 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ls.h"

static void				print_total(t_vector *begin, t_precision *ans, int dir)
{
	int					total;
	long long			tmp;
	t_file				*content;

	if (!begin || !((t_file *)begin->content))
		return ;
	total = 0;
	content = ((t_file *)(begin->content));
	while (begin)
	{
		content = ((t_file *)(begin->content));
		total += content->all->st_blocks;
		tmp = content->all->st_nlink;
		ans->numb_link = (ans->numb_link < tmp) ? tmp : ans->numb_link;
		tmp = ft_strlen(getpwuid(content->all->st_uid)->pw_name) + 1;
		ans->len_uid = (ans->len_uid < tmp) ? tmp : ans->len_uid;
		tmp = ft_strlen(getgrgid(content->all->st_gid)->gr_name) + 1;
		ans->len_grd = (ans->len_grd < tmp) ? tmp : ans->len_grd;
		tmp = content->all->st_size;
		ans->size_file = (ans->size_file < tmp) ? tmp : ans->size_file;
		begin = begin->next;
	}
	if (dir)
		ft_printf("total %d\n", total);
}

static void				len_numb(t_precision *ans)
{
	unsigned long long	numb_link;
	unsigned long long	size;

	size = ans->size_file;
	numb_link = ans->numb_link;
	ans->size_file = (!size) ? 1 : 0;
	while (size)
	{
		size /= 10;
		++ans->size_file;
	}
	ans->numb_link = (!numb_link) ? 1 : 0;
	while (numb_link)
	{
		numb_link /= 10;
		++ans->numb_link;
	}
}

static char				execute_permission(t_vector *begin,
		char mod_x, char usr)
{
	char				ans;
	mode_t				tmp;

	ans = mod_x;
	tmp = ((t_file *)begin->content)->all->st_mode;
	if (((tmp & S_ISUID && usr == 'u') || (tmp & S_ISGID && usr == 'g'))
			&& ans == 'x')
		ans = 's';
	else if (((tmp & S_ISUID && usr == 'u') || (tmp & S_ISGID && usr == 'g'))
			&& ans == '-')
		ans = 'S';
	else if ((tmp & S_ISVTX && usr == 'o') && ans == 'x')
		ans = 't';
	else if ((tmp & S_ISVTX && usr == 'o') && ans == '-')
		ans = 'T';
	return (ans);
}

static char				print_mod(t_vector *begin)
{
	char				mod[11];

	mod[0] = type_file(begin);
	mod[10] = extend(((t_file *)begin->content)->full_name);
	mod[1] = (((t_file *)begin->content)->all->st_mode & S_IRUSR) ? 'r' : '-';
	mod[2] = (((t_file *)begin->content)->all->st_mode & S_IWUSR) ? 'w' : '-';
	mod[3] = (((t_file *)begin->content)->all->st_mode & S_IXUSR) ? 'x' : '-';
	mod[3] = execute_permission(begin, mod[3], 'u');
	mod[4] = (((t_file *)begin->content)->all->st_mode & S_IRGRP) ? 'r' : '-';
	mod[5] = (((t_file *)begin->content)->all->st_mode & S_IWGRP) ? 'w' : '-';
	mod[6] = (((t_file *)begin->content)->all->st_mode & S_IXGRP) ? 'x' : '-';
	mod[6] = execute_permission(begin, mod[6], 'g');
	mod[7] = (((t_file *)begin->content)->all->st_mode & S_IROTH) ? 'r' : '-';
	mod[8] = (((t_file *)begin->content)->all->st_mode & S_IWOTH) ? 'w' : '-';
	mod[9] = (((t_file *)begin->content)->all->st_mode & S_IXOTH) ? 'x' : '-';
	mod[9] = execute_permission(begin, mod[9], 'o');
	write(1, mod, 11);
	return (mod[0]);
}

void					ft_difficult_print(t_vector *begin, int dir)
{
	t_precision			*ans;
	char				*tmp;
	char				*time;
	char				mod;

	if (!(ans = make_precision()))
		return ;
	print_total(begin, ans, dir);
	len_numb(ans);
	prove_on_device(begin, ans);
	while (begin)
	{
		take_time(&tmp, &time, begin);
		mod = print_mod(begin);
		ft_printf(" %*d", ans->numb_link,
				((t_file *)begin->content)->all->st_nlink);
		print_uid_grd(begin, ans);
		print_size(begin, ans, mod);
		ft_printf(" %s %s %s", tmp, time, ((t_file *)begin->content)->name);
		(mod == 'l') ? print_soft_link(begin) : write(1, "\n", 1);
		ft_clear_tfile((t_file *)begin->content);
		begin = begin->next;
	}
	free(ans);
	ans = 0;
}
