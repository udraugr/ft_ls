/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:46:19 by udraugr-          #+#    #+#             */
/*   Updated: 2019/02/18 14:38:29 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "../libft/ft_printf/printf.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <sys/ioctl.h>

typedef struct			s_fl
{
	unsigned char		upper_r;
	unsigned char		r;
	unsigned char		l;
	unsigned char		a;
	unsigned char		t;
	unsigned char		one;
}						t_fl;

typedef struct			s_file
{
	char				*name;
	char				*full_name;
	int					type;
	struct stat			*all;
}						t_file;

typedef struct			s_vector
{
	void				*content;
	int					index;
	struct s_vector		*next;
	struct s_vector		*previous;
}						t_vector;

typedef struct			s_precision
{
	long long			numb_link;
	long long			len_uid;
	long long			len_grd;
	long long			size_file;
}						t_precision;

char					**ft_parcing(int argc, char **argv,
		t_fl **flags, int *number_of_file);

void					error_flags(char flag);
void					error_errno(char *name);

t_vector				*ft_create_vector(void *content);
t_vector				*ft_add_vector(t_vector *begin, void *content);
t_vector				*ft_take_vector(t_vector *begin, int index);
void					ft_del_vector(t_vector **begin);
void					ft_delall_vector(t_vector **chain);
void					ft_swap_vector(t_vector *v1, t_vector *v2);
int						ft_count_vector(t_vector *begin);

void					ft_transform(char **file_names, int numb_all_files,
		t_fl *flags, char *dir);

void					ft_prosessing(char **dir, t_fl *flags,
		int all, int lvl);
DIR						*open_dir(char **dir);

void					ft_sort_files(t_vector *files, t_fl *flags);
void					ft_sort_folds(t_vector *folders, t_fl *flags);

void					ft_clear_tfile(t_file *content);

void					ft_printf_out(t_vector *begin, t_fl *flags, int dir);
void					ft_difficult_print(t_vector *begin, int dir);

char					type_file(t_vector *begin);
t_precision				*make_precision(void);
void					take_time(char **tmp, char **time_or_year,
		t_vector *begin);
void					prove_on_device(t_vector *begin, t_precision *ans);

char					extend(char *filename);
void					print_size(t_vector *begin, t_precision *ans, char mod);
void					print_uid_grd(t_vector *begin, t_precision *ans);
void					print_soft_link(t_vector *begin);

#endif
