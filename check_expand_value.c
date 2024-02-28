/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:05:16 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/28 21:27:55 by vkatason         ###   ########.fr       */
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
int	ft_check_vars(char *usr_input, t_data *data)
{
	t_list		*var_list;
	t_list		*tmp;
	t_var_name	*var_name;
	char		*env_value;

	var_list = ft_var_name(usr_input);
	tmp = var_list;
	while (tmp != NULL)
	{
		var_name = (t_var_name *)tmp->content;
		env_value = get_env_value(data->env_copy, var_name->name);
		if (env_value == NULL)
		{
			ft_printf_fd(2, "%s: Variable is undefined.\n", var_name->name);
			ft_free_var_list(var_list);
			return (-1);
		}
		tmp = tmp->next;
	}
	ft_free_var_list(var_list);
	return (1);
}
