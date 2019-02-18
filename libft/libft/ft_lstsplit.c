/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:03:58 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 14:48:15 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				*ft_free_(t_list *begin)
{
	t_list		*tmp;

	while (begin)
	{
		if (begin->content)
		{
			free(begin->content);
			begin->content_size = 0;
		}
		tmp = begin;
		begin = begin->next;
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

static char const		*ft_len(char const *s, char c, t_list **curr,
		t_list *begin)
{
	size_t		len;

	if (*s)
	{
		if (!((*curr)->next = (t_list *)malloc(sizeof(t_list))))
			return (ft_free_(begin));
		*curr = (*curr)->next;
		(*curr)->next = NULL;
	}
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	(*curr)->content_size = len + 1;
	if (!((*curr)->content = (unsigned char *)malloc(len + 1)))
		return (ft_free_(begin));
	len = 0;
	while (*s && *s != c)
		((unsigned char*)(*curr)->content)[len++] = *(s++);
	((unsigned char *)(*curr)->content)[len] = '\0';
	while (*s && *s == c)
		s++;
	return (s);
}

t_list					*ft_lstsplit(char const *s, char c)
{
	t_list	*begin;
	t_list	*curr;
	t_list	*tmp;

	if (!s)
		return (NULL);
	while (*s && *s == c)
		s++;
	if (!(curr = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	curr->next = NULL;
	begin = curr;
	while (*s)
		s = ft_len(s, c, &curr, begin);
	tmp = begin;
	begin = begin->next;
	free(tmp);
	return (begin);
}
