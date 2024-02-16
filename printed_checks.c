/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:32:11 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/16 20:03:25 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to print the result 
 * of the check_input_quotes function
 * that checks if there is an open quote
 * in the user input (single or double).
 * Function is used for debugging purposes.
 * @param usr_input Input from the user
 * to be checked for open quotes.
 */
void	ft_print_check_input_quotes(char *usr_input)
{
	int		result;
	char	*status;

	result = ft_check_input_quotes(usr_input);
	ft_printf("Test case: %s\n", usr_input);
	ft_printf("Result: %d\n", result);
	if (result == 0)
		status = "OK";
	else
		status = "ERROR";
	ft_printf("Status: %s\n\n", status);
}

/**
 * @brief Function prints the result of ft_all_var_names:
 * the names of all variables found in the string
 * of the user input.
 * 
 * @param usr_input User input string
 * @var var_names The array of variable names
 * @var i The index of the array
 */
void	ft_print_all_var_names(char **usr_input)
{
	char	**var_names;
	int		i;

	var_names = ft_all_var_names(usr_input);
	if (var_names != NULL)
	{
		i = 0;
		while (var_names[i] != NULL)
		{
			ft_printf("Variable number: %d\n", i + 1);
			ft_printf("Variable name: %s\n", var_names[i]);
			free(var_names[i]);
			i++;
		}
		free(var_names);
	}
	else
		ft_printf("No variables found.\n");
}
