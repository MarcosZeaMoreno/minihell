/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:08:57 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/18 16:20:40 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to handle the parse input
 * 
 * @param data 
 * @param usr_input 
 */
void	ft_parse_input(t_data *data, char *usr_input)
{
	t_token	*token;

	token = NULL;
	token = ft_tokenizer(usr_input);
	ft_token_lst_last(token);
	data->token = token;
}
