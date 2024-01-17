/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:32:25 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/16 17:12:41 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to handle the echo builtin
 * 
 * @param data 
 * @param usr_input 
 */
void	ft_echo(t_data *data, t_token token)
{
	int		flag;
	t_token	tmp;

	(void)data;
	tmp = token;
	tmp = tmp->next;
	flag = 0;
	if (!ft_strncmp("-n", token->next->value, 3))
	{
		tmp = tmp->next;
		flag = 1;
	}
	while (tmp->next != NULL)
	{
		ft_printf("%s", tmp->value);
		tmp = tmp->next;
	}
	if (flag == 0)
		ft_printf("\n");
}
