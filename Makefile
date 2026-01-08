# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 18:30:00 by amkhelif          #+#    #+#              #
#    Updated: 2026/01/08 15:14:38 by amkhelif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes
MLX_PATH = ./minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11

# Source files
SRCS = srcs/main.c \
       srcs/move/utils.c \
       srcs/move/move_player.c\
       srcs/parsing/read_map.c \
       srcs/draw/draw_map.c \
       srcs/draw/draw_wall_v1.c \
	   srcs/draw/draw_all.c \
       srcs/parsing/all_check.c \
       srcs/parsing/all_check_v2.c \
	   srcs/draw/draw_wall.c \
       srcs/parsing/algo.c \
       includes/struct.c \
       libft/ft_itoa.c \
       libft/ft_split.c \
       libft/ft_strjoin.c \
       libft/ft_strlen.c \
       libft/ft_nb_line.c

# Object files
OBJS = $(SRCS:.c=.o)

# Colors for output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
NC = \033[0m # No Color

# ============================================================================ #
# TARGETS                                                                    #
# ============================================================================ #

all: $(NAME)

$(NAME): $(OBJS) mlx
	@echo "$(BLUE)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully$(NC)"

mlx:
	@if [ ! -f $(MLX_PATH)/libmlx.a ]; then \
		echo "$(YELLOW)Building minilibx...$(NC)"; \
		cd $(MLX_PATH) && make -j4 > /dev/null 2>&1; \
	fi

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(NC)"
	@rm -f $(OBJS)
	@echo "$(GREEN)✓ Object files cleaned$(NC)"

fclean: clean
	@echo "$(YELLOW)Removing $(NAME)...$(NC)"
	@rm -f $(NAME)
	@echo "$(GREEN)✓ $(NAME) removed$(NC)"

re: fclean all
	@echo "$(GREEN)✓ Rebuild complete$(NC)"

test: $(NAME)
	@echo "$(BLUE)Testing with map.ber...$(NC)"
	@./$(NAME) map.ber

test_invalid: $(NAME)
	@echo "$(BLUE)Testing invalid maps...$(NC)"
	@echo "$(YELLOW)Test 1: No exit$(NC)"
	@./$(NAME) test_invalid1.ber 2>&1 | grep -v "^111" || true
	@echo "$(YELLOW)Test 2: No player$(NC)"
	@./$(NAME) test_invalid2.ber 2>&1 | grep -v "^111" || true
	@echo "$(YELLOW)Test 3: No collectible$(NC)"
	@./$(NAME) test_invalid3.ber 2>&1 | grep -v "^111" || true
	@echo "$(YELLOW)Test 4: Invalid character$(NC)"
	@./$(NAME) test_invalid4.ber 2>&1 | grep -v "^111" || true
	@echo "$(YELLOW)Test 5: Unclosed wall$(NC)"
	@./$(NAME) test_invalid5.ber 2>&1 | grep -v "^111" || true
	@echo "$(YELLOW)Test 6: Non-rectangular$(NC)"
	@./$(NAME) test_invalid6.ber 2>&1 | grep -v "^111" || true

.PHONY: all clean fclean re test test_invalid mlx
