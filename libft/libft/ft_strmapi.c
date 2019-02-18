/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:47:53 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 19:19:12 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	char	*str;

	size = 0;
	if (!s || !f)
		return (NULL);
	while (s[size])
		size++;
	str = (char*)malloc(size + 1);
	if (!str)
		return (NULL);
	size = 0;
	while (s[size])
	{
		str[size] = f(size, s[size]);
		size++;
	}
	str[size] = '\0';
	return (str);
}
