/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:38:01 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/23 18:28:32 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *source)
{
	size_t	i;

	i = 0;
	while (destination[i])
		i++;
	while (*source)
		destination[i++] = *(source++);
	destination[i] = '\0';
	return (destination);
}
