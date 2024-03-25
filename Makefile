NAME = push_swap

PUSH_LIB = push_swap.a

CC = cc = -Wall -Wextra -Werror -g

INCLUDE = -I ./includes

SRC = 

OBJS = ${SRC:.C=.O}

all: $(NAME)

$(NAME): $(PUSH_LIB) $(OBJS)
	@$(CC) SRC/main.c $(INCLUDE) $(PUSH_LIB) -O $(NAME)

