COLOUR_PURPLE=\033[0;33m
END_COLOUR=\033[0m

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c printf_utils.c printf_unsigned.c \
		printf_hex.c printf_ptr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "📒$(COLOUR_PURPLE) ¡Compiling libft library! $(END_COLOUR)📒"
	$(MAKE) -C libft/ all
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	$(MAKE) clean -C libft/
	rm -f $(OBJ)
	rm -f libftprintf.a

fclean: clean
	$(MAKE) fclean -C libft/
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re