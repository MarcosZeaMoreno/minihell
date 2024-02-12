/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:46:14 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/02/12 21:29:13 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function used to execute a command by path.
 * 
 * @param usr_input: a pointer that contain the string of readline.
 * @return int: "1" if ok, "0" if error.
 */
void	check_execve(t_data *data, char **env, t_env *enviroment)
{
	char	**cmds;

	cmds = lst_to_char(data->token);
	exec_local(cmds, env, enviroment);
}

/**
 * @brief Function used to detect if a command is a builtin.
 * 
 * @param usr_input: a pointer that contain the string of readline.
 * @return int: "1" if ok, "0" if error.
 */
int	check_builtin(t_token *token)
{
	char	*value;

	if (!token)
		return (-1);
	value = token->value;
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

/**
 * @brief Function used to execute a builtin.
 * 
 * @param data: a pointer that contain the main data structure.
 * @param usr_input: a pointer that contain the string of readline.
 */
void	exec_builtin(t_data *data, t_token *token)
{
	char	*value;

	if (!data || !token)
		return ;
	value = token->value;
	if (!ft_strncmp("echo", value, 5))
		ft_echo(data, token);
	else if (!ft_strncmp("cd", value, 3))
		ft_cd(data, token);
	else if (!ft_strncmp("pwd", value, 4))
		ft_pwd(data);
	else if (!ft_strncmp("export", value, 7))
		ft_export(data, token);
	else if (!ft_strncmp("unset", value, 6))
		ft_unset(data, token);
	else if (!ft_strncmp("env", value, 4))
		ft_env(data->env_copy);
	else if (!ft_strncmp("", value, 1))
		return ;
}
