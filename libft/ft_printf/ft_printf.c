/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:15:06 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/29 18:41:52 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_output(va_list ap, t_options *modify, int *ans)
{
	if (ft_strchr("ouxXpOU", modify->conv))
		ft_output_unsigned(ap, modify, ans);
	else if (ft_strchr("diD", modify->conv))
		ft_output_signed(ap, modify, ans);
	else if (ft_strchr("fF", (modify->conv)))
		ft_output_fraction_f(ap, modify, ans);
	else if (ft_strchr("gG", (modify->conv)))
		ft_output_fraction_g(ap, modify, ans);
	else if (ft_strchr("eE", (modify->conv)))
		ft_output_fraction_e(ap, modify, ans);
	else if (modify->conv == 'n')
		ft_output_n(ap, modify, ans);
	else
		ft_output_other(ap, modify, ans);
	free(modify->modificator);
	free(modify);
}

static int		ft_end_transform(char c)
{
	if (c == '#' || c == '0' || c == ' ' || c == '+' || c == '-' ||
		c == '*' ||
		c == 'l' || c == 'h' || c == 'z' || c == 'j' || c == 'L' ||
		c == '.' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

static char		*ft_transform(const char **format)
{
	char	*transform;
	int		len;

	len = 0;
	while (ft_end_transform((*format)[len]))
		len++;
	len++;
	if (!(transform = (char *)malloc(len + 1)))
		return (NULL);
	len = 0;
	while (ft_end_transform(**format))
		transform[len++] = *((*format)++);
	transform[len++] = **format;
	if (**format)
		(*format)++;
	transform[len] = '\0';
	return (transform);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ans;
	t_options	*modify;
	char		*modify_str;

	va_start(ap, format);
	ans = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write(1, &(*format), 1);
			ans++;
			format++;
		}
		else
		{
			format++;
			modify_str = ft_transform(&(format));
			modify = ft_parsing(modify_str, ap);
			ft_output(ap, modify, &ans);
		}
	}
	va_end(ap);
	return (ans);
}
