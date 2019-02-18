/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:28:14 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 17:35:45 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfree(t_list *begin)
{
	t_list		*tmp;

	if (!begin)
		return (NULL);
	while (begin)
	{
		free(begin->content);
		begin->content_size = 0;
		tmp = begin;
		begin = begin->next;
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}
