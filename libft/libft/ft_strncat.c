/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:59:40 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/23 19:43:13 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, const char *source,
		size_t num)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (destination[j])
		j++;
	while (source[i] && i < num)
		destination[j++] = source[i++];
	destination[j] = '\0';
	return (destination);
}
