# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/19 19:23:28 by yoinoue           #+#    #+#              #
#    Updated: 2021/02/14 18:03:27 by yoinoue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRCS =	./srcs/cub3d.c \
		./srcs/error.c \
		./srcs/flood_fill.c \
		./srcs/flood_fill2.c \
		./srcs/get_next_line.c \
		./srcs/info_check.c \
		./srcs/info_check2.c \
		./srcs/info_fill_tex.c \
		./srcs/info.c \
		./srcs/utils.c \
		./srcs/bmp.c \
		./srcs/keydown.c \
		./srcs/fill_tex.c \
		./srcs/render_floor_and_ceiling.c \
		./srcs/render_wall1.c \
		./srcs/render_wall2.c \
		./srcs/render_sprite.c \
		./srcs/render_sprite2.c \
		./srcs/screen.c \
		./srcs/my_mlx.c \
		./libft/ft_atoi.c \
		./libft/ft_bzero.c \
		./libft/ft_calloc.c \
		./libft/ft_isdigit.c \
		./libft/ft_putchar_fd.c \
		./libft/ft_putstr_fd.c \
		./libft/ft_strchr.c \
		./libft/ft_strdup.c \
		./libft/ft_strjoin.c \
		./libft/ft_strlcat.c \
		./libft/ft_strlcpy.c \
		./libft/ft_strncmp.c \
		./libft/ft_substr.c \
		./libft/ft_memset.c \
		./libft/ft_memcpy.c \
		./libft/ft_strlen.c \
		./libft/ft_putnbr_fd.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O2

ifeq ($(shell uname),Linux)
LIBMLX_D = ./minilibx_linux
LIBMLX_FLAGS = -lXext -lX11 -lm
LIBMLX = libmlx_Linux.a
else
LIBMLX_D = ./minilibx_mms_20200219
LIBMLX_FLAGS = -framework OpenGL -framework Appkit -lz
LIBMLX = libmlx.dylib
endif

all : $(NAME)

$(NAME) : $(OBJS) $(LIBMLX)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBMLX_FLAGS)

$(LIBMLX) :
	make -C $(LIBMLX_D)
	cp ./$(LIBMLX_D)/$@ ./

clean :
	rm -rf $(OBJS)
	make -C $(LIBMLX_D) clean

fclean : clean
	rm -rf Saved.bmp
	rm -rf $(NAME) $(LIBMLX)

re : fclean all

run : re
	./$(NAME) ./tests/map.cub
	make clean

.PHONY : run all clean fclean re
