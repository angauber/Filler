NAME = angauber.filler

SRC =	src/filler_start.c \
		src/algo.c \
		src/function_len.c \
		src/heatmap.c \
		src/place_piece.c

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(CFLAGS) libft/libft.a $(SRC) -o $(NAME)
	@echo "\033[0;32m [OK] \033[0m		\033[0;36m angauber.filler created \033[0m       \033"

clean:
	@echo "\033[0;32m [OK] \033[0m       	\033[0;35m deleting libft OBJ's\033[0m"
	@make clean -C libft/

fclean: clean
	@echo "\033[0;32m [OK] \033[0m       	\033[0;31m deleting libft.a\033[0m"
	@make fclean -C libft/
	@echo "\033[0;32m [OK] \033[0m       	\033[0;31m deleting angauber.filler\033[0m"
	@rm -rf angauber.filler

re: fclean all

.PHONY: clean fclean re all
