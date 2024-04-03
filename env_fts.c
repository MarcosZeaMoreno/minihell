/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:18:21 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/02 19:34:22 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to change the value of an enviroment variable
 * 
 * @param data: a pointer to the data structure.
 * @param key: a pointer to the key.
 * @param value: a pointer to the value.
 */
void	change_value_env(t_data *data, char *key, char *value)
{
	t_env	*temp;
	char	*to_free;

	to_free = NULL;
	temp = data->env_copy;
	while (temp != NULL)
	{
		if (!ft_strncmp(temp->key, key, ft_strlen(key) + 1))
		{
			if (!value)
				to_free = ft_strdup("");
			to_free = ft_strdup(value);
			if (temp->value)
				free(temp->value);
			temp->value = to_free;
			return ;
		}
		temp = temp->next;
	}
}

/**
 * @brief Function to remove a enviromental variable
 * 
 * @param data: a pointer to the data structure.
 * @param key: a pointer to the key.
 */
void	remove_env_var(t_data *data, char *key)
{
	t_env	*current;
	t_env	*prev;

	current = data->env_copy;
	prev = NULL;
	while (current != NULL)
	{
		if (!ft_strncmp(current->key, key, ft_strlen(key)))
		{
			if (prev == NULL)
				data->env_copy = current->next;
			else
				prev->next = current->next;
			free(current->key);
			free(current->value);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

/**
 * @brief Function to add a enviromental variable
 * 
 * @param data: a pointer to the data structure.
 * @param key: a pointer to the key.
 * @param value: a pointer to the value.
 */
void	add_env_var(t_data *data, char *key, char *value)
{
	char	*env_v;
	char	*key_copy;
	char	*value_copy;
	char	*aux;
	char	*temp;

	temp = ft_strdup("=");
	if (!value)
		value = "";
	key_copy = ft_strdup(key);
	value_copy = ft_strdup(value);
	env_v = ft_strjoin_free(key_copy, temp);
	aux = ft_strjoin_free(env_v, value_copy);
	data->env_copy = ft_env_lst_add_back(data, aux);
	free(aux);
}

/**
 * @brief Function to convert the enviromental variables
 * 		into a double char pointer.
 * 
 * @param env: a pointer to the enviromental variables.
 * 
 * @return char**: a double char pointer that contain
 * 		the enviromental variables.
 */
char	**ft_env_to_char(t_env *env)
{
	char	**env_cpy;
	t_env	*temp;
	int		i;

	i = 0;
	temp = env;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	env_cpy = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	temp = env;
	while (temp != NULL)
	{
		env_cpy[i] = ft_strjoin(temp->key, "=");
		env_cpy[i] = ft_strjoin_free(env_cpy[i], ft_strdup(temp->value));
		i++;
		temp = temp->next;
	}
	env_cpy[i] = NULL;
	return (env_cpy);
}
