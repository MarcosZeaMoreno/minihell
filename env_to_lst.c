/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:01:14 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/09 17:39:09 by vkatason         ###   ########.fr       */
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
	env_lst->key = strtok(env, "=");
	env_lst->value = strtok(NULL, "=");
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
t_env	*ft_env_lst_last(t_data *data)
{
	if (!data->env_copy)
		return (0);
	while (data->env_copy->next)
		data->env_copy = data->env_copy->next;
	return (data->env_copy);
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
	env_lst->key = strtok(env, "=");
	env_lst->value = strtok(NULL, "=");
	env_lst->next = NULL;
	ft_env_lst_last(data)->next = env_lst;
	return (data->env_copy);
}
