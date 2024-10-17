# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 16:13:02 by ycantin           #+#    #+#              #
#    Updated: 2024/06/23 11:20:16 by ycantin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
NAME = fil-de-fer
CC = cc
FLAGS = -Wall -Wextra -Werror -g
DEPS = -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm
RM = rm -f

SRC = src/extras/helpers.c \
	  src/extras/get_next_line.c \
	  src/read_map.c \
	  src/main.c \
	  src/mlx_hooks.c \
	  src/draw_grid/dda.c \
	  src/draw_grid/bresenham.c \
	  src/draw_grid/grid.c \
	  src/controls/controls.c \
	  src/controls/controls2.c \
	  src/transform_coords.c \
	  src/isometric.c \
	  

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(SRC)
	@$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME) $(DEPS)

clean:
#	@$(RM) $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
