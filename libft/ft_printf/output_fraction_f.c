/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_fraction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 05:21:49 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/29 16:25:11 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				ft_output_f(t_options *modify, long double numb)
{
	char	*sign;
	int		len_conv;
	int		ans;
	int		order;
	char	*numb_str;

	order = 0;
	sign = ft_sign_num(numb, modify->flags);
	numb_str = ft_strnumb(numb, modify->precision, &order, modify->conv);
	len_conv = ft_strlen(numb_str);
	ans = (len_conv + (int)ft_strlen(sign) + order > modify->min_width) ?
		len_conv + ft_strlen(sign) + order : modify->min_width;
	if (modify->flags[1] == '1')
		ft_putstr(sign);
	while (modify->flags[4] == '0' && modify->min_width-- - len_conv > 0)
		write(1, (modify->flags[1] == '1') ? "0" : " ", 1);
	if (modify->flags[1] == '0')
		ft_putstr(sign);
	if (order)
		write(1, "1", 1);
	ft_putstr(numb_str);
	while (modify->flags[4] == '1' && modify->min_width-- - len_conv > 0)
		write(1, " ", 1);
	free(numb_str);
	return (ans);
}

void			ft_output_fraction_f(va_list ap, t_options *modify, int *ans)
{
	if (ft_strchr(modify->modificator, 'L'))
		*ans += ft_output_f(modify, va_arg(ap, long double));
	else
		*ans += ft_output_f(modify, va_arg(ap, double));
}
