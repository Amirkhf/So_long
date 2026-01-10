
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./minilibx-linux
MLX_PATH = ./minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11

SRCS = srcs/main.c \
       srcs/move/utils.c \
       srcs/move/move_player.c \
       srcs/move/move_player_utils.c \
       srcs/parsing/read_map.c \
       srcs/move/move_ennemy_utils.c \
       srcs/move/move_ennemy.c \
       srcs/move/count_move.c \
       srcs/draw/draw_map.c \
       srcs/draw/draw_wall_v1.c \
       srcs/draw/draw_all.c \
       srcs/draw/draw_wall.c \
       srcs/parsing/all_check.c \
       srcs/parsing/all_check_v2.c \
       srcs/parsing/all_check_utils.c \
       srcs/parsing/algo.c \
       srcs/utils/utils.c \
       includes/struct.c \
       includes/struct_v2.c \
       libft/ft_itoa.c \
       libft/ft_split.c \
       libft/ft_strjoin.c \
       libft/ft_strlen.c \
       libft/ft_putstr.c \
       srcs/game_over/game_over.c\
       srcs/game_over/win.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS) mlx
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(MLX_FLAGS) -o $(NAME)

mlx:
	if [ ! -f $(MLX_PATH)/libmlx.a ]; then cd $(MLX_PATH) && make -j4; fi

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

