/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:21:51 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/14 16:11:15 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Helper function for ft_lexer_get_next_token
 * that handles quotes. 
 * 
 * @param lexer lexer object
 * @return t_tkn* Pointer to the TKNS_STRING token.
 */
t_tkn	*ft_handle_quotes(t_lexer *lexer)
{
	if (lexer->c == '"' || lexer->c == '\'')
		return (ft_lexer_get_string(lexer));
	return (NULL);
}

/**
 * @brief Helper function for ft_lexer_get_next_token
 * that handles whitespace. Basically, it just advances
 * the lexer if the current character is a whitespace.
 * 
 * @param lexer lexer object
 */
void	ft_handle_whitespace(t_lexer *lexer)
{
	if (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n')
		ft_lexer_advance(lexer);
}

/**
 * @brief Helper function for ft_lexer_get_next_token
 * that handles pipe.
 * 
 * @param lexer lexer object
 * @return t_tkn* TKN_PIPE token if the current
 * character is a pipe, TKN_ERROR if more than 2 pipes
 * found in the string, otherwise NULL.
 */
t_tkn	*ft_handle_pipe(t_lexer *lexer)
{
	char	*value;

	if (lexer->c == '|' && ft_count_the_same(lexer, '|') >= 2)
	{
		value = ft_str_repeat('|', ft_count_the_same(lexer, '|'));
		lexer->i += ft_count_the_same(lexer, '|');
		lexer->c = lexer->input[lexer->i];
		return (ft_init_tkn(TKN_ERROR, value));
	}
	else if (lexer->c == '|' && ft_count_the_same(lexer, '|') == 1)
	{
		return (ft_lexer_advance_with_tkn(lexer, ft_init_tkn(TKN_PIPE,
					ft_lexer_char_to_str(lexer))));
	}
	return (NULL);
}

/**
 * @brief Helper function for ft_lexer_get_next_token
 * that handles less then symbols as redirections.
 * 
 * @var char* value The string where the greater than symbols
 * are stored that will be used to create the token.
 * @param lexer lexer object
 * @return t_tkn* TKN_ERROR if 3 or more < found in the string,
 * TKN_REDIR_HERE_DOC if 2 < found in the string, TKN_REDIR_IN
 * if 1 < found in the string, otherwise NULL.
 */
t_tkn	*ft_handle_less_than(t_lexer *lexer)
{
	char	*value;

	if (lexer->c == '<' && ft_count_the_same(lexer, '<') >= 3)
	{
		value = ft_str_repeat('<', ft_count_the_same(lexer, '<'));
		lexer->i += ft_count_the_same(lexer, '<');
		lexer->c = lexer->input[lexer->i];
		return (ft_init_tkn(TKN_ERROR, value));
	}
	else if (lexer->c == '<' && ft_count_the_same(lexer, '<') == 2)
	{
		lexer->i++;
		return (ft_lexer_advance_with_tkn(lexer,
				ft_init_tkn(TKN_REDIR_HERE_DOC, "<<")));
	}
	else if (lexer->c == '<' && ft_count_the_same(lexer, '<') == 1)
	{
		return (ft_lexer_advance_with_tkn(lexer, ft_init_tkn(TKN_REDIR_IN,
					ft_lexer_char_to_str(lexer))));
	}
	return (NULL);
}

/**
 * @brief Helper function for ft_lexer_get_next_token
 * that handles greater than symbols as redirections.
 * 
 * @var char* value The string where the greater than symbols
 * are stored that will be used to create the token.
 * @param lexer lexer object
 * @return t_tkn* TKN_ERROR if 3 or more > found in the string,
 * TKN_REDIR_APPEND if 2 > found in the string, TKN_REDIR_OUT
 * if 1 > found in the string, otherwise NULL.
 */
t_tkn	*ft_handle_greater_than(t_lexer *lexer)
{
	char	*value;

	if (lexer->c == '>' && ft_count_the_same(lexer, '>') >= 3)
	{
		value = ft_str_repeat('>', ft_count_the_same(lexer, '>'));
		lexer->i += ft_count_the_same(lexer, '>');
		lexer->c = lexer->input[lexer->i];
		return (ft_init_tkn(TKN_ERROR, value));
	}
	else if (lexer->c == '>' && ft_count_the_same(lexer, '>') == 2)
	{
		lexer->i++;
		return (ft_lexer_advance_with_tkn(lexer,
				ft_init_tkn(TKN_REDIR_APPEND, ">>")));
	}
	else if (lexer->c == '>' && ft_count_the_same(lexer, '>') == 1)
	{
		return (ft_lexer_advance_with_tkn(lexer, ft_init_tkn(TKN_REDIR_OUT,
					ft_lexer_char_to_str(lexer))));
	}
	return (NULL);
}
