/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:15:43 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/28 21:22:24 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == (size_t)(-1) || !(str = (char *)malloc(size + 1)))
		return (NULL);
	while (size)
		((unsigned char*)str)[size--] = 0;
	((unsigned char *)str)[0] = 0;
	return (str);
}
