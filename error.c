/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:25:58 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/02/18 18:23:13 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to send error message to the user
 * 
 * @param usr_input The user input string.
 * @param type_error The type of error.
 */
void	ft_error(char *usr_input, int type_error)
{
	ft_printf_fd(2, "%sMiniHell:%s", RED, RST);
	if (type_error == 1)
		ft_printf_fd(2, " %s: command not found\n", usr_input);
	else if (type_error == 2)
		ft_printf_fd(2, " %s: command not exec\n", usr_input);
	else if (type_error == 3)
		ft_printf_fd(2, " %s: no such file or directory\n", usr_input);
	else if (type_error == 4)
		ft_printf_fd(2, " %s: is not a directory\n", usr_input);
	else if (type_error == 11)
		ft_printf_fd(2, " Wrong quotes usage\n");
	else if (type_error == 12)
		ft_printf_fd(2, " Syntax error\n");
}
