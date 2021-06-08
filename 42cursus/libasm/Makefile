NAME = test
ARCHIVE = libasm.a
SRCS = ft_write.s \
	   ft_strlen.s \
	   ft_strcmp.s \
	   ft_strcpy.s \
	   ft_strdup.s \
	   ft_read.s
OBJS = $(SRCS:.s=.o)
MAIN = main.c

all : $(NAME)

$(NAME) : $(ARCHIVE) $(MAIN)
	gcc -o $@ $(MAIN) -L . -lasm

$(ARCHIVE) : $(OBJS)
	ar rcs $@ $^

.s.o:
	nasm -Fdwarf -fmacho64 $<

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) $(ARCHIVE)

re : fclean all

.PHONY : all clean fclean re
