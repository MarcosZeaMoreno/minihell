/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:05:16 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/28 20:20:41 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// /**
//  * @brief Function checks if the variable exists in the env_copy list
//  * 
//  * @param usr_input string to check
//  * @param data main data structure
//  * @return int 1 if the variable exists, -1 if not
//  */
// int	ft_check_vars(char *usr_input, t_data *data)
// {
// 	t_var_name	*var_name;
// 	char		*env_value;

// 	var_name = ft_var_name(usr_input);
// 	while (var_name != NULL)
// 	{
// 		env_value = get_env_value(data->env_copy, var_name->name);
// 		if (env_value == NULL)
// 		{
// 			ft_printf_fd(2, "%s: Variable is undefined.\n", var_name->name);
// 			free(var_name->name);
// 			free(var_name);
// 			return (-1);
// 		}
// 		usr_input += var_name->pos;
// 		free(var_name->name);
// 		free(var_name);
// 		var_name = ft_var_name(usr_input);
// 	}
// 	return (1);
// }
