/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 20:46:39 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/26 04:04:03 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_numlen(unsigned long long numb, int base, int precision)
{
	int		len;

	len = (!numb && precision) ? 1 : 0;
	while (numb)
	{
		numb /= base;
		len++;
	}
	return (len);
}

static void		ft_print_num(unsigned long long numb, unsigned long long base,
		char conv)
{
	char		mas[30];
	int			i;

	i = 0;
	while (numb >= base)
	{
		mas[i] = numb % base;
		mas[i] = (mas[i] > 9) ? mas[i] + 87 : mas[i] + 48;
		if (conv == 'X' && (mas[i] < '0' || mas[i] > '9'))
			mas[i] -= 32;
		numb /= base;
		i++;
	}
	numb = (numb > 9) ? numb + 87 : numb + 48;
	numb = (conv == 'X' && (numb < '0' || numb > '9') ? numb - 32 : numb);
	write(1, &numb, 1);
	while (i)
		write(1, &mas[i-- - 1], 1);
}

static char		*ft_special_form(t_options *modify, int base,
		unsigned long long numb, int precision)
{
	char	*tmp;

	tmp = 0;
	if (modify->conv == 'p')
		tmp = "0x";
	else if ((modify->conv == 'o' || modify->conv == 'O') &&
			modify->flags[0] == '1' && !numb && !precision)
		tmp = "0";
	else if (modify->flags[0] == '1' && !(base % 8) && numb)
	{
		if (modify->conv == 'x')
			tmp = "0x";
		else if (modify->conv == 'X')
			tmp = "0X";
		else
			tmp = "0";
	}
	tmp = (!(tmp)) ? "" : tmp;
	return (tmp);
}

static int		ft_output_unsigned_fase_2(t_options *modify,
		int base, unsigned long long numb)
{
	char	*sign;
	int		len_numb;
	int		len_conv;
	int		ans;

	sign = ft_special_form(modify, base, numb, modify->precision);
	len_numb = ft_numlen(numb, base, modify->precision);
	(ft_strlen(sign) == 1) ? modify->precision-- : modify->precision;
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
		ft_print_num(numb, base, modify->conv);
	while (modify->flags[4] == '1' && modify->min_width-- - len_conv > 0)
		write(1, " ", 1);
	return (ans);
}

void			ft_output_unsigned(va_list ap, t_options *modify, int *ans)
{
	unsigned long long	numb;
	int					base;

	base = 16;
	if (ft_strchr("uU", modify->conv))
		base = 10;
	else if (ft_strchr("oO", modify->conv))
		base = 8;
	if (ft_strstr(modify->modificator, "ll") || modify->conv == 'p' ||
	ft_strchr(modify->modificator, 'z') || ft_strchr(modify->modificator, 'j'))
		numb = va_arg(ap, unsigned long long);
	else if (ft_strstr(modify->modificator, "l") || modify->conv == 'O' ||
			modify->conv == 'U')
		numb = va_arg(ap, unsigned long);
	else if (ft_strstr(modify->modificator, "hh"))
		numb = (unsigned char)va_arg(ap, int);
	else if (ft_strstr(modify->modificator, "h"))
		numb = (unsigned short)va_arg(ap, int);
	else
		numb = va_arg(ap, unsigned int);
	*ans += ft_output_unsigned_fase_2(modify, base, numb);
}
