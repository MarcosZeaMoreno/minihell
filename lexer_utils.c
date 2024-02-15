/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:30:41 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/14 14:45:00 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to check if a quote is open 
 * in the user input (single or double).
 * @param usr_input Input from the user.
 * @var quote_type Type of quote (single or double).
 * @var is_quote_open Flag to check if a quote is open.
 * @return int 1 if there is an open quote, 0 otherwise. 
 * 
 * TESTS:
 * This is a test OK
 * This is a 'test' OK
 * "This is a \"test\" ERROR
 * "This is a 'test" ERROR
 * 'This is a "test' ERROR
 * "This is a '' test" OK
 * "This is a \"\" test" OK
 * 'This is a \'\' test' OK
 * 'This is a "" test' OK
 * "This is a \"test OK
 */
int	ft_check_input_quotes(char *usr_input)
{
	char	quote_type;
	int		is_quote_open;

	is_quote_open = 0;
	while (*usr_input)
	{
		if (*usr_input == quote_type && is_quote_open)
		{
			is_quote_open = 0;
			quote_type = 0;  // Reset quote_type when a quote is closed
		}
		else if (ft_match_symbol(*usr_input, "\"\'") && !is_quote_open)
		{
			quote_type = *usr_input;
			is_quote_open = 1;
			if (*(usr_input + 1) == quote_type && *(usr_input + 2) != quote_type)
				return (1);  // Return error if two consecutive quotes of the same type are found
		}
		usr_input++;
	}
	if (is_quote_open)
		return (1);
	return (0);
}

