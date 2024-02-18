/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:30:41 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/18 14:05:25 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Check if the input has an open quote
 * and properly balanced quotes.
 * @param usr_input The input string.
 * @var int i The index of the string.
 * @var int flags[3] The flags to check if there is an open quote
 * or an escape character.
 * 
 * @var flags[0] The flag for single quotes.
 * This flag is toggled (switched between 0 and 1)
 * every time a single quote (') is encountered in the user input.
 * If the flag is 1, it means that there is an open single quote.
 * 
 * 
 * If it encounters a backslash followed by a single 
 * quote inside single quotes, it immediately 
 * returns 1 to indicate an error
 * 
 * @var flags[1] The flag for double quotes.
 * This flag is toggled every time a double quote (")
 * is encountered in the user input, but only if a single quote
 * is not currently open (flags[0] is 0) and the next
 * character is not escaped (flags[2] is 0).
 *
 * @var flags[2] The flag for escape characters.
 * This flag is toggled every time a backslash (\) is encountered
 * in the user input. If the flag is 1, it means that the next
 * character is escaped and should not be considered as a quote.
 * 
 * @return int 1 if there is an open quote, 0 otherwise. 
 * 
 * TESTS:
 * This is a test OK
 * This is a 'test' OK
 * "This is a \"test\" ERROR
 * "This is a 'test" OK
 * 'This is a "test' OK
 * "This is a '' test" OK
 * "This is a \"\" test" OK
 * 'This is a \'\' test' ERROR 
 * 'This is a "" test' OK
 * "This is a \"test ERROR (need a " to close the quote, 
 * because escape character is not found and " considered as
 * an open quote in the end of the string)
 * "This is a 'test ERROR (need a " to close the quote)
 * 'This is a "test ERROR (need a ' to close the quote)
 * echo "This is test '$USER '$TERMCOLOR'" OK
 */
int	ft_check_input_quotes(char *usr_input)
{
	int	i;
	int	flags[3];

	i = -1;
	while (++i < 3)
		flags[i] = 0;
	i = -1;
	while (usr_input[++i] != '\0')
	{
		if (usr_input[i] == '\\' && usr_input[i + 1] == '\'' && flags[0])
			return (1);
		if (usr_input[i] == '\\' && !flags[0])
			flags[2] = 1;
		else
		{
			if (usr_input[i] == '\'' && !flags[1])
				flags[0] = !flags[0];
			else if (usr_input[i] == '\"' && !flags[0] && !flags[2])
				flags[1] = !flags[1];
			flags[2] = 0;
		}
	}
	if (flags[0] || flags[1])
		return (1);
	return (0);
}
