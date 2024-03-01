/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:05:16 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/01 14:13:11 by vkatason         ###   ########.fr       */
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
	var->value = get_env_value(data->env_copy, var->name);
	return (var->value);
}

