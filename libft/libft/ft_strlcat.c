/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:44:13 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/23 19:39:08 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		ans;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
		j++;
	if (i > size)
		return (j + size);
	ans = i + j;
	j = 0;
	while (src[j])
	{
		if (i < size - 1)
			dst[i++] = src[j];
		else if (i == size - 1)
			dst[i] = '\0';
		j++;
	}
	if (i <= size)
		dst[i] = '\0';
	return (ans);
}
