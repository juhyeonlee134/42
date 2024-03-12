CC=cc
CFLAG=-Wall -Wextra -Werror -Imlx -Iincludes -c
LFLAG=-Lmlx -lmlx -framework OpenGL -framework Appkit -Llibft -lft
NAME=so_long
SRCS=srcs/ft_printf.c \
	 srcs/util.c \
	 srcs/get_next_line.c \
	 srcs/get_next_line_utils.c \
	 srcs/utils_1.c \
	 srcs/utils_2.c \
	 srcs/parsing_1.c \
	 srcs/parsing_2.c \
	 srcs/parsing_3.c \
	 srcs/parsing_4.c \
	 srcs/parsing_5.c \
	 srcs/game_1.c \
	 srcs/game_2.c \
	 srcs/game_3.c \
	 srcs/main.c
OBJS=$(SRCS:.c=.o)
LIBFTDIR=libft
MLXDIR=mlx
LIBFT=$(LIBFTDIR)/libft.a
MLX=$(MLXDIR)/libmlx.dylib

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $^ $(LFLAG) -o $@

$(MLX):
	make -C $(MLXDIR)

$(LIBFT):
	make -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAG) $< -o $@

clean:
	make clean -C $(LIBFTDIR)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	make clean -C $(MLXDIR)
	rm -rf $(NAME)

re: fclean all
