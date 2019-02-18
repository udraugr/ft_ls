/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:57:29 by udraugr-          #+#    #+#             */
/*   Updated: 2019/02/17 13:35:29 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/ls.h"

static void		ft_initialization(t_fl *tmp)
{
	tmp->upper_r = 0;
	tmp->r = 0;
	tmp->l = 0;
	tmp->a = 0;
	tmp->t = 0;
	tmp->one = 0;
}

static void		parcing_flags(char *str, t_fl *tmp)
{
	while (*str)
	{
		if (*str == 'R')
			tmp->upper_r = '1';
		else if (*str == 'r')
			tmp->r = '1';
		else if (*str == 'l')
			tmp->l = '1';
		else if (*str == 'a')
			tmp->a = '1';
		else if (*str == 't')
			tmp->t = '1';
		else if (*str == '1')
			tmp->one = '1';
		else
			error_flags(*str);
		++str;
	}
}

static void		sort_params(char **argv)
{
	char				*temp;
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			++j;
		}
		++i;
	}
}

char			**ft_parcing(int argc, char **argv, t_fl **flags,
		int *number_of_files)
{
	t_fl				*tmp;
	unsigned short int	i;

	if (!flags || !number_of_files || !(tmp = (t_fl *)malloc(sizeof(t_fl))))
		return (0);
	ft_initialization(tmp);
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-' && ft_strlen(argv[i]) != 1)
		{
			if (argv[i][1] == '-' && ft_strlen(argv[i]) == 2)
			{
				++i;
				break ;
			}
			parcing_flags(++argv[i], tmp);
		}
		else
			break ;
	}
	*flags = tmp;
	*number_of_files = argc - i;
	sort_params(&argv[i]);
	return (ft_copy_arr(*number_of_files, &argv[i]));
}
