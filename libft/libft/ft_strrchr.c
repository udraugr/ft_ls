/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:54:50 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/22 17:19:40 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*str1;

	str1 = NULL;
	while (*str)
	{
		if (*str == c)
			str1 = str;
		str++;
	}
	if (!c)
		return ((char*)str);
	return ((char*)str1);
}
