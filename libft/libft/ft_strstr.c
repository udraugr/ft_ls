/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:35:39 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/22 16:53:15 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	const char	*str;

	i = 0;
	if (!(*needle))
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			str = haystack;
			while (*haystack && *(haystack++) == needle[i++])
				if (!needle[i])
					return ((char*)str);
			haystack = str;
			i = 0;
		}
		haystack++;
	}
	return (NULL);
}
