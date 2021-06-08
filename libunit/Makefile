NAME		= libft_tests
LIBUNIT		= framework/libunit.a
LIBTESTS	= tests/libtests.a
LIBFT		= libft/libft.a
SRCS		= ./tests/main.c
OBJS		= $(SRCS:.c=.o)
CC			= gcc
CCFLAGS		= -Wall -Wextra -Werror
MFLAGS		= --no-print-directory -C

all: $(NAME)

$(NAME): $(OBJS) $(LIBUNIT) $(LIBTESTS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) -L./tests -ltests -L./framework -lunit -L./libft -lft

$(LIBUNIT): FORCE
	make $(MFLAGS) framework

$(LIBTESTS): FORCE
	make $(MFLAGS) tests

$(LIBFT): FORCE
	make $(MFLAGS) libft

test: all
	./$(NAME)

clean:
	make clean $(MFLAGS) framework
	make clean $(MFLAGS) tests
	make clean $(MFLAGS) libft

fclean: clean
	make fclean $(MFLAGS) framework
	make fclean $(MFLAGS) tests
	make fclean $(MFLAGS) libft
	rm -f $(NAME)

re: fclean all

FORCE:
.PHONY: all clean fclean re FORCE
