/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:55:41 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 11:55:37 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	unsigned char		tmp;
	unsigned char		d;
	unsigned char		e;

	tmp = c;
	if (tmp < 128)
		write(1, &tmp, 1);
	else
	{
		d = 192 + tmp / 64;
		e = 128 + tmp % 64;
		write(1, &d, 1);
		write(1, &e, 1);
	}
}
