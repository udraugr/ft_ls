/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:43:06 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 16:05:13 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_lstfold(int x, int *arr, int (*f)(int, int), int lenarr)
{
	int			i;
	long long	ans;

	if (arr && f)
	{
		i = 0;
		ans = x;
		while (i < lenarr)
			ans = f(ans, arr[i++]);
		return (ans);
	}
	return ((long long)x);
}
