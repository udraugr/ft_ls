/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:08:49 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/28 18:54:14 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_strsplit3(char const *s, char c, char **arr)
{
	size_t		j;
	size_t		i;
	size_t		tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			arr[j][tmp++] = s[i];
			arr[j][tmp] = '\0';
		}
		else if (s[i] == c && s[i - 1] != c)
		{
			arr[j][tmp] = '\0';
			j++;
			tmp = 0;
		}
		i++;
	}
	return (arr);
}

static char		**ft_free(size_t j, char **arr)
{
	j -= 2;
	while (j-- > 0)
		free(arr[j]);
	free(arr[j]);
	free(arr);
	return (NULL);
}

static char		**ft_strsplit2(char const *s, char c, char **arr)
{
	size_t		j;
	size_t		i;
	size_t		tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
		{
			if (!(arr[j++] = (char *)malloc(sizeof(char) * (tmp + 1))))
				return (ft_free(j, arr));
			tmp = 0;
		}
		else if (s[i] != c)
			tmp++;
		i++;
	}
	if (i != 0 && s[i - 1] != c)
		if (!(arr[j++] = (char *)malloc(sizeof(char) * tmp + 1)))
			return (ft_free(j, arr));
	arr[j] = 0;
	arr = ft_strsplit3(s, c, arr);
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		tmp;
	size_t		i;
	char		**arr;

	i = 0;
	tmp = 0;
	if (!s)
		return (NULL);
	while (*s && *s == c)
		s++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			tmp++;
		i++;
	}
	if (i != 0 && s[i - 1] != c)
		tmp++;
	if (!(arr = (char **)malloc(sizeof(char *) * (tmp + 1))))
		return (NULL);
	arr = ft_strsplit2(s, c, arr);
	return (arr);
}
