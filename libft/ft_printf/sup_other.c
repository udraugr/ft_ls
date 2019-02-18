/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:12:34 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/27 19:22:52 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_sizeof_char(int c)
{
	int		ans;

	ans = 1;
	ans = (c > 127) ? ans + 1 : ans;
	ans = (c > 2047) ? ans + 1 : ans;
	ans = (c > 65535) ? ans + 1 : ans;
	return (ans);
}

int			ft_wstrlen(int precision, wchar_t *str)
{
	int		i;
	int		max;

	i = -1;
	max = 0;
	while (str[++i])
	{
		max += ft_sizeof_char(str[i]);
		if (max >= precision && precision != -1)
		{
			max = (max > precision) ?
				max - ft_sizeof_char(str[i]) : max;
			break ;
		}
	}
	return (max);
}
