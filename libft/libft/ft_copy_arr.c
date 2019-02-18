/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:54:29 by udraugr-          #+#    #+#             */
/*   Updated: 2019/01/27 15:54:58 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_copy_arr(int number_of_str, char **str_arr)
{
	char				**ans;
	unsigned short int	i;

	i = 0;
	ans = (char **)malloc(sizeof(char *) * number_of_str + 1);
	if (!ans || !str_arr)
		return (NULL);
	while (str_arr[i])
	{
		ans[i] = ft_strdup(str_arr[i]);
		++i;
	}
	ans[i] = 0;
	return (ans);
}
