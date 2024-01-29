/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:34:51 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/29 02:06:46 by vkatason         ###   ########.fr       */
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
 * @brief The function skips all whitespace characters
 * (space, tab, newline) in the input and advances the lexer.
 * 
 * @param lexer The lexer object. 
 */
void	ft_lexer_skip_whitespace(t_lexer *lexer)
{
	while (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n')
		ft_lexer_advance(lexer);
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
	while (lexer->c != '\0' && lexer->i < ft_strlen(lexer->input))
	{
		if (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n')
		{
			ft_lexer_skip_whitespace(lexer);
			return (ft_lexer_advance_with_tkn(lexer, ft_init_tkn(TKN_WHITESPACE,
						ft_lexer_get_char(lexer))));
		}
		if (lexer->c == '"')
		{
			ft_lexer_get_string(lexer);
		}
		else if (lexer->c == ';')
		{
			return (ft_lexer_advance_with_tkn(lexer, ft_init_tkn(TKN_SEMICOLON,
						ft_lexer_get_char(lexer))));
		}
		else if (lexer->c == '|' && lexer->input[lexer->i + 1] == '|')
		{
			lexer->i++;
			return (ft_lexer_advance_with_tkn(lexer,
					ft_init_multi_tkn(TKN_DOUBLE_PIPE, "||")));
		}
		else if (lexer->c == '|')
		{
			return (ft_lexer_advance_with_tkn(lexer, ft_init_tkn(TKN_PIPE,
						ft_lexer_get_char(lexer))));
		}
		else if (lexer->c == '<' && lexer->input[lexer->i + 1] == '<')
		{
			lexer->i++;
			return (ft_lexer_advance_with_tkn(lexer,
					ft_init_multi_tkn(TKN_REDIR_HERE_DOC, "<<")));
		}
		else if (lexer->c == '<')
		{
			return (ft_lexer_advance_with_tkn(lexer, ft_init_tkn(TKN_REDIR_IN,
						ft_lexer_get_char(lexer))));
		}
		else if (lexer->c == '>' && lexer->input[lexer->i + 1] == '>')
		{
			lexer->i++;
			return (ft_lexer_advance_with_tkn(lexer,
					ft_init_multi_tkn(TKN_REDIR_APPEND, ">>")));
		}
		else if (lexer->c == '>')
		{
			return (ft_lexer_advance_with_tkn(lexer, ft_init_tkn(TKN_REDIR_OUT,
						ft_lexer_get_char(lexer))));
		}
		else if (lexer->c == '$')
		{
			return (ft_lexer_advance_with_tkn(lexer, ft_init_tkn(TKN_DOLLAR,
						ft_lexer_get_char(lexer))));
		}
		else if (lexer->c == '&' && lexer->input[lexer->i + 1] == '&')
		{
			lexer->i++;
			return (ft_lexer_advance_with_tkn(lexer,
					ft_init_multi_tkn(TKN_DOUBLE_AMPER, "&&")));
		}
		else if (lexer->c == '&')
		{
			return (ft_lexer_advance_with_tkn(lexer, ft_init_tkn(TKN_AMPER,
						ft_lexer_get_char(lexer))));
		}
		else if (lexer->c == '~')
		{
			return (ft_lexer_advance_with_tkn(lexer, ft_init_tkn(TKN_TILDE,
						ft_lexer_get_char(lexer))));
		}
		else if (ft_isalnum((int)lexer->c) == 1)
			return (ft_lexer_get_word(lexer));
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

	ft_lexer_advance(lexer);
	value = ft_calloc(1, sizeof(char));
	value[0] = '\0';
	while (lexer->c != '"')
	{
		tmp = ft_lexer_get_char(lexer);
		value = ft_realloc(value, (ft_strlen(value) + ft_strlen(tmp) + 1)
				* sizeof(char));
		ft_strcat(value, tmp);
	}
	ft_lexer_advance(lexer);
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

	ft_lexer_advance(lexer);
	value = ft_calloc(1, sizeof(char));
	value[0] = '\0';
	while (ft_isalnum((int)lexer->c) == 1)
	{
		tmp = ft_lexer_get_char(lexer);
		value = ft_realloc(value, (ft_strlen(value) + ft_strlen(tmp) + 1)
				* sizeof(char));
		ft_strcat(value, tmp);
	}
	ft_lexer_advance(lexer);
	return (ft_init_tkn(TKN_WORD, value));
}

/**
 * @brief Basically, it's a helper function 
 * for ft_lexer_get_next_token that advances
 *  the lexer to the next character 
 * and returns the given token.
 * 
 * @param lexer The lexer object.
 * @param tkn The token to be returned.
 * @return The given token.
 */
t_tkn *ft_lexer_advance_with_tkn(t_lexer *lexer, t_tkn *tkn)
{
	ft_lexer_advance(lexer);
	return (tkn);
}

/**
 * @brief The gets current character as a string
 * 
 * @param lexer The lexer object. 
 * @return char* Current character as a string.
 */
char	*ft_lexer_get_char(t_lexer *lexer)
{
	char	*value;

	value = ft_calloc(2, sizeof(char));
	value[0] = lexer->c;
	value[1] = '\0';
	return (value);
}
