/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:39:42 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/02/28 20:51:00 by vkatason         ###   ########.fr       */
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
# define INPUT_QUOTES_ERROR 11
# define SYNTAX_ERROR 12

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
 * @brief Struct to handle the redirections
 * @param file The file to redirect
 * @param redir_type The type of redirection:
 * ">>" to append,
 * ">" to overwrite,
 * "<" to read from file
 * "<<" to read from a heredoc
 * @param next The next redirection 
 */
typedef struct s_redir
{
	char			*file;
	char			*redir_type;
	struct s_redir	*next;
}					t_redir;

/**
 * @brief Struct to handle the commands
 * @param argv The comand itself and its arguments
 * @param is_redir A flag to indicate if the command has redirections
 * @param fd_in The file descriptor to read from
 * @param fd_out The file descriptor to write to
 * @param redir The redirections list (if the command has redirections)
 * @param next The next command
 */
typedef struct s_cmd
{
	char			**argv;
	int				is_redir;
	int				fd_in;
	int				fd_out;
	struct s_redir	*redir;
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
	t_env			*env_copy;
	char			*input_copy;
	t_cmd			*cmd;
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

/*----- LEXER & INPUT CHECK ----*/

int					ft_is_input_error(char *usr_input);

/*----- VARIABLE SEARCH AND EXPANSION ----*/
t_list				*ft_var_name(char *usr_input);
t_var_name			*ft_create_var(char *usr_input, int *i);
// int				ft_check_vars(char *usr_input, t_data *data);
// void				print_var_names(char *usr_input);
// void				print_var_check_vars(char *usr_input, t_data *data);
void				ft_free_var_list(t_list *vars);
void				ft_print_vars(t_list *vars);

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
