NAME		= libtests.a
STRLEN_DIR	= ./strlen_test
ATOI_DIR	= ./atoi_test
SRCS		= main.c \
			  $(STRLEN_DIR)/00_launcher.c \
			  $(STRLEN_DIR)/01_basic_test.c \
			  $(STRLEN_DIR)/02_null_test.c \
			  $(STRLEN_DIR)/03_long_string_test.c \
			  $(STRLEN_DIR)/04_segv_test.c \
			  $(ATOI_DIR)/00_launcher.c \
			  $(ATOI_DIR)/01_basic_test.c \
			  $(ATOI_DIR)/02_null_test.c \
			  $(ATOI_DIR)/03_max_int_test.c \
			  $(ATOI_DIR)/04_min_int_test.c \
			  $(ATOI_DIR)/05_negative_test.c \
			  $(ATOI_DIR)/06_positive_test.c \
			  $(ATOI_DIR)/07_non_numeric_test.c \
			  $(ATOI_DIR)/08_double_plus_test.c \
			  $(ATOI_DIR)/09_double_minus_test.c \
			  $(ATOI_DIR)/10_character_test.c \
			  $(ATOI_DIR)/11_space_insertion_test.c
OBJS		= $(SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
