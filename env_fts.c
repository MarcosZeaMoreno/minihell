/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:18:21 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/18 18:15:01 by mzea-mor         ###   ########.fr       */
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
	t_env	*temp;

	temp = data->env_copy;
	while (temp != NULL)
	{
		if (!ft_strncmp(temp->key, key, ft_strlen(key) + 1))
		{
			temp->value = ft_strdup(value);
			return ;
		}
		temp = temp->next;
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
 * @param data 
 * @param key 
 * @param value 
 */
void	add_env_var(t_data *data, char *key, char *value)
{
	char	*env_v;
	char	*temp;

	env_v = ft_strjoin(key, "=");
	temp = env_v;
	env_v = ft_strjoin(env_v, value);
	free(temp);
	data->env_copy = ft_env_lst_add_back(data, env_v);
}

int	ft_token_size(t_token *token)
{
    int	i;

    i = 0;
    while (token != NULL)
    {
        token = token->next;
        i++;
    }
    return (i);
}

char	**lst_to_char(t_token *token)
{
    char	**cmds;
    int		i;

    i = 0;
    cmds = malloc(sizeof(char *) * (ft_token_size(token) + 1));
    if (!cmds)
        return (NULL);
    while (token != NULL)
    {
        cmds[i] = ft_strdup(token->value);
        token = token->next;
        i++;
    }
    cmds[i] = NULL;
    return (cmds);
}
