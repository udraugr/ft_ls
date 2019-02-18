/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:00:20 by udraugr-          #+#    #+#             */
/*   Updated: 2018/11/28 14:06:05 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				max_index;
	int				negative;
	unsigned int	nb;
	char			*str;

	max_index = 1;
	negative = 0;
	if (n < 0 && ++negative)
		nb = n * -1;
	else
		nb = n;
	while ((n >= 10 || n <= -10) && max_index++)
		n /= 10;
	if (!(str = (char *)malloc((max_index + negative + 1) * sizeof(char))))
		return (NULL);
	str[max_index + negative] = '\0';
	while (--max_index + negative >= 0)
	{
		str[max_index + negative] = nb % 10 + '0';
		nb /= 10;
	}
	if (negative == 1)
		str[0] = '-';
	return (str);
}
