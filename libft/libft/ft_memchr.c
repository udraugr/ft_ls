/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:09:11 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/26 13:24:23 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		count;

	count = 0;
	while (count++ < n)
	{
		if (*((unsigned char*)s) == (unsigned char)c)
			return ((void*)s);
		s++;
	}
	return (NULL);
}
