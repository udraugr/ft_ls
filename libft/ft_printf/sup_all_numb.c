/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_all_numb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 12:02:25 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/29 12:02:55 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_sign_num(long double numb, char *flags)
{
	char	*sign;

	sign = "";
	if (numb < 0)
		sign = "-";
	else if (flags[3] == '1')
		sign = "+";
	else if (flags[2] == '1')
		sign = " ";
	return (sign);
}
