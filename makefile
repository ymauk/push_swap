NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRC = src/push_swap.c src/parsing.c src/help.c src/error_handling.c src/checking_string.c src/help_node.c src/operations.c src/operations2.c \
		src/operations3.c
OBJS = $(SRC:.c=.o)
LIBFT = lib/Libft
PRINTF = lib/printf

INLIBFT = -L $(LIBFT) -lft
INPRINTF = -L $(PRINTF) -lftprintf

B:= "\033[0;34m"
P:= "\033[0;35m"
R:= "\033[0;31m"
G:= "\033[0;32m"
Y:= "\033[0;33m"
DC:= "\033[0;39m"

$(NAME): $(OBJS)
	@echo $(B)"Compiling libft..."$(DC)
	@cd $(LIBFT) && $(MAKE) --silent
	@echo $(P)"Compiling printf...\n"$(DC)
	@cd $(PRINTF) && $(MAKE) --silent
	@echo $(G)"Compiling push_swap..."$(DC)
	@cc $(OBJS) $(INLIBFT) $(INPRINTF) -o $(NAME)

all: $(NAME)

%.o : %.c
	@cc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@cd $(LIBFT) && $(MAKE) clean --silent
	@cd $(PRINTF) && $(MAKE) clean --silent

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFT) && $(MAKE) fclean --silent
	@cd $(PRINTF) && $(MAKE) fclean --silent
	@echo $(Y)"\nEverything is properly cleaned!\n"$(DC)

re: fclean all

.PHONY: all clean fclean re


