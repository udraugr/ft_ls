/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:08:35 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/27 19:24:47 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_print_c(int c, int memory)
{
	unsigned char	tmp[4];
	int				i;

	i = 0;
	if (memory == 1)
		write(1, &c, 1);
	else
	{
		while (i < memory - 1)
		{
			tmp[i] = 128 + c % 64;
			c /= 64;
			i++;
		}
		tmp[i] = c + 192;
		if (memory >= 3)
			tmp[i] += 32;
		if (memory == 4)
			tmp[i] += 16;
		while (i > -1)
			write(1, &tmp[i--], 1);
	}
}

static int	ft_output_character(t_options *modify, int c)
{
	int		ans;
	int		memory;
	char	content;

	memory = ft_sizeof_char(c);
	ans = (modify->conv != 127) ? memory : 0;
	content = (modify->flags[1] == '1') ? '0' : ' ';
	ans = (modify->min_width > ans) ? modify->min_width : ans;
	while (modify->flags[4] == '0' && modify->min_width-- > memory)
		write(1, &content, 1);
	if (modify->conv != 127)
		ft_print_c(c, memory);
	while (modify->flags[4] == '1' && modify->min_width-- > memory)
		write(1, &content, 1);
	return (ans);
}

static int	ft_output_string(t_options *modify, char *str)
{
	int		max;
	int		ans;
	char	content;

	if (!str)
		str = "(null)";
	max = (ft_strlen(str) > (size_t)modify->precision &&
			modify->precision != -1) ? modify->precision : ft_strlen(str);
	content = (modify->flags[1] == '1') ? '0' : ' ';
	ans = (max > modify->min_width) ? max : modify->min_width;
	modify->min_width -= max;
	while (modify->flags[4] == '0' && modify->min_width-- > 0)
		write(1, &content, 1);
	while (max-- && *str)
		write(1, &*(str++), 1);
	while (modify->flags[4] == '1' && modify->min_width-- > 0)
		write(1, &content, 1);
	return (ans);
}

static int	ft_output_wstring(t_options *modify, wchar_t *str)
{
	int		max;
	int		ans;
	char	content;

	if (!str)
		return (ft_output_string(modify, "(null)"));
	max = ft_wstrlen(modify->precision, str);
	content = (modify->flags[1] == '1') ? '0' : ' ';
	ans = (max > modify->min_width) ? max : modify->min_width;
	modify->min_width -= max;
	while (modify->flags[4] == '0' && modify->min_width-- > 0)
		write(1, &content, 1);
	while (*str && (max -= ft_sizeof_char(*str)) >= 0)
	{
		ft_print_c(*str, ft_sizeof_char(*str));
		str++;
	}
	while (modify->flags[4] == '1' && modify->min_width-- > 0)
		write(1, &content, 1);
	return (ans);
}

void		ft_output_other(va_list ap, t_options *modify, int *ans)
{
	if (modify->conv == 'C' ||
			(modify->conv == 'c' && ft_strchr(modify->modificator, 'l')))
		*ans += ft_output_character(modify, va_arg(ap, int));
	else if (modify->conv == 'S' ||
		(modify->conv == 's' && ft_strchr(modify->modificator, 'l')))
		*ans += ft_output_wstring(modify, va_arg(ap, wchar_t *));
	else if (modify->conv == 'c')
		*ans += ft_output_character(modify, (char)va_arg(ap, int));
	else if (modify->conv == '%')
		*ans += ft_output_character(modify, '%');
	else if (modify->conv == 's')
		*ans += ft_output_string(modify, va_arg(ap, char *));
	else
		*ans += ft_output_character(modify, modify->conv);
}
