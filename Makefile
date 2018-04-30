# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokartou <yokartou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/12 21:43:25 by yokartou          #+#    #+#              #
#    Updated: 2018/04/28 12:44:56 by yokartou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Wolf3d

CC = clang

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC_DIR = srcs

INC_DIR = incs

OBJ_DIR = objs

LIBS = -L minilibx \
	   -I libft \
	   -L./libft/ -lft

SRC = map.c \
	coord.c \
	draw.c \
	hook.c \
	keyboard.c \
	main.c \
	player.c \
	raycast.c \
	raydraw.c \
	read.c \
	setup_mlx.c \
	texture.c

OBJ = $(SRC:%.c=objs/%.o)

all : objs $(NAME)

objs :
	@mkdir objs

$(NAME): $(OBJ)
	@make -C libft/
	@make -C minilibx
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I $(INC_DIR) $(MLXFLAGS) $(LIBS)
	@echo "Wolf3d Done"

objs/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	@make -C libft/ clean
	@make -C minilibx/ clean
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
