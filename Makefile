# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 16:13:01 by sehwang           #+#    #+#              #
#    Updated: 2021/04/26 15:58:02 by sehwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address

MLX = mlx

LXFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = cub3d.h

SRC =  main key_press

FIL = $(addsuffix .c, $(addprefix files/, $(SRC)))

OBJ = $(FIL:.c=.o)

$(NAME):$(OBJ)
	$(CC) -L $(MLX) $(CFLAGS) $(LXFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)
	./cub3D

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
