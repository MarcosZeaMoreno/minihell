/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tkns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:16:12 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/11 17:49:15 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function prints tokens from the user input
 * with the type and value of each token
 * (see enum e_tkn_type in lexer.h)
 * 
 * @param str user input string
 */
void	print_tkn(t_tkn *tkn)
{
	const char	*tkn_types[] = {
		"TKN_WHITESPACE", "TKN_TAB", "TKN_NEWLINE", "TKN_DOT",
		"TKN_COMMA", "TKN_COLON", "TKN_SEMICOLON", "TKN_EXCLAMATION",
		"TKN_QUESTION", "TKN_SLASH", "TKN_BACKSLASH", "TKN_ASTERISK",
		"TKN_EQUALS", "TKN_MINUS", "TKN_PLUS", "TKN_PIPE", "TKN_DOUBLE_PIPE",
		"TKN_REDIR_IN", "TKN_REDIR_OUT", "TKN_REDIR_APPEND",
		"TKN_REDIR_HERE_DOC", "TKN_DOLLAR", "TKN_AMPER", "TKN_DOUBLE_AMPER",
		"TKN_TILDE", "TKN_BACKTICK", "TKN_SNGL_QUOTE", "TKN_DOUBLE_QUOTE",
		"TKN_LEFT_PAR", "TKN_RIGHT_PAR", "TKN_LEFT_BRACKET",
		"TKN_RIGHT_BRACKET", "TKN_LEFT_BRACE", "TKN_RIGHT_BRACE", "TKN_WORD",
		"TKN_STRING"
	};

	ft_printf("TKN#%d\t |", tkn->order);
	ft_printf("TYPE: %s\t\t |", tkn_types[tkn->e_type]);
	ft_printf("VALUE: %s\n", tkn->value);
}

/**
 * @brief Function prints the list of tokens
 * saved in the data->tkns
 * 
 * @param data The main data structure
 */
void	print_tkn_lst(t_data *data)
{
	t_tkn_lst	*current;

	current = data->tkns;
	while (current != NULL)
	{
		print_tkn(current->tkn);
		current = current->next;
	}
}