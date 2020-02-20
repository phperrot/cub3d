# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phperrot <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 15:54:20 by phperrot          #+#    #+#              #
#    Updated: 2020/02/20 09:06:24 by phperrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft minilibx

SRCS = ./srcs/mandatory/map.c \
	   ./srcs/mandatory/main.c \
	   ./srcs/mandatory/cub3d_utils.c \
	   ./srcs/mandatory/cub3d_utils2.c \
	   ./srcs/mandatory/cub3d_utils3.c \
	   ./srcs/mandatory/init.c \
	   ./srcs/mandatory/init2.c \
	   ./srcs/mandatory/parser.c \
	   ./srcs/mandatory/parser_tex.c \
	   ./srcs/mandatory/events.c \
	   ./srcs/mandatory/exit.c \
	   ./srcs/mandatory/move.c \
	   ./srcs/mandatory/display.c \
	   ./srcs/mandatory/display_items.c \
	   ./srcs/mandatory/ray.c \
	   ./srcs/mandatory/ray2.c \
	   ./srcs/mandatory/minimap.c \
	   ./srcs/mandatory/weapon.c \
	   ./srcs/mandatory/weapon2.c \
	   ./srcs/mandatory/save.c \
	   ./srcs/mandatory/save2.c \
	   ./srcs/mandatory/sprite.c \
	   ./srcs/mandatory/sprite2.c \
	   ./srcs/mandatory/sprite3.c \
	   ./srcs/mandatory/items.c \
	   ./srcs/mandatory/items2.c \
	   ./srcs/mandatory/free.c \
	   ./srcs/mandatory/error.c \
	   ./srcs/mandatory/error2.c \
	   ./srcs/mandatory/textures.c \
	   ./srcs/gnl/get_next_line.c \
	   ./srcs/gnl/get_next_line_utils.c \

SRCSBONUS = ./srcs/bonus/map_bonus.c ./srcs/bonus/main_bonus.c ./srcs/bonus/cub3d_utils_bonus.c ./srcs/bonus/cub3d_utils2_bonus.c ./srcs/bonus/cub3d_utils3_bonus.c ./srcs/bonus/init_bonus.c ./srcs/bonus/init2_bonus.c ./srcs/bonus/parser_bonus.c ./srcs/bonus/parser_tex_bonus.c ./srcs/bonus/events_bonus.c ./srcs/bonus/exit_bonus.c ./srcs/bonus/move_bonus.c ./srcs/bonus/display_bonus.c ./srcs/bonus/display_items_bonus.c ./srcs/bonus/ray_bonus.c ./srcs/bonus/ray2_bonus.c ./srcs/bonus/minimap_bonus.c ./srcs/bonus/weapon_bonus.c ./srcs/bonus/weapon2_bonus.c ./srcs/bonus/save_bonus.c ./srcs/bonus/save2_bonus.c ./srcs/bonus/sprite_bonus.c ./srcs/bonus/sprite2_bonus.c ./srcs/bonus/sprite3_bonus.c ./srcs/bonus/items_bonus.c ./srcs/bonus/items2_bonus.c ./srcs/bonus/free_bonus.c ./srcs/bonus/error_bonus.c ./srcs/bonus/error2_bonus.c ./srcs/bonus/textures_bonus.c  ./srcs/gnl/get_next_line.c ./srcs/gnl/get_next_line_utils.c

NAME = Cub3D
NAME_BONUS = Cub3D_bonus
GCC_FLAG = -Wall -Werror -Wextra -g
CC = gcc $(GCC_FLAG)

OBJS = $(SRCS:.c=.o)
BOBJS = $(SRCSBONUS:.c=.o)

all: libft minilibx $(NAME)

bonus: libft minilibx $(NAME_BONUS)

libft:
	make -C libft/

minilibx:
	make -C srcs/minilibx/


$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJS)
	$(CC) -o $@ $^ -Lsrcs/minilibx/ -lmlx -framework OPENGL -framework Appkit -Llibft -lft

$(NAME_BONUS):  $(BOBJS)
	$(CC) -o $@ $^ -Lsrcs/minilibx/ -lmlx -framework OPENGL -framework Appkit -Llibft -lft

clean:
	rm -f $(OBJS)
	rm -f $(BOBJS)
	make -Clibft/ clean
	make -C srcs/minilibx/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make -C libft/ fclean
	make -C srcs/minilibx/ clean

re: fclean all
