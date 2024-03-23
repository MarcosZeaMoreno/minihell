/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:23:45 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/03/23 19:15:09 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to handle the echo builtin
 * 
 * @param data 
 * @param cmds 
 */
void	ft_export(t_data *data, char **cmds)
{
	char	*key;
	char	*value;
	int		i;

	i = 1;
	while (cmds[i] != NULL)
	{
		key = ft_strtok(cmds[i], "=");
		value = ft_strtok(NULL, "=");
		if (key == NULL || value == NULL)
		{
			ft_printf_fd(1, "export: %s: Invalid argument\n", cmds[i]);
			return ;
		}
		if (get_env_value(data->env_copy, key) != NULL)
			change_value_env(data, key, value);
		else
			add_env_var(data, key, value);
		i++;
	}
}

/**
 * @brief Function to handle the unset builtin
 * 
 * @param data 
 * @param cmds 
 */
void	ft_unset(t_data *data, char **cmds)
{
	char	*key;
	int		i;

	i = 0;
	while (cmds[i] != NULL)
	{
		key = cmds[i];
		if (key == NULL)
		{
			ft_printf_fd(1, "unset: %s: Invalid argument\n", cmds[i]);
			i++;
			continue ;
		}
		if (get_env_value(data->env_copy, key) != NULL)
			remove_env_var(data, key);
		if (cmds[i] != NULL)
			i++;
	}
}

/**
 * @brief Function to handle the env builtin
 * 
 * @param env
 */
void	ft_env(t_env *env)
{
	while (env != NULL)
	{
		ft_printf_fd(1, "%s=%s\n", env->key, env->value);
		env = env->next;
	}
}

/**
 * @brief Function to handle the pwd builtin
 * 
 * @param data 
 */
void	ft_pwd(t_data *data)
{
	if (get_env_value(data->env_copy, "PWD") != NULL)
		ft_printf_fd(1, "%s\n", get_env_value(data->env_copy, "PWD"));
	else
		ft_printf_fd(1, "%s\n", get_env_value(data->env_copy, "HOME"));
}
