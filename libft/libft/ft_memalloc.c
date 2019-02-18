/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:26:41 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/28 12:29:30 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*area;

	area = (void*)malloc(size);
	if (!area)
		return (NULL);
	while (size)
		((unsigned char*)area)[size--] = 0;
	((unsigned char *)area)[0] = 0;
	return (area);
}
