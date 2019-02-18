/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:08:41 by udraugr-          #+#    #+#             */
/*   Updated: 2019/01/29 11:45:27 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <wchar.h>

typedef struct		s_options
{
	char			flags[6];
	int				min_width;
	int				precision;
	char			*modificator;
	char			conv;
}					t_options;

t_options			*ft_parsing(char *str, va_list ap);
void				ft_output_unsigned(va_list ap, t_options *modify,
		int *ans);
void				ft_output_signed(va_list ap, t_options *modify,
		int *ans);
void				ft_output_fraction_f(va_list ap, t_options *modify,
		int *ans);
void				ft_output_fraction_e(va_list ap, t_options *modify,
		int *ans);
void				ft_output_fraction_g(va_list ap, t_options *modify,
		int *ans);
int					ft_output_e(t_options *modify, long double numb);
int					ft_output_f(t_options *modify, long double numb);
char				*ft_itoa_fract(long long nbr);
char				*ft_strnumb(long double numb, int precision,
		int *order, char conv);
char				*ft_sign_num(long double numb, char *flags);
char				*ft_okrug(char *str, int *order);
void				ft_output_other(va_list ap, t_options *modify,
		int *ans);
int					ft_sizeof_char(int c);
int					ft_wstrlen(int precision, wchar_t *str);
void				ft_output_n(va_list ap, t_options *modify,
		int *ans);
int					ft_printf(const char *format, ...);

#endif
