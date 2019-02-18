/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:27:40 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 12:39:40 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	size_t		count;

	count = 0;
	while (count++ < n)
	{
		*((unsigned char*)dst) = *((unsigned char*)src);
		if (*((unsigned char*)src) == (unsigned char)c)
			return (++dst);
		src++;
		dst++;
	}
	return (NULL);
}
