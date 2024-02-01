/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:23:25 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/02/01 16:01:38 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to fork and execute a command.
 * 
 * @param full_path: a pointer that contain the string of the full path.
 * @param cmds: a double char pointer that contain the string of readline.
 * @param env: a double char pointer that contain the enviromental variables.
 */
void	forkit(char *full_path, char **cmds, char **env)
{
	int		status;
	pid_t	father;

	father = fork();
	if (father < 0)
	{
		perror("fork");
        exit(EXIT_FAILURE);
	}
	else if (father > 0)
		wait(&status);
	else if (father == 0)
		execve(full_path, cmds, env);
}

/**
 * @brief Function to execute a command by path.
 * 
 * @param cmds: a double char pointer that contain the string of readline.
 * @param env: a double char pointer that contain the enviromental variables.
 */
void exec_absolute_path(char **cmds, char **env)
{
    if (access(cmds[0], F_OK) == 0)
    {
        if (access(cmds[0], X_OK) == 0)
        {
            forkit(cmds[0], cmds, env);
            return;
        }
        else
        {
            ft_printf_fd(2, "%s: Permission denied.\n", *cmds);
            return;
        }
    }
    else
    {
        ft_printf_fd(2, "%s: No such file or directory\n", *cmds);
        return;
    }
}

void exec_command_in_path(char **cmds, char **env, t_env *enviroment)
{
    char	*command;
    char 	**path;
    int     i = 0;

    path = ft_split(get_env_value(enviroment, "PATH"), ':');
    while (path[i])
    {
        command = ft_strjoin(ft_strjoin(path[i], "/"), *cmds);
        if (access(command, F_OK) == 0)
        {
            if (access(command, X_OK) == 0)
            {
                forkit(command, cmds, env);
                break;
            }
            else
            {
                ft_printf_fd(2, "%s: Permission denied.\n", *cmds);
                break;
            }
        }
        i++;
    }
    if (!path[i])
        ft_printf_fd(2, "%s: Command not found.\n", *cmds);
}

void exec_local(char **cmds, char **env, t_env *enviroment)
{
	if (cmds[0][0] == '/' || strncmp(cmds[0], "./", 2) == 0)
		exec_absolute_path(cmds, env);
	else
		exec_command_in_path(cmds, env, enviroment);
}
