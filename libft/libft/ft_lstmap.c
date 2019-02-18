/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:58:09 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/30 14:13:17 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_free_1(t_list *begin)
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

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*current;
	t_list		*begin;

	if (!lst || !f || !(current = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (lst)
	{
		current = f(lst);
		begin = current;
		lst = lst->next;
	}
	while (lst)
	{
		if (!(current->next = f(lst)))
			return (ft_free_1(begin));
		current = current->next;
		lst = lst->next;
	}
	current->next = NULL;
	return (begin);
}
