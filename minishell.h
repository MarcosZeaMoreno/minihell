/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:39:42 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/19 02:56:03 by vkatason         ###   ########.fr       */
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
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
# include <string.h>

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
# define CMND_NOT_VALID 6
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
 * @brief Structure to handle the data
 * 
 * @param env The enviroment variables
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
int					check_builtin(t_token *token, char **env);
int					ft_init(t_data *data, int ac, char **av, char **env);;
int					check_execv(t_token *token, char **env);
void				exec_builtin(t_data *data, t_token *token);
char				*get_env_value(t_env *env, char *key);
void				ft_error(char *str, int type_error);
void				free_split(char **split);

/*-----  UTILS ----*/
void				print_var_name(char *str);
void				print_var_list(char *input);
#endif
