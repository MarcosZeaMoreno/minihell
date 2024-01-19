# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 15:13:18 by vkatason          #+#    #+#              #
#    Updated: 2024/01/19 19:30:01 by vkatason         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell.a
USER := $(shell whoami)
APPNAME = minishell
CC = gcc -g
CLEAN = rm -Rf
CFLAGS = -fsanitize=address -Wall -Werror -Wextra
LDFLAGS = -L/Users/$(USER)/.brew/opt/readline/lib -lreadline
LIBFT = libft
SRC =  check_comand.c main.c print_entry.c signals.c \
		env_to_lst.c error.c ./builtin/builtins.c \
		./builtin/echo.c env_fts.c parse.c tokens.c \
		utils.c input_clean.c print_checks.c \

OBJS := $(SRC:.c=.o)

all: libftmake $(APPNAME)

$(APPNAME): $(NAME)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(NAME) $(LIBFT)/libft.a -o $(APPNAME)
	@echo "$(GREEN)The app $(APPNAME) was successfully compiled. $(DEFAULT)"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
	@echo "$(GREEN)Compiling:$(DEFAULT) $(notdir $<)"
	
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Library $(NAME) was successfully created.$(DEFAULT)"

clean: libftclean
	@$(CLEAN) ./$(OBJS)
	@echo "$(RED)Removing:$(DEFAULT) all objects of $(APPNAME)."

fclean: libftfclean
	@$(CLEAN) ./$(OBJS)
	@echo "$(RED)Removing:$(DEFAULT) all objects of $(APPNAME)."
	@$(CLEAN) ./$(NAME) ./$(APPNAME)
	@echo "$(RED)Removing:$(DEFAULT) $(NAME) library."
	@echo "$(RED)Removing:$(DEFAULT) $(APPNAME) program."

re: fclean all

norma: libftnorma
	@norminette $(SRC) philo.h
libftnorma:
	@make norma -C $(LIBFT)
norma_color: libftnorma_color
	@norminette $(SRC) philo.h 2>&1 | sed -e "s/Warning/\x1b[1;33m&\x1b[0m/" -e "s/Error/\x1b[1;31m&\x1b[0m/" -e "s/OK/\x1b[1;32m&\x1b[0m/"
libftnorma_color:
	@make norma_color -C $(LIBFT)
libftmake:
	@make -C $(LIBFT)
libftclean:
	@make clean -C $(LIBFT)
libftfclean:
	@make fclean -C $(LIBFT)
libftre: libftclean libftmake

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
DEFAULT	:= \033[0m

.PHONY : all clean fclean re \
libftmake libftclean libftfclean libftre