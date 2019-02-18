/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:39:30 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/05 14:35:55 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(int ans, int len)
{
	if (ans || len)
		return (1);
	return (0);
}

static int		ft_out(char **big, char **line, int ans)
{
	int			i;
	int			len;
	char		*tmp;
	char		*tmp1;

	if (!ans && !(*big))
		return (0);
	i = 0;
	while ((*big)[i] && (*big)[i] != '\n')
		i++;
	*line = ft_strsub(*big, 0, i);
	len = ft_strlen(*big);
	tmp1 = ft_strchr((*big), '\n');
	tmp = (tmp1) ? ft_strdup(tmp1 + 1) : tmp1;
	free(*big);
	*big = tmp;
	return (ft_check(ans, len));
}

int				get_next_line(const int fd, char **line)
{
	static char	*big[1024];
	char		str[BUFF_SIZE + 1];
	char		*tmp;
	int			ans;

	if (!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	while ((ans = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[ans] = '\0';
		if (!big[fd])
			if (!(big[fd] = ft_strnew(0)))
				return (-1);
		tmp = big[fd];
		big[fd] = ft_strjoin(big[fd], str);
		free(tmp);
		if (ft_strchr(str, '\n'))
			return (ft_out(&(big[fd]), line, ans));
	}
	if (ans == -1)
		return (-1);
	return (ft_out(&big[fd], line, ans));
}
