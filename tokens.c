/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:20:22 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/02/19 18:35:50 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to handle the tokenizer
 * 
 * @param usr_input 
 * @return t_token* 
 */
t_token	*ft_tokenizer(char *usr_input)
{
	t_token	*token;
	t_token	*tmp;
	char	**split_input;
	int		i;

	i = 0;
	if (ft_is_input_error(usr_input))
		return (NULL);
	split_input = ft_split(usr_input, ' ');
	if (!split_input || !split_input[i])
		return (NULL);
	token = ft_token_lst_new(split_input[i]);
	tmp = token;
	while (split_input[++i] != NULL)
	{
		tmp->next = ft_token_lst_new(split_input[i]);
		tmp = tmp->next;
	}
	free_split(split_input);
	return (token);
}

/**
 * @brief Function to create a new token
 * 
 * @param value 
 * @return t_token* 
 */
t_token	*ft_token_lst_new(char *value)
{
	t_token	*token;

	if (!value)
		return (NULL);
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = ft_strdup(value);
	token->next = NULL;
	return (token);
}

/**
 * @brief Function to add a new token to the end of the list
 * 
 * @param token 
 * @param value 
 */
void	ft_token_lst_add_back(t_token *token, char *value)
{
	t_token	*tmp;

	tmp = token;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_token_lst_new(value);
}

/**
 * @brief Function to get the last token of the list
 * 
 * @param token 
 * @return t_token* 
 */
t_token	*ft_token_lst_last(t_token *token)
{
	if (!token)
		return (NULL);
	while (token->next)
		token = token->next;
	return (token);
}

/**
 * @brief Function to free the token list
 * 
 * @param token 
 */
void	ft_token_lst_free(t_token *token)
{
	t_token	*tmp;

	while (token != NULL)
	{
		tmp = token->next;
		free(token->value);
		free(token);
		token = tmp;
	}
}
