/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:23:45 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/18 17:54:45 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Function to handle the export builtin
* @param data
* @param token
*/
void	ft_export(t_data *data, t_token *token)
{
	char	*key;
	char	*value;

	token = token->next;
	while (token != NULL)
	{
		key = ft_strtok(token->value, "=");
		value = ft_strtok(NULL, "=");
		if (key == NULL || value == NULL)
		{
			ft_printf("export: %s: Invalid argument\n", token->value);
			return ;
		}
		if (get_env_value(data->env_copy, key) != NULL)
			change_value_env(data, key, value);
		else
			add_env_var(data, key, value);
		token = token->next;
	}
}

/**
 * @brief Function to handle the unset builtin
 * 
 * @param data 
 * @param token 
 */
void	ft_unset(t_data *data, t_token *token)
{
	char	*key;

	token = token->next;
	while (token != NULL)
	{
		key = token->value;
		if (key == NULL)
		{
			ft_printf("unset: %s: Invalid argument\n", token->value);
			token = token->next;
			continue ;
		}
		if (get_env_value(data->env_copy, key) != NULL)
			remove_env_var(data, key);
		token = token->next;
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
		ft_printf("%s=%s\n", env->key, env->value);
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
		ft_printf("%s\n", get_env_value(data->env_copy, "PWD"));
	else
		ft_printf("%s\n", get_env_value(data->env_copy, "HOME"));
}
