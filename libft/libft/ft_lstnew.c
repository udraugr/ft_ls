/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:06:30 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/28 16:02:44 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy_copy(void *dst, const void *src, size_t n)
{
	size_t		count;
	void		*fin;

	count = 0;
	fin = dst;
	while (count++ < n)
		*((unsigned char*)dst++) = *((unsigned char*)src++);
	return (fin);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = (unsigned char *)malloc(content_size)))
		{
			free(list);
			return (NULL);
		}
		list->content = ft_memcpy_copy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
