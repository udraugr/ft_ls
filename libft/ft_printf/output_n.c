/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 10:12:38 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/29 10:32:14 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_output_n(va_list ap, t_options *modify, int *ans)
{
	if (ft_strstr(modify->modificator, "ll") ||
			ft_strchr(modify->modificator, 'z') ||
			ft_strchr(modify->modificator, 'j'))
		*va_arg(ap, long long *) = *ans;
	else if (ft_strchr(modify->modificator, 'l'))
		*va_arg(ap, long int *) = *ans;
	else if (ft_strstr(modify->modificator, "hh"))
		*(char *)va_arg(ap, int *) = *ans;
	else if (ft_strchr(modify->modificator, 'h'))
		*(short *)va_arg(ap, int *) = *ans;
	else
		*va_arg(ap, int *) = *ans;
}
