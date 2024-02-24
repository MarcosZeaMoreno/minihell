/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:05:16 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/24 18:33:10 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function checks if the variable exists in the env_copy list
 * 
 * @param usr_input string to check
 * @param data main data structure
 * @return int 1 if the variable exists, -1 if not
 */
int	ft_check_vars(char *usr_input, t_data *data)
{
	char	*value;
	char	*env_value;

	value = ft_var_name(usr_input);
	while (value != NULL)
	{
		env_value = get_env_value(data->env_copy, value);
		if (env_value == NULL)
		{
			ft_printf_fd(2, "%s: Variable is undefined.\n", value);
			free(value);
			return (-1);
		}
		usr_input = ft_strchr(usr_input, '$');
		if (usr_input != NULL)
			usr_input += 1;
		free(value);
		value = ft_var_name(usr_input);
	}
	return (1);
}
