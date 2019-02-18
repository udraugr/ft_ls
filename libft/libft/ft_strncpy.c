/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:54:07 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/23 15:22:59 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destination, const char *source, size_t num)
{
	size_t		i;

	i = 0;
	while (i < num)
	{
		if (*source)
			destination[i++] = *(source++);
		else
			destination[i++] = '\0';
	}
	return (destination);
}
