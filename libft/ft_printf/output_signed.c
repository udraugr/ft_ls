/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_signed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 20:46:39 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/29 11:55:35 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_numlen(long long numb, int precision)
{
	int		len;

	len = (!numb && precision) ? 1 : 0;
	while (numb)
	{
		numb /= 10;
		len++;
	}
	return (len);
}

static void		ft_print_num(long long int numb)
{
	unsigned long long	tmp;
	int					i;
	char				mas[30];

	tmp = (numb < 0) ? numb * -1 : numb;
	i = 0;
	while (tmp > 9)
	{
		mas[i] = tmp % 10 + '0';
		i++;
		tmp /= 10;
	}
	tmp += '0';
	write(1, &tmp, 1);
	while (i)
		write(1, &(mas[i-- - 1]), 1);
}

static int		ft_output_signed_fase_2(t_options *modify,
		long long int numb)
{
	char	*sign;
	int		len_numb;
	int		len_conv;
	int		ans;

	sign = ft_sign_num(numb, modify->flags);
	len_numb = ft_numlen(numb, modify->precision);
	len_conv = (modify->precision > len_numb) ?
		modify->precision + ft_strlen(sign) : len_numb + ft_strlen(sign);
	ans = (len_conv > modify->min_width) ? len_conv : modify->min_width;
	if (modify->flags[1] == '1' && modify->precision == -1)
		ft_putstr(sign);
	while (modify->flags[4] == '0' && modify->min_width-- - len_conv > 0)
		write(1, (modify->flags[1] == '1' && modify->precision == -1) ?
			"0" : " ", 1);
	if (modify->flags[1] == '0' || modify->precision != -1)
		ft_putstr(sign);
	while (modify->precision-- - len_numb > 0)
		write(1, "0", 1);
	if (numb || len_numb)
		ft_print_num(numb);
	while (modify->flags[4] == '1' && modify->min_width-- - len_conv > 0)
		write(1, " ", 1);
	return (ans);
}

void			ft_output_signed(va_list ap, t_options *modify, int *ans)
{
	long long int		numb;

	if (ft_strstr(modify->modificator, "ll") ||
			ft_strchr(modify->modificator, 'z') ||
			ft_strchr(modify->modificator, 'j'))
		numb = va_arg(ap, long long);
	else if (ft_strchr(modify->modificator, 'l') || modify->conv == 'D')
		numb = va_arg(ap, long int);
	else if (ft_strstr(modify->modificator, "hh"))
		numb = (char)va_arg(ap, int);
	else if (ft_strchr(modify->modificator, 'h'))
		numb = (short)va_arg(ap, int);
	else
		numb = va_arg(ap, int);
	*ans += ft_output_signed_fase_2(modify, numb);
}
