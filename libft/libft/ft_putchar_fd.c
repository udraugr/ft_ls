/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:13:55 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 12:00:45 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char		tmp;
	unsigned char		d;
	unsigned char		e;

	tmp = c;
	if (tmp < 128)
		write(fd, &c, 1);
	else
	{
		d = 192 + tmp / 64;
		e = 128 + tmp % 64;
		write(fd, &d, 1);
		write(fd, &e, 1);
	}
}
