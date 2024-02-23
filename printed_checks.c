/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:32:11 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/23 13:37:44 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function prints the original user input
 * and the result of ft_clean_input: the user input
 * with replaced variables.
 * 
 * @param str user input string
 */
void	print_replaced_input(char *usr_input, t_data *data)
{
	if (usr_input != NULL)
	{
		ft_printf("Original input: %s\n", usr_input);
		ft_clean_input(&usr_input, data);
		ft_printf("Replaced input: %s\n", usr_input);
	}
	else
		ft_printf("No input.\n");
}
