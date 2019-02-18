/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:25:37 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/22 16:51:00 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			j;
	const char		*str;

	j = 1;
	i = 0;
	if (!(*little))
		return ((char*)big);
	while (*big && j <= len)
	{
		if (*big == little[i])
		{
			str = big;
			while (*big && little[i] == *big && i + j <= len && ++i && ++big)
				if (!little[i])
					return ((char*)str);
			big = str;
			i = 0;
		}
		j++;
		big++;
	}
	return (NULL);
}
