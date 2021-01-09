NAME = ft_ls

SRC := difficult_print.c\
		error_handler.c\
		ft_transform.c\
		fts_vector.c\
		fts_vector2.c\
		help_diff_print.c\
		help_diff_print2.c\
		main.c\
		open_dir.c\
		parcing.c\
		print_out.c\
		prossesing.c\
		sort_folds_and_files.c

OBJ := $(patsubst %.c, %.o, $(SRC))

HDR = ./incl/

LIB = libft/libftprintf.a

SRC_LIB = 	libft/ft_atoi.c       libft/ft_lstnew.c     libft/ft_putstr_fd.c  libft/ft_strncmp.c\
			libft/ft_bzero.c      libft/ft_lstsplit.c   libft/ft_strcat.c     libft/ft_strncpy.c\
			libft/ft_copy_arr.c   libft/ft_memalloc.c   libft/ft_strchr.c     libft/ft_strnequ.c\
			libft/ft_isalnum.c    libft/ft_memccpy.c    libft/ft_strclr.c     libft/ft_strnew.c\
			libft/ft_isalpha.c    libft/ft_memchr.c     libft/ft_strcmp.c     libft/ft_strnstr.c\
			libft/ft_isascii.c    libft/ft_memcmp.c     libft/ft_strcpy.c     libft/ft_strrchr.c\
			libft/ft_isdigit.c    libft/ft_memcpy.c     libft/ft_strdel.c     libft/ft_strrev.c\
			libft/ft_isprint.c    libft/ft_memdel.c     libft/ft_strdup.c     libft/ft_strsplit.c\
			libft/ft_itoa.c       libft/ft_memmove.c    libft/ft_strequ.c     libft/ft_strstr.c\
			libft/ft_lstadd.c     libft/ft_memset.c     libft/ft_striter.c    libft/ft_strsub.c\
			libft/ft_lstdel.c     libft/ft_putchar.c    libft/ft_striteri.c   libft/ft_strtrim.c\
			libft/ft_lstdelone.c  libft/ft_putchar_fd.c libft/ft_strjoin.c    libft/ft_swap.c\
			libft/ft_lstfold.c    libft/ft_putendl.c    libft/ft_strlcat.c    libft/ft_swap_str.c\
			libft/ft_lstfree.c    libft/ft_putendl_fd.c libft/ft_strlen.c     libft/ft_tolower.c\
			libft/ft_lstiter.c    libft/ft_putnbr.c     libft/ft_strmap.c     libft/ft_toupper.c\
			libft/ft_lstlen.c     libft/ft_putnbr_fd.c  libft/ft_strmapi.c    libft/get_next_line.c\
			libft/ft_lstmap.c     libft/ft_putstr.c     libft/ft_strncat.c\
			ft_printf/ft_printf.c         ft_printf/output_n.c          ft_printf/parsing_ft_printf.c\
			ft_printf/output_fraction_e.c ft_printf/output_other.c      ft_printf/sup_all_numb.c\
			ft_printf/output_fraction_f.c ft_printf/output_signed.c     ft_printf/sup_fraction_efg.c\
			ft_printf/output_fraction_g.c ft_printf/output_unsigned.c   ft_printf/sup_other.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	clang -Wall -Wextra -Werror -I$(HDR) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
	clang -Wall -Wextra -Werror -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft fclean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Removed a \"ft_ls\" file!"

re: fclean all
