/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:55:51 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/02/12 21:26:19 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to get current directory
 * 
 * @return char* 
 */
char	*get_current_directory(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		ft_printf_fd(1, "cd: error\n");
	return (pwd);
}

/**
 * @brief Function to change directory
 * 
 * @param dir 
 * @return int 
 */
int	change_directory(char *dir)
{
	if (chdir(dir) == -1)
	{
		ft_error(dir, 3);
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
	free(pwd_old);
	free(pwd_new);
}

/**
 * @brief Function to handle the cd builtin
 * 
 * @param data 
 * @param token
 */
void	ft_cd(t_data *data, t_token *token)
{
	char	*pwd_old;
	char	*pwd_new;
	char	*dir;

	pwd_old = get_current_directory();
	if (!pwd_old)
		return ;
	if (token->next == NULL || token->next->value == NULL)
		dir = get_env_value(data->env_copy, "HOME");
	else
		dir = token->next->value;
	if (change_directory(dir) == -1)
	{
		free(pwd_old);
		return ;
	}
	pwd_new = get_current_directory();
	if (!pwd_new)
	{
		free(pwd_old);
		return ;
	}
	update_env_variables(data, pwd_old, pwd_new);
}
