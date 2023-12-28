# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 15:37:18 by mzea-mor          #+#    #+#              #
#    Updated: 2023/12/28 18:37:23 by vkatason         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_BLUE=\033[0;34m
END_COLOUR=\033[0m

OBJ = $(SRC:.c=.o)
NAME = minishell
USER := $(shell whoami)
CC = gcc
CFLAGS = -fsanitize=address -Wall -Werror -Wextra
LDFLAGS = -L/Users/$USER/.brew/opt/readline/lib -lreadline
SRC = main.c signals.c print_entry.c check_comand.c

$(NAME): $(OBJ)
	@echo "📘$(COLOUR_BLUE) ¡Compiling ft_printf library! $(END_COLOUR)📘"
	@cd libs/ft_printf && make all
	@$(CC) $(CFLAGS) $(LDFLAGS) $(SRC) libs/ft_printf/libftprintf.a -o minishell
	@echo "🎉$(COLOUR_GREEN) Makefile had been executed successfully! $(END_COLOUR)🎉"

all: $(NAME)

clean:
	@cd libs/ft_printf && make clean
	@rm -f *.o
	@echo "🎉$(COLOUR_GREEN) Object files had been successfully removed! $(END_COLOUR)🎉"

fclean: clean
	@cd libs/ft_printf && make fclean
	@rm -f minishell
	@echo "🎉$(COLOUR_GREEN) Files had been successfully removed! $(END_COLOUR)🎉"

re: fclean all

.PHONY: all clean fclean re