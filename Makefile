# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epilar <epilar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/23 13:50:59 by epilar            #+#    #+#              #
#    Updated: 2021/03/04 14:44:26 by epilar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFT = libft/libft.a

MLX = libmlx.dylib

SRC = main.c\
		parser.c\
		parser_utils.c\
		get_params.c\
		check0.c\
		check1.c\
		check2.c\
		call_error.c\
		move_plr.c\
		draw_utils.c\
		draw_map.c\
		draw_walls.c\
		draw_sprites.c\
		init_utils.c\
		sprite_utils.c\
		get_txtrs_color.c\
		utils.c\
		image2bmp.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ = $(patsubst %.c, %.o, $(SRC))

D_FILES = $(patsubst %.c, %.d, $(SRC))

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -MMD

include $(wildcard $(D_FILES))

$(NAME) : $(OBJ)
	$(MAKE) -C ./mlx
	cp mlx/$(MLX) .
	$(MAKE) -C ./libft
	$(MAKE) bonus -C ./libft
	$(CC) $(FLAGS) $(LIBFT) $(OBJ) $(MLX) -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -o $(NAME)

clean :
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./mlx
	@rm -f $(OBJ) $(D_FILES)

fclean : clean
	$(MAKE) fclean -C ./libft
	@rm -f $(NAME) $(MLX)

re : fclean $(NAME)

dbg :
	$(CC) $(FLAGS) -g $(LIBFT) $(SRC) $(MLX)

.PHONY : all clean fclean re
