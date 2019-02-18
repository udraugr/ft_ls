/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:09:47 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 17:24:42 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *begin)
{
	int		len;

	if (!begin)
		return (0);
	len = 0;
	while (begin)
	{
		begin = begin->next;
		len++;
	}
	return (len);
}
