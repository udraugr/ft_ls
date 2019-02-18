/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_fraction_g.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:14:24 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/29 16:37:23 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_output_fraction_g(va_list ap, t_options *modify, int *ans)
{
	long double tmp;
	long double tmp2;
	int			pow;

	(!modify->precision) ? ++modify->precision : modify->precision;
	modify->precision = (modify->precision == -1) ? 5 : modify->precision - 1;
	if (ft_strchr(modify->modificator, 'L'))
		tmp = va_arg(ap, long double);
	else
		tmp = va_arg(ap, double);
	tmp2 = (tmp < 0) ? tmp * -1.0L : tmp;
	pow = 1;
	while (tmp2 >= 10.0L && pow++)
		tmp2 /= 10.0L;
	if ((tmp < 0.0001L && tmp > 0.0L) ||
			(tmp > -0.0001L && tmp < 0.0L) || pow > modify->precision)
		*ans += ft_output_e(modify, tmp);
	else
		*ans += ft_output_f(modify, tmp);
}
