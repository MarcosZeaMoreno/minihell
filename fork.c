/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:23:25 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/19 18:49:12 by mzea-mor         ###   ########.fr       */
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
	char	**env_tab;
	env_tab = env;
	father = fork();
	if (father > 0)
		wait(&status);
	else if (father == 0)
		execve(full_path, cmds, env_tab);
}

/**
 * @brief Function to execute a command by path.
 * 
 * @param cmds: a double char pointer that contain the string of readline.
 * @param env: a double char pointer that contain the enviromental variables.
 */
void	exec_local(char **cmds, char **env)
{
	char	*command;

	if (ft_strncmp(*cmds, "/bin/", 5))
		command = ft_strjoin("/bin/", *cmds);
	else
		command = ft_strdup(*cmds);
	if (access(command, F_OK) == 0)
	{
		if (access(command, X_OK) == 0)
			forkit(command, cmds, env);
		else
			ft_printf("%s: Permission denied.\n", *cmds);
	}
	else
		ft_printf("%s: Command not found.\n", *cmds);
}
