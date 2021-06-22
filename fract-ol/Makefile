NAME = fractol

SRCS =	srcs/main.c \
		srcs/init.c \
		srcs/fractol.c \
		srcs/my_mlx.c \
		srcs/mandelbrot.c \
		srcs/julia.c \
		srcs/color.c
OBJS = $(SRCS:.c=.o)

LIBFT_D = ./libft
LIBFT_FLAGS = -L. -lft
LIBFT = libft.a

ifeq ($(shell uname),Linux)
LIBMLX_D = ./minilibx_linux
LIBMLX_FLAGS = -lXext -lX11 -lm
LIBMLX = libmlx_linux.a
else
LIBMLX_D = ./minilibx_mms_20200219
LIBMLX_FLAGS = -framework OpenGL -framework Appkit -lz
LIBMLX = libmlx.dylib
endif

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS) $(LIBMLX) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBMLX_FLAGS) $(LIBFT_FLAGS)

$(LIBMLX) :
	make -C $(LIBMLX_D)
	cp ./$(LIBMLX_D)/$@ ./

$(LIBFT) :
	make -C $(LIBFT_D)
	cp ./$(LIBFT_D)/$@ ./

clean :
	rm -rf $(OBJS)
	make -C $(LIBMLX_D) clean
	make -C $(LIBFT_D) clean

fclean : clean
	rm -rf $(NAME) $(LIBMLX) $(LIBFT)
	make -C $(LIBFT_D) fclean

re : fclean all

.PHONY : run all clean fclean re
