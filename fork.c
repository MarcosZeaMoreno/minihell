/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:23:25 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/03/25 18:48:15 by vkatason         ###   ########.fr       */
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
 * @brief Function to execute a command with absolute path.
 *
 * @param cmds: a double char pointer that contain the arguments.
 * @param env: a double char pointer that contain the enviromental variables.
 * @param data: a pointer to the data structure.
 */
void	exec_absolute_path(char **cmds, char **env, t_data *data)
{
	if (access(cmds[0], F_OK) == 0)
	{
		if (access(cmds[0], X_OK) == 0)
		{
			forkit(cmds[0], cmds, env);
			return ;
		}
		else
		{
			ft_printf_fd(2, "%s: Permission denied.\n", *cmds);
			data->exit_status = 1;
			return ;
		}
	}
	else
	{
		ft_printf_fd(2, "%s: No such file or directory\n", *cmds);
		data->exit_status = 1;
		return ;
	}
}

/**
 * @brief Function to execute a command handler.
 *
 * @param command: a pointer that contain the string of the command.
 * @param cmds: a double char pointer that contain the string of readline.
 * @param env: a double char pointer that contain the enviromental variables.
 * @return int: return 1 if the command is not found, 2 if the command is found.
 */
int	execute_command_handler(char *command, char **cmds, char **env)
{
	if (access(command, F_OK) == 0)
	{
		if (access(command, X_OK) == 0)
		{
			forkit(command, cmds, env);
			return (2);
		}
		else
		{
			ft_printf_fd(2, "%s: Permission denied.\n", *cmds);
			return (1);
		}
	}
	else
		return (1);
}

void	exec_command_in_path(char **cmds, char **env,
	t_env *enviroment, t_data *data)
{
	char	*command;
	char	**path;
	int		i;
	int		found = 0;

	i = 0;
	path = ft_split(get_env_value(enviroment, "PATH"), ':');
	while (path[i])
	{
		command = ft_strjoin(ft_strjoin(path[i], "/"), *cmds);
		if (execute_command_handler(command, cmds, env) == 2)
		{
			data->exit_status = 0;
			found = 1;
			break ;
		}
		i++;
	}
	if (!found)
	{
		data->exit_status = 1;
		ft_printf_fd(2, "%s: Command not found.\n", *cmds);
	}
}

/**
 * @brief Function to execute a command.
 *
 * @param cmds: a double char pointer that contain the arguments.
 * @param enviroment: a pointer to the enviromental variables.
 * @param data: a pointer to the data structure.
 */
void	exec_local(char **cmds, t_env *enviroment, t_data *data)
{
	char	**env;

	env = ft_env_to_char(enviroment);
	if (check_builtin(cmds))
		exec_builtin(data, cmds);
	else
	{
		if (cmds[0][0] == '/' || strncmp(cmds[0], "./", 2) == 0)
			exec_absolute_path(cmds, env, data);
		else
			exec_command_in_path(cmds, env, enviroment, data);
	}
}
