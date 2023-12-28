#COLORS
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RST		:= \033[0m 

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c printf_utils.c printf_unsigned.c \
		printf_hex.c printf_ptr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling:$(RST) $(notdir $<)"

$(NAME): $(OBJ)
	@echo "📒$(YELLOW) Compiling libft library! $(RST)📒"
	@$(MAKE) -C libft/ all
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
#	@echo "📘$(BLUE) Ft_printf library had been successfully compiled! $(RST)📘"

clean:
	@$(MAKE) clean -C libft/
	@rm -f $(OBJ)
	@rm -f libftprintf.a

fclean: clean
	@$(MAKE) fclean -C libft/
	@rm -f libft.a
	@echo "📘$(RED) Printf had been removed! $(RST)📘"

re: fclean all

.PHONY: all clean fclean re