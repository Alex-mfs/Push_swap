#CORES
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#COMMANDS
RM = rm -rf
AR = ar -rcs
CC = cc

#FLAGS
CFLAGS	= -Wall -Wextra -Werror -g
LFLAGS	= -L ./libft -lft

#PATHS
DEPS			= include
HEADERS			= include/push_swap.h include/libft.h
SRCS			= srcs/push_swap
SRCS_BONUS		= srcs/checker
LIBFT_PATH		= libft
OBJ_PATH		= objs
OBJ_PATH_BONUS	= objs_checker

#FILES
NAME			= push_swap
SRC_FILES		= utils validate error swap rotate reverse_rotate push sorting stack_aux sorting_aux calculate_cost algorithm
OBJS			= $(SRC_FILES:%=%.o)
TARGET			= $(addprefix $(OBJ_PATH)/, $(OBJS))

#RULES 
all: $(NAME)

$(NAME): $(OBJ_PATH) $(TARGET) $(HEADERS) srcs/push_swap/main.c
	echo "$(MAGENTA)Compiling:$(RESET) $(GREEN)libft/*$(RESET)"
	make -C $(LIBFT_PATH)
	echo "$(CYAN)🔗 Linking: $(RESET) $(CFLAGS) $(GREEN)*$(NAME)$(RESET)"
	$(CC) $(CFLAGS) $(TARGET) srcs/push_swap/main.c $(LFLAGS) -o $(NAME) -I$(DEPS)
	@echo "$(GREEN)🎉 YAY! Compilation is done!$(RESET)"
	
$(OBJ_PATH)/%.o : $(SRCS)/%.c 
	@echo "$(MAGENTA)Compiling:$(RESET) $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

$(OBJ_PATH) :
	mkdir -p $(OBJ_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	echo "$(RED)🗑️  Deleted: $(RESET) $(GREEN)$(OBJ_PATH)$(RESET)"
	$(RM) $(OBJ_PATH)
	echo "$(RED)🗑️  Deleted: $(RESET) $(GREEN)$(OBJ_PATH_BONUS)$(RESET)"
	$(RM) $(OBJ_PATH_BONUS)

fclean: clean
	make fclean -C $(LIBFT_PATH)	
	echo "$(RED)🗑️  Deleted: $(RESET) $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)
	echo "$(RED)🗑️  Deleted: $(RESET) $(GREEN)$(NAME_BONUS)$(RESET)"
	$(RM) $(NAME_BONUS)

re: fclean all

rebonus: fclean bonus
