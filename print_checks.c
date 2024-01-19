/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:24:22 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/19 19:26:13 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Fuction prints the result of ft_rm_quotes
 * as a new string.
 * 
 * @param usr_input 
 */
void	print_rm_quotes(char *usr_input)
{
	char	*input_copy;

	input_copy = ft_strdup(usr_input);
	ft_rm_quotes(&input_copy);
	ft_printf("%s\n", input_copy);
	free(input_copy);
}

/**
 * @brief Function prints the result of ft_var_name:
 * the name of the first variable found in the string.
 * 
 * @param str user input string
 */
void	print_var_name(char *str)
{
	char	*var_name;

	var_name = ft_var_name(str);
	if (var_name != NULL)
	{
		ft_printf("First variable name: %s\n", var_name);
		free(var_name);
	}
	else
		ft_printf("No variable found.\n");
}
