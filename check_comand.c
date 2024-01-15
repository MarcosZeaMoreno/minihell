/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:46:14 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/11 16:27:23 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function used to execute a command by path.
 * 
 * @param usr_input: a pointer that contain the string of readline.
 * @return int: "1" if ok, "0" if error.
 */
int	check_execv(char *usr_input, char **env)
{
	char	*path;
	char	**split;

	split = ft_split(usr_input, ' ');
	path = ft_strjoin("/bin/", usr_input);
	if (execve(path, split, env) == -1)
		return (0);
	else
		execve(path, split, env);
	return (1);
}

/**
 * @brief Function used to detect if a command is a builtin.
 * 
 * @param usr_input: a pointer that contain the string of readline.
 * @return int: "1" if ok, "0" if error.
 */
int	check_builtin(char *usr_input, char **env)
{
	if (!ft_strncmp("echo", usr_input, 5))
		return (1);
	else if (!ft_strncmp("echo -n", usr_input, 5))
		return (1);
	else if (!ft_strncmp("cd", usr_input, 3))
		return (1);
	else if (!ft_strncmp("pwd", usr_input, 4))
		return (1);
	else if (!ft_strncmp("export", usr_input, 7))
		return (1);
	else if (!ft_strncmp("unset", usr_input, 6))
		return (1);
	else if (!ft_strncmp("env", usr_input, 4))
		return (1);
	else if (!ft_strncmp("exit", usr_input, 5))
		return (1);
	else if (!ft_strncmp("", usr_input, 1))
		return (1);
	else
		return (check_execv(usr_input, env));
}

/**
 * @brief Function used to execute a builtin.
 * 
 * @param data: a pointer that contain the main data structure.
 * @param usr_input: a pointer that contain the string of readline.
 */
void	exec_builtin(t_data *data, char *usr_input)
{
	if (!ft_strncmp("echo", usr_input, 5))
		ft_echo(data, usr_input);
	else if (!ft_strncmp("cd", usr_input, 3))
		ft_cd(data, usr_input);
	else if (!ft_strncmp("pwd", usr_input, 4))
		ft_pwd(data);
	else if (!ft_strncmp("export", usr_input, 7))
		ft_export(data, usr_input);
	else if (!ft_strncmp("unset", usr_input, 6))
		ft_unset(data, usr_input);
	else if (!ft_strncmp("env", usr_input, 4))
		ft_env(data->env_copy);
	else if (!ft_strncmp("", usr_input, 1))
		return ;
}
