/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:55:51 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/01 20:01:37 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to get current directory
 *
 * @return char*
 */
char	*get_current_directory(t_data *data)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_printf_fd(1, "cd: error\n");
		data->exit_status = 1;
		return (NULL);
	}
	return (pwd);
}

/**
 * @brief Function to change directory
 *
 * @param dir
 * @return int
 */
int	change_directory(char *dir, t_data *data)
{
	if (chdir(dir) == -1)
	{
		ft_error(dir, 3);
		data->exit_status = 1;
		return (-1);
	}
	return (0);
}

/**
 * @brief Function to update env variables
 *
 * @param data
 * @param pwd_old
 * @param pwd_new
 */
void	update_env_variables(t_data *data, char *pwd_old, char *pwd_new)
{
	change_value_env(data, "OLDPWD", pwd_old);
	change_value_env(data, "PWD", pwd_new);
	free_cd(pwd_old, pwd_new);
}

void	free_cd(char *pwd_old, char *pwd_new)
{
	free(pwd_old);
	free(pwd_new);
}

/**
 * @brief Function to handle the cd builtin
 *
 * @param data
 * @param cmds
 */
void	ft_cd(t_data *data, char **cmds)
{
	char	*pwd_old;
	char	*pwd_new;
	char	*dir;
	int		i;

	i = 1;
	pwd_old = get_current_directory(data);
	if (!pwd_old)
		return ;
	if (cmds[i] == NULL)
		dir = get_env_value(data->env_copy, "HOME");
	else
		dir = cmds[i];
	if (change_directory(dir, data) == -1)
	{
		free_cd(pwd_old, NULL);
		return ;
	}
	pwd_new = get_current_directory(data);
	if (!pwd_new)
	{
		free_cd(pwd_old, NULL);
		return ;
	}
	update_env_variables(data, pwd_old, pwd_new);
}
