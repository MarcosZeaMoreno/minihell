/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:39:42 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/11 14:36:19 by vkatason         ###   ########.fr       */
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
 * @brief Structure to handle the data
 * 
 * @param env_copy Structure with a copy of enviroment variables
 * @param cwd Current working directory
 */
typedef struct s_data
{
	t_env			*env_copy;
	char			*cwd;
}					t_data;

/*-----  FUNCTIONS ----*/
void				handle_sigint(int sig);
void				print_entry(void);
void				print_exit(void);
void				print_header(void);
int					check_builtin(char *ptr);
void				ft_data_init(t_data *data);
int					check_execv(char *usr_input);
void				exec_builtin(t_data *data, char *usr_input);


/*-----  BUILTINS ----*/
void				ft_echo(t_data *data, char *usr_input);
void				ft_cd(t_data *data, char *usr_input);
void				ft_pwd(t_data *data);
void				ft_export(t_data *data, char *usr_input);
void				ft_unset(t_data *data, char *usr_input);
void				ft_env(t_env *env);

/*-----  ENVIRONMENT VARIABLES ----*/
t_env				*ft_env_lst_add_back(t_data *data, char *env);
void				ft_env_lst_last(t_data *data, t_env *env_lst);
t_env				*ft_env_lst_new(t_data *data, char *env);
t_data				*ft_get_env_cpy(t_data *data, char **env);
#endif
