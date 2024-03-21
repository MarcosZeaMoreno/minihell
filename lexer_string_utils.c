/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_string_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:56:25 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/21 17:58:48 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function that processes characters in the lexer
 * in case of a string token.
 * 
 * @param lexer The lexer object.
 * @param value The value of the token.
 * @return char* The value of the token.
 * @var tmp The temporary string.
 */
char	*ft_lexer_process_chars(t_lexer *lexer, char *value)
{
	char	*tmp;

	tmp = ft_lexer_char_to_str(lexer);
	value = ft_realloc(value,
			(ft_strlen(value) + ft_strlen(tmp) + 1) * sizeof(char));
	ft_strcat(value, tmp);
	ft_lexer_advance(lexer);
	return (value);
}
