/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:27:36 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/11 13:01:06 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Initializes a token with the given type and value.
 * This function allocates memory for a new token, sets its type and value,
 * and returns a pointer to the created token.
 *
 * @param type The type of the token.
 * @param value The value of the token.
 * @return A pointer to the created token.
 */
t_tkn	*ft_init_tkn(int type, char *value)
{
	t_tkn	*tkn;

	tkn = ft_calloc(1, sizeof(t_tkn));
	if (tkn == NULL)
	{
		ft_putstr_fd("Error: Failed to allocate memory for token\n", 2);
		exit(EXIT_FAILURE);
	}
	tkn->e_type = type;
	tkn->value = value;
	tkn->order = ft_reset_tkn_order(0);
	return (tkn);
}

/**
 * @brief Initializes a token with the given type and value.
 * The difference between this function and ft_init_tkn is that
 * this function duplicates the value that let us make double symbols
 * like >>, <<, &&, ||, etc using ft_strdup function.  
 * 
 * @param type The type of the token.
 * @param value The value of the token.
 * @return A pointer to the created token.
 */
t_tkn	*ft_init_multi_tkn(int type, char *value)
{
	t_tkn		*tkn;

	tkn = ft_calloc(1, sizeof(t_tkn));
	if (tkn == NULL)
	{
		ft_putstr_fd("Error: Failed to allocate memory for token\n", 2);
		exit(EXIT_FAILURE);
	}
	tkn->e_type = type;
	tkn->value = ft_strdup(value);
	tkn->order = ft_reset_tkn_order(0);
	return (tkn);
}

/**
 * @brief Adds a token to the token list.
 *
 * @param head The head of the token list.
 * @param tkn The token to be added.
 * @return The updated head of the token list.
 */
t_tkn_lst	*ft_add_tkn_to_lst(t_tkn_lst *head, t_tkn *tkn)
{
	t_tkn_lst	*new_lst_node;
	t_tkn_lst	*current;

	if (tkn == NULL)
	{
		ft_putstr_fd("Error: Null token\n", 2);
		return (head);
	}
	new_lst_node = malloc(sizeof(t_tkn_lst));
	if (new_lst_node == NULL)
	{
		ft_putstr_fd("Error: Failed to allocate memory for token_list\n", 2);
		exit(EXIT_FAILURE);
	}
	new_lst_node->tkn = tkn;
	new_lst_node->next = NULL;
	new_lst_node->prev = NULL;
	if (head == NULL)
		return (new_lst_node);
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_lst_node;
	new_lst_node->prev = current;
	return (head);
}

/**
 * @brief Tokenizes the input string.
 * This function tokenizes the input string and stores 
 * the tokens in a token list in the data structure.
 *
 * @param input The input string.
 * @param data The main data structure.
 */
void	ft_tknize_input(t_data *data)
{
	t_lexer	*lexer;
	t_tkn	*tkn;

	if (data->tkns != NULL)
	{
		ft_free_tkn_lst(data->tkns);
		data->tkns = NULL;
	}
	lexer = ft_init_lexer(data->input_copy);
	data->tkns = NULL;
	while (1)
	{
		tkn = ft_lexer_get_next_token(lexer);
		if (tkn == NULL)
			break ;
		data->tkns = ft_add_tkn_to_lst(data->tkns, tkn);
	}
}

/**
 * @brief The function that frees the token list.
 * 
 * @param head The head of the token list. 
 */
void	ft_free_tkn_lst(t_tkn_lst *head)
{
	t_tkn_lst	*current;
	t_tkn_lst	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		if (current->tkn != NULL)
		{
			if (current->tkn->value != NULL)
			{
				free(current->tkn->value);
				current->tkn->value = NULL;
			}
			free(current->tkn);
			current->tkn = NULL;
		}
		//free(current);
		current = next;
		if (current != NULL)
			current->prev = NULL;
	}
	ft_reset_tkn_order(1);
}
