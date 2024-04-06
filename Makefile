# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

#Include directory
INC = -Iinc

# Project files
SRC_PATH = ./src/push_swap/
SRCS = $(SRC_PATH)main.c $(SRC_PATH)utils.c $(SRC_PATH)utils2.c $(SRC_PATH)validate.c $(SRC_PATH)error.c $(SRC_PATH)swap.c $(SRC_PATH)rotate.c $(SRC_PATH)reverse_rotate.c $(SRC_PATH)push.c $(SRC_PATH)sorting.c $(SRC_PATH)stack_aux.c $(SRC_PATH)sorting_aux.c $(SRC_PATH)calculate_cost.c $(SRC_PATH)algorithm.c
OBJS = $(SRCS:.c=.o)
DEPS = inc/push_swap.h
NAME = push_swap

# Compile and create the executable
all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS)

# Generic rule for object files
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Clean objects
clean:
	rm -f $(OBJS)

# Full clean (objects + executable)
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re
