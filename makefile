CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

# Directories
MLX_DIR = minilibx-linux
LIBFT_DIR = libft
SRCS_DIR = srcs
INC_DIR = includes

# MLX flags
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Sources
SRCS = $(SRCS_DIR)/main.c \
       $(SRCS_DIR)/parsing/algo.c \
       $(SRCS_DIR)/parsing/check_map.c \
       $(SRCS_DIR)/parsing/read_map.c \
       $(SRCS_DIR)/parsing/utils.c \
       $(INC_DIR)/struct.c

LIBFT_SRCS = $(LIBFT_DIR)/ft_split.c \
             $(LIBFT_DIR)/ft_strjoin.c \
             $(LIBFT_DIR)/ft_strlen.c

OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

# Includes
INCLUDES = -I$(INC_DIR) -I$(MLX_DIR)

NAME = so_long

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX_DIR)/libmlx.a $(OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(LIBFT_OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
