/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:16:22 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 16:33:38 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t		i;
	size_t		j;
	char		tmp;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		return (str);
	i--;
	j = 0;
	while (j < i)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		j++;
		i--;
	}
	return (str);
}
