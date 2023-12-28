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

CC = @gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
		ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_split.c ft_itoa.c ft_memcpy.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c 

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling:$(RST) $(notdir $<)"

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
#	@echo "📒$(YELLOW) Libft library had been successfully compiled! $(RST)📒"
clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
#	@echo "📒$(RED) Libft object files had been successfully removed! $(RST)📒"

fclean: clean
	@rm -f libft.a
	@echo "📒$(RED) Libft had been successfully cleaned! $(RST)📒"
re: fclean all

bonus: $(NAME) $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJ_BONUS)

.PHONY: all clean fclean re

