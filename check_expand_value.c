/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:05:16 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/29 16:34:17 by vkatason         ###   ########.fr       */
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
int	ft_check_vars(t_list *node, t_data *data)
{
	t_var_name	*var_name;
	char		*env_value;

	var_name = (t_var_name *)node->content;
	env_value = get_env_value(data->env_copy, var_name->name);
	if (env_value == NULL)
	{
		ft_printf_fd(2, "%s: Variable is undefined.\n", var_name->name);
		return (-1);
	}
	ft_printf("Variable: %s, Value: %s\n", var_name->name, env_value);
	return (1);
}
