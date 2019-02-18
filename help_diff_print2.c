/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_diff_print2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:36:58 by udraugr-          #+#    #+#             */
/*   Updated: 2019/02/17 15:28:29 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ls.h"

char					extend(char *filename)
{
	acl_t		acl;
	acl_entry_t	dummy;
	ssize_t		xattr;
	char		ans;

	xattr = 0;
	acl = 0;
	acl = acl_get_link_np(filename, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, 0, &dummy) == -1)
	{
		acl_free(acl);
		acl = 0;
	}
	xattr = listxattr(filename, 0, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		ans = '@';
	else if (acl)
		ans = '+';
	else
		ans = ' ';
	acl_free(acl);
	acl = NULL;
	return (ans);
}

void					print_size(t_vector *begin, t_precision *ans, char mod)
{
	int					tmp;

	if (mod == 'c' || mod == 'b')
	{
		tmp = (ans->size_file - 2) / 2;
		ft_printf(" %*d, %*d",
				tmp,
				major(((t_file *)begin->content)->all->st_rdev),
				tmp,
				minor(((t_file *)begin->content)->all->st_rdev));
	}
	else
	{
		ft_printf(" %*llu", ans->size_file,
				((t_file *)begin->content)->all->st_size);
	}
}

void					print_uid_grd(t_vector *begin, t_precision *ans)
{
	char				*tmp;

	tmp = getpwuid(((t_file *)begin->content)->all->st_uid)->pw_name;
	ft_printf(" %s", tmp);
	ft_printf("%*", ans->len_uid - ft_strlen(tmp) + 1);
	tmp = getgrgid(((t_file *)begin->content)->all->st_gid)->gr_name;
	ft_printf(" %s", tmp);
	ft_printf("%*", ans->len_grd - ft_strlen(tmp) + 1);
}

void					print_soft_link(t_vector *begin)
{
	char				tmp[4096];

	ft_memset(tmp, 0, 4096);
	readlink(((t_file *)begin->content)->full_name, tmp, 4096);
	ft_printf(" -> %s\n", tmp);
}
