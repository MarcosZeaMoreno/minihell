/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:34:51 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/12 19:46:16 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief The function initializes the lexer object.
 * 
 * @param input User input readed by readline.
 * @return t_lexer* Pointer to the lexer object.
 */
t_lexer	*ft_init_lexer(char *input)
{
	t_lexer	*lexer;

	lexer = ft_calloc(1, sizeof(t_lexer));
	lexer->input = input;
	lexer->i = 0;
	lexer->c = input[lexer->i];
	return (lexer);
}

/**
 * @brief The function advances the lexer to the next character.
 * 
 * @param lexer The lexer object. 
 */
void	ft_lexer_advance(t_lexer *lexer)
{
	if (lexer->c != '\0' && lexer->i < ft_strlen(lexer->input))
	{
		lexer->i += 1;
		lexer->c = lexer->input[lexer->i];
	}
}

/**
 * @brief The function gets different tokens from the input.
 * It is a finite state machine that returns a token. It checks
 * the current character and returns the corresponding token.
 * 
 * @param lexer The lexer object. 
 * @return t_tkn* Pointer to the token.
 */
t_tkn	*ft_lexer_get_next_token(t_lexer *lexer)
{
	char	*value;

	while (lexer->c != '\0' && lexer->i < ft_strlen(lexer->input))
	{
		if (lexer->c == '"' || lexer->c == '\'')
		{
			return (ft_lexer_get_string(lexer));
		}
		if (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n')
			ft_lexer_advance(lexer);
		else if (lexer->c == '|' && ft_count_the_same(lexer, '|') >= 2)
		{
			value = ft_str_repeat('|', ft_count_the_same(lexer, '|'));
			lexer->i += ft_count_the_same(lexer, '|');
			lexer->c = lexer->input[lexer->i];
			return (ft_init_tkn(TKN_ERROR, value));
		}
		else if (lexer->c == '|' && ft_count_the_same(lexer, '|') == 1)
			return (ft_lexer_advance_with_tkn(lexer, ft_init_tkn(TKN_PIPE,
						ft_lexer_char_to_str(lexer))));
		else if (lexer->c == '<' && ft_count_the_same(lexer, '<') >= 3)
		{
			value = ft_str_repeat('<', ft_count_the_same(lexer, '<'));
			lexer->i += ft_count_the_same(lexer, '<');
			lexer->c = lexer->input[lexer->i];
			return (ft_init_tkn(TKN_ERROR, value));
		}
		else if (lexer->c == '>' && ft_count_the_same(lexer, '>') >= 3)
		{
			value = ft_str_repeat('>', ft_count_the_same(lexer, '>'));
			lexer->i += ft_count_the_same(lexer, '>');
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
		else if (ft_is_extended((int)lexer->c))
			return (ft_lexer_get_word(lexer));
		else
			ft_lexer_advance(lexer);
	}
	return (NULL);
}

/**
 * @brief The function gets a string from the input.
 * As a string, we consider a sequence of characters
 * between two double quotes.
 * 
 * @param lexer The lexer object. 
 * @return t_tkn* Pointer to the token with a TKN_STRING type.
 */
t_tkn	*ft_lexer_get_string(t_lexer *lexer)
{
	char	*value;
	char	*tmp;
	char	quote;

	quote = lexer->c;
	ft_lexer_advance(lexer);
	value = ft_calloc(1, sizeof(char));
	value[0] = '\0';
	while (lexer->c != quote)
	{
		tmp = ft_lexer_char_to_str(lexer);
		value = ft_realloc(value, (ft_strlen(value) + ft_strlen(tmp) + 1)
				* sizeof(char));
		ft_strcat(value, tmp);
		ft_lexer_advance(lexer);
	}
	ft_lexer_advance(lexer);
	if (lexer->c == quote)
	{
		return (ft_lexer_get_string(lexer));
	}
	return (ft_init_tkn(TKN_STRING, value));
}

/**
 * @brief The function gets a word from the input.
 * As a word, we consider a sequence of alphanumeric
 * characters.
 * 
 * @param lexer The lexer object. 
 * @return t_tkn* Pointer to the token with a TKN_WORD type.
 */
t_tkn	*ft_lexer_get_word(t_lexer *lexer)
{
	char	*value;
	char	*tmp;

	value = ft_calloc(1, sizeof(char));
	value[0] = '\0';
	while (ft_is_extended((int)lexer->c))
	{
		if (lexer->c == ' '
			|| lexer->c == '|'
			|| lexer->c == '>'
			|| lexer->c == '<')
			break ;
		tmp = ft_lexer_char_to_str(lexer);
		value = ft_realloc(value, (ft_strlen(value) + ft_strlen(tmp) + 1)
				* sizeof(char));
		ft_strcat(value, tmp);
		ft_lexer_advance(lexer);
	}
	return (ft_init_tkn(TKN_WORD, value));
}
