NAME = libft.a

CC = gcc

SRC =	src/ft_printf/ft_printf.c \
		src/ft_printf/fill_address.c \
		src/ft_printf/parsing.c \
		src/ft_printf/fill_string.c \
		src/ft_printf/solver.c \
		src/ft_printf/solve.c \
		src/ft_printf/fill_integer.c \
		src/ft_printf/fill_integer_bis.c \
		src/ft_printf/fill_hexa.c \
		src/ft_printf/fill_octal.c \
		src/ft_printf/fill_unsigned_d.c \
		src/ft_printf/fill_float.c \
		src/ft_printf/fill_float_bis.c \
		src/ft_printf/ull_itoa.c \
		src/ft_printf/floats_math.c \
		src/ft_atoi.c \
		src/ft_itoa.c \
		src/ft_bzero.c \
		src/ft_isalnum.c \
		src/ft_isalpha.c \
		src/ft_isascii.c \
		src/ft_isdigit.c \
		src/ft_isprint.c \
		src/ft_memccpy.c \
		src/ft_memchr.c \
		src/ft_memcmp.c \
		src/ft_memcpy.c \
		src/ft_memmove.c \
		src/ft_memset.c \
		src/ft_strcat.c \
		src/ft_strcmp.c \
		src/ft_strcpy.c \
		src/ft_strchr.c \
		src/ft_strdup.c \
		src/ft_strlcat.c \
		src/ft_strncpy.c \
		src/ft_strlen.c \
		src/ft_strncat.c \
		src/ft_strncmp.c \
		src/ft_strnstr.c \
		src/ft_strrchr.c \
		src/ft_strstr.c \
		src/ft_tolower.c \
		src/ft_toupper.c \
		src/ft_memalloc.c \
		src/ft_memdel.c \
		src/ft_strnew.c \
		src/ft_strclr.c \
		src/ft_striter.c \
		src/ft_striteri.c \
		src/ft_strdel.c \
		src/ft_strmap.c \
		src/ft_strmapi.c \
		src/ft_strequ.c \
		src/ft_swap.c \
		src/ft_strnequ.c \
		src/ft_strsub.c \
		src/ft_strjoin.c \
		src/ft_strtrim.c \
		src/ft_strsplit.c \
		src/ft_count_words.c \
		src/ft_putstr.c \
		src/ft_putestr.c \
		src/ft_putendl.c \
		src/ft_putchar_fd.c \
		src/ft_putstr_fd.c \
		src/ft_putnbr_fd.c \
		src/ft_putendl_fd.c \
		src/ft_putnbr.c \
		src/ft_putchar.c \
		src/ft_lstdelone.c \
		src/ft_lstdel.c \
		src/ft_lstnew.c \
		src/ft_lstiter.c \
		src/ft_lstmap.c \
		src/ft_strrev.c \
		src/ft_lstadd.c \
		src/ft_strcharlen.c \
		src/get_next_line.c \
		src/ft_strfjoin.c \
		src/ft_putlength.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I include/

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $@ $^
	@echo "\033[0;32m [OK] \033[0m		\033[0;36m libft.a created \033[0m       \033"

%.o : %.c
	@gcc $(CFLAGS) -o $@ -c $^
	@echo "\033[0;32m [OK] \033[0m		\033[0;33m Compiling libft.. \033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[0;32m [OK] \033[0m       	\033[0;35m OBJs deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;32m [OK] \033[0m       	\033[0;31m libft.a deleted\033[0m"

re: fclean all

.PHONY: clean fclean re all
