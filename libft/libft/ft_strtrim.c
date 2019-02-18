/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:00:29 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/28 13:28:30 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		end;
	char		*str;

	i = 0;
	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	end = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			end = i + 1;
		i++;
	}
	if (!(str = (char *)malloc(end + 1)))
		return (NULL);
	i = 0;
	while (i++ < end)
		str[i - 1] = s[i - 1];
	str[i - 1] = '\0';
	return (str);
}
