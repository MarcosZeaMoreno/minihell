/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:39:42 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/30 03:14:21 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
// # include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

/*
** ASCII colors escape sequences for printf
** Usage:
** 		printf(RED "Red bold text" RST);
**		printf(B "Bold text goes here" RST);
*/
# define RST "\033[0m"        /* Reset to default color */
# define BU "\033[1;4;0m"     /* Bold and underlined text*/
# define B "\033[1m"          /* Bold text default color */
# define U "\033[4m"          /* Underlined text default color */
# define RED "\033[1;31m"     /* Bold Red*/
# define GREEN "\033[1;32m"   /* Bold Green */
# define YELLOW "\033[1;33m"  /* Bold Yellow */
# define BLUE "\033[1;34m"    /* Bold Blue */
# define MAGENTA "\033[1;35m" /* Bold Magenta */
# define CYAN "\033[1;36m"    /* Bold Cyan */
# define WHITE "\033[1;37m"   /* Bold White */

/*
 * The following defines are used to identify the type of error
 */
# define CMND_NOT_FOUND 1
# define CMND_NOT_EXEC 2
# define CMND_NOT_DIR 3
# define CMND_NOT_FILE 4
# define CMND_NOT_PERM 5
# define PERMISION_DENIED 6
# define CMND_NOT_MEM 7
# define CMND_NOT_ARG 8
# define CMND_NOT_PIPE 9
# define CMND_NOT_FORK 10

/*----- STRUCTURES -----*/

/**
 * @brief Structure to handle the enviroment variables
 *
 * @param key The key of the variable
 * @param value The value of the variable
 */
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

/**
 * @brief Structure to handle the tokens
 *
 * @param token The token
 * @param next The next token
 */
typedef struct s_token
{
	char			*value;
	struct s_token	*next;
}					t_token;

/**
 * @brief Structure representing a token in the minishell program.
 * 
 * @param e_type The type of the token
 * @param TKN_WHITESPACE All the whitespaces
 * @param TKN_SEMICOLON Semicolon symbol (;)
 * @param TKN_PIPE Pipe symbol (|)
 * @param TKN_DOUBLE_PIPE Double pipe symbol (||)
 * @param TKN_REDIR_IN Redirection input symbol (<)
 * @param TKN_REDIR_OUT Redirection output symbol (>)
 * @param TKN_REDIR_APPEND Redirection append symbol (>>)
 * @param TKN_REDIR_HERE_DOC Redirection here doc symbol (<<)
 * @param TKN_DOLLAR Dollar symbol ($)
 * @param TKN_AMPER Amper symbol (&)
 * @param TKN_DOUBLE_AMPER Double amper symbol (&&)
 * @param TKN_TILDE Tilde symbol (~)
 * @param TKN_SNGL_QUOTE Single quote symbol (')
 * @param TKN_STRING All that inside the quotes
 * @param TKN_WORD Everything that is not a special character
 * @param value The value of the token
 * @param order The order of the token (e.g. 1, 2, 3, ...)
 */
typedef struct s_tkn
{
	enum
	{
		TKN_WHITESPACE,
		TKN_SEMICOLON,
		TKN_PIPE,
		TKN_DOUBLE_PIPE,
		TKN_REDIR_IN,
		TKN_REDIR_OUT,
		TKN_REDIR_APPEND,
		TKN_REDIR_HERE_DOC,
		TKN_DOLLAR,
		TKN_AMPER,
		TKN_DOUBLE_AMPER,
		TKN_TILDE,
		TKN_SNGL_QUOTE,
		TKN_WORD,
		TKN_STRING
	} e_type;
	char			*value;
	int				order;
}					t_tkn;

/**
 * @brief Structure to handle the lexer
 *
 * @param c The current character
 * @param i The index of the current character
 * @param input The input string
 */
typedef struct s_lexer
{
	char			c;
	unsigned int	i;
	char			*input;
}					t_lexer;

/**
 * @brief Structure to handle the data
 *
 * @param env_copy The current copy of enviroment variables
 * @param token The token list
 * @param pid The process id
 */
typedef struct s_data
{
	t_env			*env_copy;
	t_token			*token;
	pid_t			pid;
}					t_data;

/*-----  BUILTINS ----*/

void				ft_echo(t_data *data, t_token *token);
void				ft_cd(t_data *data, t_token *token);
void				ft_pwd(t_data *data);
void				ft_export(t_data *data, t_token *token);
void				ft_unset(t_data *data, t_token *token);
void				ft_env(t_env *env);

/*-----  PARSING ----*/

void				ft_parse_input(t_data *data, char *usr_input);

/*-----  TOKENIZER ----*/

t_token				*ft_tokenizer(char *usr_input);
t_token				*ft_token_lst_new(char *value);
void				ft_token_lst_add_back(t_token *token, char *value);
t_token				*ft_token_lst_last(t_token *token);

/*-----  ENVIRONMENT VARIABLES ----*/

t_env				*ft_env_lst_add_back(t_data *data, char *env);
void				ft_env_lst_last(t_data *data, t_env *env_lst);
t_env				*ft_env_lst_new(t_data *data, char *env);
char				**lst_to_char(t_token *token);
t_data				*ft_get_env_cpy(t_data *data, char **env);
void				add_env_var(t_data *data, char *key, char *value);
void				remove_env_var(t_data *data, char *key);
void				change_value_env(t_data *data, char *key, char *value);

/*-----  FUNCTIONS ----*/

void				handle_sigint(int sig);
void				print_exit(void);
void				print_header(void);
int					check_builtin(t_token *token);
int					ft_init(t_data *data, int ac, char **av, char **env);
void				check_execve(t_data *data, char **env);
void				exec_builtin(t_data *data, t_token *token);
char				*get_env_value(t_env *env, char *key);
void				ft_error(char *str, int type_error);
void				free_split(char **split);
void				exec_local(char **cmds, char **env);
void				forkit(char *full_path, char **cmds, char **env);

/* FUNCTIONS */
void				lst_delone_token(t_token *lst, void (*del)(void *));
void				lst_delone(t_env *lst, void (*del)(void *));
void				lst_clear_token(t_token **lst, void (*del)(void *));
void				lst_clear(t_env **lst, void (*del)(void *));

/*-----  INPUT STRING CLEANING ----*/

void				print_var_name(char *str);
void				print_rm_quotes(char *usr_input);
void				print_var_check_vars(char *usr_input, t_data *data);
void				print_replaced_input(char *usr_input, t_data *data);
char				*ft_var_name(char *str);
void				ft_rm_quotes(char **str);
int					ft_num_chars_to_rm(char *str);
int					ft_check_vars(char *usr_input, t_data *data);
void				ft_replace_input(char **str, char *old_value,
						char *new_alue);
int					ft_clean_input(char **usr_input, t_data *data);

/*----- LEXER FUNCTIONS -----*/
t_lexer				*ft_init_lexer(char *input);
void				ft_lexer_advance(t_lexer *lexer);
void				ft_lexer_skip_whitespace(t_lexer *lexer);
t_tkn				*ft_lexer_get_next_token(t_lexer *lexer);
t_tkn				*ft_lexer_get_string(t_lexer *lexer);
t_tkn				*ft_lexer_get_word(t_lexer *lexer);
char				*ft_lexer_get_char(t_lexer *lexer);
t_tkn				*ft_lexer_advance_with_tkn(t_lexer *lexer, t_tkn *tkn);
void				print_tkn(t_tkn *tkn);

/*----- LEXER TOKENS -----*/
t_tkn				*ft_init_tkn(int type, char *value);
t_tkn				*ft_init_multi_tkn(int type, char *value);

#endif
