/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:32:11 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/24 18:37:03 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function prints the result of ft_var_value:
 * the value of the first variable found in the string
 * is equal to the value of the variable in the environment.
 * 
 * @param str user input string
 */
void	print_var_check_vars(char *usr_input, t_data *data)
{
	int	result;

	result = ft_check_vars(usr_input, data);
	if (result == 1)
		ft_printf("Variable check passed.\n");
	else if (result == -1)
		ft_printf("Undefined variable found.\n");
	else
		ft_printf("Invalid result.\n");
}

/**
 * @brief Function prints the result of all
 * the expandable variable names found in the user input. 
 * @param str user input string
 */
void	print_var_names(char *usr_input)
{
	char	*var_name;

	var_name = ft_var_name(usr_input);
	while (var_name != NULL)
	{
		if (getenv(var_name) != NULL)
		{
			printf("Expandable and existing variable name: %s\n", var_name);
		}
		free(var_name);
		var_name = ft_var_name(usr_input);
	}
}
