/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:48:00 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/02 20:06:15 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	if (!(str = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	j += i;
	i = 0;
	while (i < j)
	{
		if (*s1)
			str[i++] = *(s1++);
		else
			str[i++] = *(s2++);
	}
	str[i] = '\0';
	return (str);
}
