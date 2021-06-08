# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 09:54:48 by yoinoue           #+#    #+#              #
#    Updated: 2020/04/09 19:57:06 by yoinoue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM = eval_expr
SRCS = $(wildcard *.c)
INCS = $(wildcard *.h)
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(PROGRAM)
$(PROGRAM): $(OBJS)
		$(CC) -o $@ $^
.c.o:
		$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)
clean:
		rm -f $(OBJS)
fclean: clean
		rm -f $(PROGRAM)
re: fclean all
.PHONY: all clean fclean re .c.o
