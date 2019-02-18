/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:10:58 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/24 16:11:31 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t num)
{
	size_t		j;

	j = 0;
	while (j < num)
	{
		((unsigned char *)str)[j] = value;
		j++;
	}
	return (str);
}
