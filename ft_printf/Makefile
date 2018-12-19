NAME = libftprintf.a

CC = gcc

SRC =	src/ft_printf.c \
		src/fill_address.c \
		src/parsing.c \
		src/fill_string.c \
		src/solver.c \
		src/solve.c \
		src/fill_integer.c \
		src/fill_integer_bis.c \
		src/fill_hexa.c \
		src/fill_octal.c \
		src/fill_unsigned_d.c \
		src/fill_float.c \
		src/fill_float_bis.c \
		src/ull_itoa.c \
		src/floats_math.c \
		libft/ft_atoi.c \
		libft/ft_itoa.c \
		libft/ft_bzero.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isprint.c \
		libft/ft_memccpy.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_strcat.c \
		libft/ft_strcmp.c \
		libft/ft_strcpy.c \
		libft/ft_strchr.c \
		libft/ft_strdup.c \
		libft/ft_strlcat.c \
		libft/ft_strncpy.c \
		libft/ft_strlen.c \
		libft/ft_strncat.c \
		libft/ft_strncmp.c \
		libft/ft_strnstr.c \
		libft/ft_strrchr.c \
		libft/ft_strstr.c \
		libft/ft_tolower.c \
		libft/ft_toupper.c \
		libft/ft_memalloc.c \
		libft/ft_memdel.c \
		libft/ft_strnew.c \
		libft/ft_strclr.c \
		libft/ft_striter.c \
		libft/ft_striteri.c \
		libft/ft_strdel.c \
		libft/ft_strmap.c \
		libft/ft_strmapi.c \
		libft/ft_strequ.c \
		libft/ft_swap.c \
		libft/ft_strnequ.c \
		libft/ft_strsub.c \
		libft/ft_strjoin.c \
		libft/ft_strtrim.c \
		libft/ft_strsplit.c \
		libft/ft_count_words.c \
		libft/ft_putstr.c \
		libft/ft_putestr.c \
		libft/ft_putendl.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr.c \
		libft/ft_putchar.c \
		libft/ft_lstdelone.c \
		libft/ft_lstdel.c \
		libft/ft_lstnew.c \
		libft/ft_lstiter.c \
		libft/ft_lstmap.c \
		libft/ft_strrev.c \
		libft/ft_lstadd.c \
		libft/ft_strcharlen.c \
		libft/get_next_line.c \
		libft/ft_strfjoin.c \
		libft/ft_putlength.c

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror -I include/

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $@ $^
	@echo "\033[0;32m [OK] \033[0m		\033[0;36m libftprintf.a created \033[0m       \033"

%.o : %.c
	@gcc $(CFLAGS) -o $@ -c $^
	@echo "\033[0;32m [OK] \033[0m		\033[0;33m Compiling.. \033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[0;32m [OK] \033[0m       	\033[0;35m OBJs deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;32m [OK] \033[0m       	\033[0;31m Libftprintf.a deleted\033[0m"

re: fclean all

.PHONY: clean fclean re all
