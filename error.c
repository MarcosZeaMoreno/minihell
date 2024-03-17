/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:25:58 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/03/17 19:22:13 by vkatason         ###   ########.fr       */
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
		ft_printf_fd(2, RED " %s: command not found\n" RST, usr_input);
	else if (type_error == 2)
		ft_printf_fd(2, RED " %s: command not exec\n" RST, usr_input);
	else if (type_error == 3)
		ft_printf_fd(2, RED " %s: no such file or directory\n" RST, usr_input);
	else if (type_error == 4)
		ft_printf_fd(2, RED " %s: is not a directory\n" RST, usr_input);
	else if (type_error == 11)
		ft_printf_fd(2, RED " Wrong quotes usage\n" RST);
	else if (type_error == 12)
		ft_printf_fd(2, RED " Syntax error\n" RST);
	else if (type_error == 13)
		ft_printf_fd(2, RED " Syntax error near unexpected token '%s'\n" RST,
			usr_input);
	else if (type_error == 14)
		ft_printf_fd(2, RED " Unexpected token in input '%s'\n" RST,
			usr_input);
}
