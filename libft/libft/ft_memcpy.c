/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:40:15 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 12:35:04 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		count;
	void		*fin;

	count = 0;
	if (!dst && !src)
		return (NULL);
	fin = dst;
	while (count++ < n)
		*((unsigned char*)dst++) = *((unsigned char*)src++);
	return (fin);
}
