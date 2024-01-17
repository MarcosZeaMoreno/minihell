/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:18:21 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/16 15:57:33 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to change the value of an enviroment variable
 * 
 * @param data 
 * @param key 
 * @param value 
 */
void	change_value_env(t_data *data, char *key, char *value)
{
	while (data->env_copy->next != NULL)
	{
		if (!ft_strncmp(data->env_copy->key, key, ft_strlen(key)))
		{
			free(data->env_copy->value);
			data->env_copy->value = ft_strdup(value);
			return ;
		}
		data->env_copy = data->env_copy->next;
	}
}

/**
 * @brief Function to remove a enviromental variable
 * 
 * @param env_lst 
 * @param key 
 */
void	remove_env_var(t_data *data, char *key)
{
	t_env	*prev;

	prev = data->env_copy;
	while (data->env_copy->next != NULL)
	{
		if (!ft_strncmp(data->env_copy->key, key, ft_strlen(key)))
		{
			prev->next = data->env_copy->next;
			free(data->env_copy->key);
			free(data->env_copy->value);
			free(data->env_copy);
			data->env_copy = prev;
			return ;
		}
		prev = data->env_copy;
		data->env_copy = data->env_copy->next;
	}
}

/**
 * @brief Function to add a enviromental variable
 * 
 * @param data 
 * @param key 
 * @param value 
 */
void	add_env_var(t_data *data, char *key, char *value)
{
	char	*env_v;

	env_v = ft_strjoin(key, "=");
	env_v = ft_strjoin(env_v, value);
	data->env_copy = ft_env_lst_add_back(data, env_v);
}

char	**lst_to_char(t_data *data)
{
	char	**cmds;
	int		i;

	i = 0;
	cmds = malloc(sizeof(char *) * (ft_lstsize(data->token) + 1));
	while (data->token->next != NULL)
	{
		cmds[i] = ft_strdup(data->token->value);
		data->token = data->token->next;
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}