/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:44:16 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 12:28:43 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		count;
	int		i;

	count = len;
	if (!dst && !src)
		return (NULL);
	while (count-- > 0)
	{
		if (dst > src)
			((unsigned char *)dst)[count] = ((unsigned char *)src)[count];
		else if (dst == src)
			break ;
		else
		{
			i = len - count - 1;
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	return (dst);
}
