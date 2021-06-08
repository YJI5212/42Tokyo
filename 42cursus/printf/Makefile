# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 18:52:10 by yoinoue           #+#    #+#              #
#    Updated: 2020/08/24 01:59:50 by yoinoue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCDIR = ./srcs/
LIBDIR = ./lib/

SRCS = ./$(wildcard $(SRCDIR)*.c)\
	   ./$(wildcard $(LIBDIR)*.c)
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(NAME)

.PHONY : all clean fclean re bonus
