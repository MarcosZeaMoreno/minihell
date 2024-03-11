/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:21:51 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/11 16:48:27 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tkn	*ft_handle_quotes(t_lexer *lexer)
{
	if (lexer->c == '"' || lexer->c == '\'')
	{
		return (ft_lexer_get_string(lexer));
	}
	return (NULL);
}

t_tkn	*ft_handle_whitespace(t_lexer *lexer)
{
	if (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n')
	{
		ft_lexer_advance(lexer);
	}
	return (NULL);
}

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
