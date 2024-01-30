/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:27:36 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/30 02:20:25 by vkatason         ###   ########.fr       */
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
	static int	order;
	t_tkn		*tkn;

	tkn = ft_calloc(1, sizeof(t_tkn));
	if (tkn == NULL)
	{
		ft_putstr_fd("Error: Failed to allocate memory for token\n", 2);
		exit(EXIT_FAILURE);
	}
	tkn->e_type = type;
	tkn->value = value;
	tkn->order = order++;
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
	static int	order;
	t_tkn		*tkn;

	tkn = ft_calloc(1, sizeof(t_tkn));
	if (tkn == NULL)
	{
		ft_putstr_fd("Error: Failed to allocate memory for token\n", 2);
		exit(EXIT_FAILURE);
	}
	tkn->e_type = type;
	tkn->value = ft_strdup(value);
	tkn->order = order++;
	return (tkn);
}

