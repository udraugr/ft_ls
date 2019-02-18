/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_fraction_e.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 10:52:21 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/29 17:59:38 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			ft_fill(char **tmp, char exsp[6], int dot, int i)
{
	exsp[4] = '\0';
	exsp[5] = '\0';
	if (dot)
	{
		(**tmp)++;
		i = (exsp[1] == '-') ? i - 1 : i + 1;
	}
	exsp[3] = i % 10 + '0';
	i /= 10;
	exsp[2] = i % 10 + '0';
	if (i > 9)
	{
		exsp[4] = exsp[3];
		exsp[3] = exsp[2];
		exsp[2] = (i / 10) % 10 + '0';
	}
}

static char			*ft_exsponenta(long double numb, char conv,
		char exsp[6], int precision)
{
	int		i;
	int		dot;
	char	*tmp;

	exsp[0] = (conv == 'g' || conv == 'G') ? conv - 2 : conv;
	exsp[1] = '+';
	i = 0;
	while (numb >= 10.0L)
	{
		numb /= 10.0L;
		i++;
	}
	while (numb <= -10.0L || (numb > 0.00000000000L && numb < 1.0000000000L)
		|| (numb < 0.00000000000L && numb > -1.0000000000L))
	{
		exsp[1] = '-';
		numb *= 10.0L;
		i++;
	}
	dot = 0;
	tmp = ft_strnumb(numb, precision, &dot, conv);
	if ((conv != 'g' && conv != 'G') || i)
		ft_fill(&tmp, exsp, dot, i);
	exsp[0] = ((conv == 'g' || conv == 'G') && !i) ? '\0' : exsp[0];
	return (tmp);
}

int					ft_output_e(t_options *modify, long double numb)
{
	char	*sign;
	int		len_conv;
	int		ans;
	char	exsp[6];
	char	*numb_str;

	numb_str = ft_exsponenta(numb, modify->conv, exsp,
			modify->precision);
	sign = ft_sign_num(numb, modify->flags);
	len_conv = ft_strlen(numb_str);
	ans = len_conv + (int)(ft_strlen(sign) + ft_strlen(exsp));
	ans = (ans > modify->min_width) ? ans : modify->min_width;
	if (modify->flags[1] == '1')
		ft_putstr(sign);
	while (modify->flags[4] == '0' && modify->min_width-- - len_conv > 0)
		write(1, (modify->flags[1] == '1') ? "0" : " ", 1);
	if (modify->flags[1] == '0')
		ft_putstr(sign);
	ft_putstr(numb_str);
	ft_putstr(exsp);
	while (modify->flags[4] == '1' && modify->min_width-- - len_conv > 0)
		write(1, " ", 1);
	free(numb_str);
	return (ans);
}

void				ft_output_fraction_e(va_list ap, t_options *modify,
		int *ans)
{
	if (ft_strchr(modify->modificator, 'L'))
		*ans += ft_output_e(modify, va_arg(ap, long double));
	else
		*ans += ft_output_e(modify, va_arg(ap, double));
}
