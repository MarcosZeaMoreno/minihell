/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:32:11 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/14 14:07:13 by vkatason         ###   ########.fr       */
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
 *
 * TESTS:
 * This is a test OK
 * This is a 'test' OK
 * "This is a \"test\" ERROR
 * "This is a 'test" ERROR
 * "This is a \"test" ERROR
 * "This is a '' test" 
 * "This is a \"\" test"
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
