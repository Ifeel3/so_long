NAME	= so_long
CC		= gcc
#FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -I. -Imlx -Ilibft
NORMIN	= norminette
SRC		= src/main.c \
		src/checkfile.c \
		src/parser.c \
		src/checkmap.c \
		src/error.c
OBJ		= $(SRC:%.c=%.o)

.PHONY: all re clean fclean libft mlx norm

.o: .c
	$(CC) $(CFLAGS) -Imlx $< -o $@

all: mlx libft $(NAME)

$(NAME): $(OBJ) so_long.h
	$(CC) $(OBJ) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

mlx:
	make -C mlx/

libft:
	make -C libft/

clean:
	make -C mlx/ clean
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f mlx/libmlx.a
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all

norm:
	make -C libft/ norm
	$(NORMIN) -R CheckForbiddenSourceHeader $(SRC)
	$(NORMIN) so_long.h