/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:39:19 by udraugr-          #+#    #+#             */
/*   Updated: 2019/02/13 15:46:44 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ls.h"

void		error_flags(char flag)
{
	write(2, "ft_ls: illegal option -- ", 25);
	write(2, &flag, 1);
	write(2, "\nusage: ft_ls [-Ralrt] [file ...]\n", 34);
	exit(0);
}

void		error_errno(char *name)
{
	char	*tmp;

	if (!name)
		return ;
	tmp = name;
	while (*name)
	{
		if (*name == '/')
			tmp = name + 1;
		++name;
	}
	if (tmp[0] == '\0')
		tmp = "fts_open";
	write(2, "ft_ls: ", 7);
	write(2, tmp, ft_strlen(tmp));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}
