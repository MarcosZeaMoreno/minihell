/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:46:14 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/03/26 21:14:19 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function used to detect if a command is a builtin.
 * 
 * @param cmds: a double char pointer that contain the string of readline.
 * @return int: return 1 if is a builtin, 0 if is not a builtin, -1 if fail.
 */
int	check_builtin(char **cmds)
{
	char	*value;

	if (!cmds)
		return (-1);
	value = cmds[0];
	if (!ft_strncmp("echo", value, 5))
		return (1);
	else if (!ft_strncmp("cd", value, 3))
		return (1);
	else if (!ft_strncmp("pwd", value, 4))
		return (1);
	else if (!ft_strncmp("export", value, 7))
		return (1);
	else if (!ft_strncmp("unset", value, 6))
		return (1);
	else if (!ft_strncmp("env", value, 4))
		return (1);
	else if (!ft_strncmp("exit", value, 5))
		return (1);
	else if (!ft_strncmp("", value, 1))
		return (1);
	else
		return (0);
}

int	check_builtin_rare(char **cmds)
{
	char	*value;

	if (!cmds)
		return (-1);
	value = cmds[0];
	if (!ft_strncmp("cd", value, 3))
		return (1);
	else if (!ft_strncmp("export", value, 7))
		return (1);
	else if (!ft_strncmp("unset", value, 6))
		return (1);
	else
		return (0);
}

/**
 * @brief Function used to execute a builtin.
 * 
 * @param data: a pointer that contain the main data structure.
 * @param cmds: a double char pointer that contain the string of readline.
 */
void	exec_builtin(t_data *data, char **cmds)
{
	char	*value;

	if (!data || !cmds)
		return ;
	value = cmds[0];
	if (!ft_strncmp("echo", value, 5))
		ft_echo(data, cmds);
	else if (!ft_strncmp("cd", value, 3))
		ft_cd(data, cmds);
	else if (!ft_strncmp("pwd", value, 4))
		ft_pwd(data);
	else if (!ft_strncmp("export", value, 7))
		ft_export(data, cmds);
	else if (!ft_strncmp("unset", value, 6))
		ft_unset(data, cmds);
	else if (!ft_strncmp("env", value, 4))
		ft_env(data->env_copy, 0);
	else if (!ft_strncmp("", value, 1))
		return ;
}

void	ft_do_builtin_rare(t_data *data, char **cmds)
{
	char	*value;

	if (!data || !cmds)
		return ;
	value = cmds[0];
	if (!ft_strncmp("cd", value, 3))
		ft_cd(data, cmds);
	else if (!ft_strncmp("export", value, 7))
		ft_export(data, cmds);
	else if (!ft_strncmp("unset", value, 6))
		ft_unset(data, cmds);
}
