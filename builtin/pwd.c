/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:08:35 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/12 16:21:45 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

/**
 * @brief Function to get a value from an environment variable
 * 
 * @param data 
 * @param usr_input 
 */
char	*get_env_value(t_env *env, char *key)
{
	while (env->next != NULL)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}
