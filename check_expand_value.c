/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:05:16 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/01 16:06:40 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function checks if the variables exist in the env_copy list
 * 
 * @param usr_input string to check
 * @param data main data structure
 * @return int 1 if all variables exist, -1 if any variable does not exist
 */
char	*ft_check_vars(t_list *node, t_data *data)
{
	t_var_name	*var;

	var = (t_var_name *)node->content;
	var->value = ft_strdup(get_env_value(data->env_copy, var->name));
	return (var->value);
}

/**
 * @brief Function to fill the values of the variables in the list
 * 
 * @param usr_input The user input string
 * @param data The main data structure
 * @var var_list The list of variables
 * @var tmp The pointer to the current node in the list
 * @var var_name The structure that holds the variable name, 
 * it's position in the string and value
 * @return t_list* The list of variables
 */
t_list	*ft_fill_values(char *usr_input, t_data *data)
{
	t_list		*var_list;
	t_list		*tmp;

	var_list = ft_var_name(usr_input);
	tmp = var_list;
	while (tmp != NULL)
	{
		ft_check_vars(tmp, data);
		tmp = tmp->next;
	}
	return (var_list);
}
