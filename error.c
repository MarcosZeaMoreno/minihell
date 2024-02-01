/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:25:58 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/18 17:50:45 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
}
