/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:13:02 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/28 12:23:44 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t		i;

	i = 0;
	while ((*str1 || *str2) && i < num)
	{
		if (*str1 != *str2)
			return (*((unsigned char*)str1) - *((unsigned char*)str2));
		i++;
		str1++;
		str2++;
	}
	return (0);
}
