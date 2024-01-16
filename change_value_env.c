/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_value_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:18:21 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/15 16:18:21 by mzea-mor         ###   ########.fr       */
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
	data->env_copy;
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
