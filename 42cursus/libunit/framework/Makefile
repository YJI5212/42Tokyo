NAME	= libunit.a
SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
