# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 15:37:18 by mzea-mor          #+#    #+#              #
#    Updated: 2023/12/28 22:06:59 by vkatason         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

OBJ = $(SRC:.c=.o)
NAME = minishell
USER := $(shell whoami)
CC = @gcc
CFLAGS = -fsanitize=address -Wall -Werror -Wextra
LDFLAGS = -L/Users/$(USER)/.brew/opt/readline/lib -lreadline
SRC = main.c signals.c print_entry.c check_comand.c

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling:$(RST) $(notdir $<)"

$(NAME): $(OBJ)
	@echo "📘$(BLUE) Compiling ft_printf library! $(RST)📘"
	@cd libs/ft_printf && make
	@$(CC) $(CFLAGS) $(LDFLAGS) $(SRC) libs/ft_printf/libftprintf.a -o minishell
	@echo "😈$(MAGENTA) MiniHell had been compiled successfully! $(RST)😈"


clean:
	@cd libs/ft_printf && make clean
	@rm -f *.o

fclean: clean
	@cd libs/ft_printf && make fclean
	@rm -f minishell
	@echo "👿$(RED) MiniHell files had been successfully removed! $(RST)👿"

re: fclean all

.PHONY: all clean fclean re