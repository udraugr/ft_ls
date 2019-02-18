/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcinng_ft_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:05:48 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/26 04:55:55 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_options	*ft_create(void)
{
	t_options	*tmp;
	int			count;

	if (!(tmp = (t_options *)malloc(sizeof(t_options))))
		return (0);
	count = 0;
	while (count < 6)
	{
		tmp->flags[count] = (count != 5) ? '0' : '\0';
		count++;
	}
	tmp->min_width = 0;
	tmp->precision = -1;
	tmp->conv = 127;
	return (tmp);
}

static void			ft_parsing_1(char c, t_options *modify)
{
	char	*flags;

	flags = "#0 +-";
	if (c == flags[0])
		modify->flags[0] = '1';
	else if (c == flags[1] && modify->flags[4] == '0')
		modify->flags[1] = '1';
	else if (c == flags[2] && modify->flags[3] == '0')
		modify->flags[2] = '1';
	else if (c == flags[3])
	{
		modify->flags[3] = '1';
		modify->flags[2] = '0';
	}
	else if (c == flags[4])
	{
		modify->flags[4] = '1';
		modify->flags[1] = '0';
	}
}

static int			ft_parsing_2(char *str, t_options *modify, int i,
		va_list ap)
{
	int		j;

	j = i;
	if (str[j] == '*')
	{
		modify->min_width = va_arg(ap, int);
		if (modify->min_width < 0)
		{
			modify->min_width *= -1;
			modify->flags[4] = '1';
			modify->flags[1] = '0';
		}
		return (j + 1);
	}
	modify->min_width = ft_atoi(&str[j]);
	while (str[j] >= 48 && str[j] <= 57)
		j++;
	return (j);
}

static int			ft_parsing_3(char *str, t_options *modify, int i,
		va_list ap)
{
	int		j;

	j = i + 1;
	if ((str[j] > '9' || str[j] < '0') && str[j] != '*')
	{
		modify->precision = 0;
		return (j);
	}
	else if (str[j] == '*')
	{
		modify->precision = va_arg(ap, int);
		if (modify->precision < 0)
			modify->precision = (!modify->min_width) ? -1 : modify->min_width;
		return (j + 1);
	}
	modify->precision = ft_atoi(&str[j]);
	while (str[j] >= 48 && str[j] <= 57)
		j++;
	return (j);
}

t_options			*ft_parsing(char *str, va_list ap)
{
	t_options	*modify;
	char		c;
	int			i;

	modify = ft_create();
	modify->modificator = str;
	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c == '+' || c == '-' || c == '0' || c == ' ' || c == '#')
		{
			ft_parsing_1(c, modify);
			i++;
		}
		else if ((c >= '1' && c <= '9') || c == '*')
			i = ft_parsing_2(str, modify, i, ap);
		else if (c == '.')
			i = ft_parsing_3(str, modify, i, ap);
		else if (c == 'j' || c == 'z' || c == 'L' || c == 'h' || c == 'l')
			i++;
		else
			modify->conv = str[i++];
	}
	return (modify);
}
