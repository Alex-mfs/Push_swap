CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

INC = -Iinc

SRC_PATH = ./src/push_swap/
SRCS = $(SRC_PATH)main.c $(SRC_PATH)utils.c $(SRC_PATH)utils2.c $(SRC_PATH)validate.c $(SRC_PATH)error.c $(SRC_PATH)swap.c $(SRC_PATH)rotate.c $(SRC_PATH)reverse_rotate.c $(SRC_PATH)push.c $(SRC_PATH)sorting.c $(SRC_PATH)stack_aux.c $(SRC_PATH)sorting_aux.c $(SRC_PATH)calculate_cost.c $(SRC_PATH)algorithm.c
OBJS = $(SRCS:.c=.o)
DEPS = inc/push_swap.h
NAME = push_swap
BONUS_PATH = ./src/checker/
BONUS_SRCS = $(BONUS_PATH)checker.c $(BONUS_PATH)get_stack_checker.c $(SRC_PATH)utils.c $(SRC_PATH)utils2.c $(SRC_PATH)validate.c $(SRC_PATH)error.c $(SRC_PATH)swap.c $(SRC_PATH)rotate.c $(SRC_PATH)reverse_rotate.c $(SRC_PATH)push.c $(SRC_PATH)sorting.c $(SRC_PATH)stack_aux.c $(SRC_PATH)sorting_aux.c $(SRC_PATH)calculate_cost.c $(SRC_PATH)algorithm.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS_NAME = checker

all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(INC) -o $(BONUS_NAME) $(BONUS_OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
