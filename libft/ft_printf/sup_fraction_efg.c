/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_fraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:29:58 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/29 16:36:23 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_itoa_fract(long long nbr)
{
	unsigned long long	nb;
	int					len;
	char				*str;

	nb = (nbr < 0) ? nbr * -1 : nbr;
	len = (!nbr) ? 1 : 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	str[len] = '\0';
	if (!nb)
		str[0] = '0';
	while (nb)
	{
		str[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}

static char		*ft_strnumb_fase_2(long double numb, int precision,
		int *order, char *str)
{
	long long	nbr;
	char		*tmp1;
	char		*tmp2;

	numb = (numb < 0) ? numb * -1 : numb;
	while (precision > 0)
	{
		precision--;
		numb *= 10;
		nbr = numb;
		tmp2 = ft_itoa_fract(nbr);
		numb -= (long double)nbr;
		tmp1 = str;
		str = ft_strjoin(str, tmp2);
		free(tmp1);
		free(tmp2);
	}
	if (order)
		*order = (numb * 10.0 > 5.0) ? 1 : 0;
	return (str);
}

char			*ft_okrug(char *str, int *order)
{
	int		i;

	if (!order)
		return (str);
	i = ft_strlen(str) - 1;
	while (i > -1)
	{
		if (*order && str[i] != '.')
		{
			str[i] += 1;
			*order = 0;
			if (str[i] > '9')
			{
				str[i] -= 10;
				*order = 1;
			}
		}
		i--;
	}
	return (str);
}

char			*ft_strnumb(long double numb, int precision, int *order,
		char conv)
{
	long long	number;
	char		*tmp;
	char		*str;
	int			i;

	precision = (precision == -1) ? 6 : precision;
	str = ft_itoa_fract(numb);
	number = numb;
	numb = numb - (long double)number;
	if (precision)
	{
		tmp = str;
		str = ft_strjoin(str, ".");
		free(tmp);
	}
	str = ft_strnumb_fase_2(numb, precision, order, str);
	str = ft_okrug(str, order);
	if (conv == 'g' || conv == 'G')
	{
		i = ft_strlen(str) - 1;
		while (str[i] == '0' && precision)
			str[i--] = '\0';
		str[i] = (str[i] == '.') ? '\0' : str[i];
	}
	return (str);
}
