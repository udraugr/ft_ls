/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:52:36 by udraugr-          #+#    #+#             */
/*   Updated: 2019/02/16 14:01:48 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				neg;
	long long		ans;

	neg = 1;
	ans = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r'
			|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
			neg = -1;
	}
	while (*str <= 57 && *str >= 48)
	{
		ans = ans * 10 + *(str++) - '0';
		if (ans < 0)
		{
			if (neg == 1)
				return (-1);
			else
				return (0);
		}
	}
	return (ans * neg);
}
