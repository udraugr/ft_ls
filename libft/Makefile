# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/17 17:34:34 by udraugr-          #+#    #+#              #
#    Updated: 2019/02/16 14:22:37 by udraugr-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_LIB := 	ft_atoi.c\
			ft_bzero.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_lstadd.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_lstfold.c\
			ft_lstfree.c\
			ft_lstiter.c\
			ft_lstlen.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_lstsplit.c\
			ft_memalloc.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strrev.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_swap.c\
			ft_tolower.c\
			ft_toupper.c\
			get_next_line.c\
			ft_copy_arr.c\
			ft_swap_str.c\

OBJ_LIB := $(patsubst %.c, %.o, $(notdir $(SRC_LIB)))

SRC_PRINTF := 	ft_printf.c\
				output_fraction_e.c\
				output_fraction_f.c\
				output_fraction_g.c\
				output_n.c\
				output_other.c\
				output_signed.c\
				output_unsigned.c\
				parsing_ft_printf.c\
				sup_all_numb.c\
				sup_fraction_efg.c\
				sup_other.c\

OBJ_PRINTF := $(patsubst %.c, %.o, $(notdir $(SRC_PRINTF)))

FLAGS := -Wall -Wextra -Werror

DIR_SRC := libft ft_printf

all: $(NAME)

$(NAME): $(OBJ_LIB) $(OBJ_PRINTF)
	@ar rcs  $(NAME) $(OBJ_LIB) $(OBJ_PRINTF)
	@echo "Create a library!"

VPATH := $(DIR_SRC)

%.o: %.c
	gcc $(FLAGS) -I ft_printf -c $< -o $@

clean:
	@/bin/rm -f $(OBJ_PRINTF) $(OBJ_LIB)
	@echo "Removed .o files!"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Removed a library!"

re: fclean all
