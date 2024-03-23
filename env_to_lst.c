/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:01:14 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/23 19:16:57 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Funciton that takes env variable
 * and save it to the new env_copy list node 
 * 
 * @param data main data structure
 * @param env enviroment variable
 * @return t_env* 
 */
t_env	*ft_env_lst_new(t_data *data, char *env)
{
	t_env	*env_lst;

	env_lst = (t_env *)malloc(sizeof(t_env));
	if (!env_lst)
		return (0);
	env_lst->key = ft_strtok(env, "=");
	env_lst->value = ft_strtok(NULL, "=");
	env_lst->next = NULL;
	data->env_copy = env_lst;
	return (data->env_copy);
}

/**
 * @brief Function finds the last node of the env list
 * 
 * @param data main data structure
 * @return t_env* updated env_copy
 */
void	ft_env_lst_last(t_data *data, t_env *env_lst)
{
	t_env	*tmp;

	tmp = data->env_copy;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = env_lst;
	tmp = tmp->next;
	tmp->next = NULL;
}

/**
 * @brief Function adds new node to the end of the env list
 * 
 * @param data main data structure
 * @param env enviroment variable
 * @return t_env* updated env_copy
 */
t_env	*ft_env_lst_add_back(t_data *data, char *env)
{
	t_env	*env_lst;

	env_lst = (t_env *)malloc(sizeof(t_env));
	if (!env_lst)
		return (0);
	env_lst->key = ft_strtok(env, "=");
	env_lst->value = ft_strtok(NULL, "=");
	env_lst->next = NULL;
	ft_env_lst_last(data, env_lst);
	return (data->env_copy);
}

/**
 * @brief Function that copies the enviroment variables
 * to the env_copy list
 * 
 * @param data main data structure
 * @param env enviroment variables
 * @return t_data* updated data
 */
t_data	*ft_get_env_cpy(t_data *data, char **env)
{
	int		i;
	char	*env_var;

	i = 0;
	env_var = env[i];
	while (env_var != NULL)
	{
		if (data->env_copy == NULL)
			data->env_copy = ft_env_lst_new(data, env_var);
		else
			data->env_copy = ft_env_lst_add_back(data, env_var);
		i++;
		env_var = env[i];
	}
	return (data);
}

/**
 * @brief Function to get a value from an environment variable
 * 
 * @param env: a pointer to the enviromental variables.
 * @param key: a pointer to the key.
 *
 * @return char*: a pointer to the value.
 */
char	*get_env_value(t_env *env, char *key)
{
	while (env != NULL)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}
