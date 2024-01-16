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
void	ft_echo(t_data *data, char *usr_input)
{
	int	i;
	int	flag;

	(void)data;
	i = 4;
	flag = 0;
	if (usr_input[4] == '-' && usr_input[5] == 'n')
	{
		i = 6;
		flag = 1;
	}
	while (usr_input[i] != '\0')
	{
		ft_printf("%c", usr_input[i]);
		i++;
	}
	if (flag == 0)
		ft_printf("\n");
}
