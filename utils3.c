/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:18:49 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/01 18:19:02 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to free a token structure
 * 
 * @param tkn: a pointer to the token structure.
 */
void	ft_free_tkn(t_tkn *tkn)
{
	if (tkn == NULL)
		return ;
	free(tkn->value);
	free(tkn);
}
