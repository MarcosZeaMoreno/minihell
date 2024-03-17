/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:39:42 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/03/17 13:56:44 by vkatason         ###   ########.fr       */
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
# include <sys/types.h>
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

/**
 * @brief The following defines are used to identify the type of redirection
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
# define INPUT_QUOTES_ERROR 11
# define SYNTAX_ERROR 12

/**
 * @brief The following defines are used
 * to identify the type of exit status
 */

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define EXIT_NOT_FOUND 127
# define EXIT_SYNTAX_ERROR 258

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
 * @param TKN_PIPE Pipe symbol (|)
 * @param TKN_REDIR_IN Redirection input symbol (<)
 * @param TKN_REDIR_OUT Redirection output symbol (>)
 * @param TKN_REDIR_APPEND Redirection append symbol (>>)
 * @param TKN_REDIR_HERE_DOC Redirection here doc symbol (<<)
 * @param TKN_WORD Everything that is not a special character
 * @param TKN_STRING All that inside the quotes with quotes
 * @param TKN_ERROR 3 and more consecutive >, < and more than 2 |
 * @param value The value of the token
 * @param order The order of the token (e.g. 1, 2, 3, ...)
 */
typedef struct s_tkn
{
	enum
	{
		TKN_PIPE,
		TKN_REDIR_IN,
		TKN_REDIR_OUT,
		TKN_REDIR_APPEND,
		TKN_REDIR_HERE_DOC,
		TKN_WORD,
		TKN_STRING,
		TKN_ERROR
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
	unsigned char	c;
	unsigned int	i;
	char			*input;
}					t_lexer;

/**
 * @brief Structure to handle the token list
 *
 * @param tkn The token
 * @param next The next token
 */
typedef struct s_tkn_lst
{
	t_tkn				*tkn;
	struct s_tkn_lst	*next;
	struct s_tkn_lst	*prev;
}					t_tkn_lst;

/**
 * @brief Struct to handle the redirections
 * @param file The file to redirect
 * @param redir_type The type of redirection:
 * ">>" to append,
 * ">" to overwrite,
 * "<" to read from file
 * "<<" to read from a heredoc
 * @param next The next redirection 
 */
typedef struct s_redirect
{
	char				*file;
	char				*redir_type;
	struct s_redirect	*next;
}						t_redirect;

/**
 * @brief Structure to handle the commands
 * @param args The arguments of the command
 * where the very first argument is the command itself
 * and the rest are the arguments 
 * @param flag_redir The flag to check if 
 * the command has a redirection
 * @param fd The file descriptor for the pipe 
 * that will be used to pass the output of the
 * previous command to the input of the next command
 * @param redir The redirection
 * @param redir_count The redirection direction
 * where 0 is input and 1 is output
 * @param save The save dup. It duplicates stdin
 * and saves it's value.
 * @param next The next cmd structure
 */
typedef struct s_cmd
{
	char			**args;
	int				flag_redir;
	int				fd[2];
	t_redirect		*redir;
	int				redir_count[2];
	int				save;
	struct s_cmd	*next;
}					t_cmd;

/**
 * @brief Structure to handle the data
 *
 * @param env_copy The current copy of enviroment variables
 * @param input_copy The clean copy of the user input with
 * the enviroment variables expanded
 * @param cmd The list of parsed commands
 * @param token The token list
 * @param pid The process id
 */
typedef struct s_data
{
	int				exit_status;
	t_env			*env_copy;
	char			*input_copy;
	t_cmd			*cmd;
	t_tkn_lst		*tkns;
	t_token			*token;
	pid_t			pid;
}					t_data;

/**
 * @brief The structure to handle the variable names
 * during the input scanning
 * @param name The name of the variable
 * @param pos The position of the last character of the variable
 * name in the input
 * @param start The start position of the variable in the input
 * startin with $ from 0
 * @param end The end position of the variable in the input
 */
typedef struct s_var_name
{
	char			*name;
	char			*value;
	int				pos;
	int				start;
	int				end;
}					t_var_name;

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
void				print_env_vars(t_data *data);

/*-----  FUNCTIONS ----*/
// PORFAVOR, DEFINE UN PROPOSITO PARA ESTAS FUNCIONES

void				handle_sigint(int sig);
void				print_exit(void);
void				print_header(void);
int					check_builtin(t_token *token);
int					ft_init(t_data *data, int ac, char **av, char **env);
void				check_execve(t_data *data, char **env, t_env *enviroment);
void				exec_builtin(t_data *data, t_token *token);
char				*get_env_value(t_env *env, char *key);
void				free_split(char **split);
void				exec_local(char **cmds, char **env, t_env *enviroment);
void				forkit(char *full_path, char **cmds, char **env);
char				**strdup_2d(char **src);

/*----- INPUT CHECK ----*/

int					ft_is_input_error(char *usr_input, t_data *data);

/*----- VARIABLE SEARCH AND EXPANSION ----*/
t_list				*ft_var_name(char *usr_input);
t_var_name			*ft_create_var(char *usr_input, int *i);
char				*ft_check_vars(t_list *var_list, t_data *data);
t_list				*ft_fill_values(char *usr_input, t_data *data);
void				ft_free_var_list(t_list *vars);
void				ft_print_vars(t_list *vars);
void				ft_get_new_input(char *usr_input, t_data *data);

/*----- LEXER FUNCTIONS -----*/
t_lexer				*ft_init_lexer(char *input);
void				ft_lexer_advance(t_lexer *lexer);
t_tkn				*ft_lexer_advance_with_tkn(t_lexer *lexer, t_tkn *tkn);
char				*ft_lexer_char_to_str(t_lexer *lexer);
t_tkn				*ft_lexer_get_next_token(t_lexer *lexer);
t_tkn				*ft_lexer_get_string(t_lexer *lexer);
t_tkn				*ft_lexer_get_word(t_lexer *lexer);
t_tkn				*ft_init_tkn(int type, char *value);
int					ft_count_the_same(t_lexer *lexer, char symbol);
char				*ft_str_repeat(char c, int count);
int					ft_reset_tkn_order(int reset);
t_tkn_lst			*ft_add_tkn_to_lst(t_tkn_lst *head, t_tkn *tkn);
void				ft_tknize_input(t_data *data);
void				ft_free_tkn_lst(t_tkn_lst *head);
void				ft_print_tkn(t_tkn *tkn);
void				ft_print_tkn_lst(t_data *data);
t_tkn				*ft_handle_quotes(t_lexer *lexer);
t_tkn				*ft_handle_greater_than(t_lexer *lexer);
t_tkn				*ft_handle_less_than(t_lexer *lexer);
t_tkn				*ft_handle_pipe(t_lexer *lexer);
void				ft_handle_whitespace(t_lexer *lexer);

/*---- CMD MANAGEMENT FUNCTTIONS -----*/

void				ft_free_redir(t_redirect *redir);
void				ft_free_cmd(t_cmd *cmd);
t_cmd				*ft_init_cmd(void);
int					ft_tkn_lst_last(t_tkn_lst *tkn_lst);
void				ft_print_cmds(t_data *data);

/*----- LIST MANAGEMENT FUNCTIONS */

void				lst_delone_token(t_token *lst, void (*del)(void *));
void				lst_delone(t_env *lst, void (*del)(void *));
void				lst_clear_token(t_token **lst, void (*del)(void *));
void				lst_clear(t_env **lst, void (*del)(void *));

/*----- READLINE FUNCTIONS -----*/

void				rl_replace_line(const char *text, int clear_undo);

/*---- TERMIOS FUNCTIONS -----*/

void				suppress_output(void);

/*----- ERROR FUNCTIONS -----*/
void				ft_error(char *str, int type_error);



#endif
