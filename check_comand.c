/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:46:14 by mzea-mor          #+#    #+#             */
/*   Updated: 2023/12/21 17:07:26 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function used to detect if a command is valid.
 * 
 * @param ptr: a pointer that contain the string of readline.
 * @return int: "1" if ok, "0" if error.
 */
int	check_comand(char *ptr)
{
	if (!ft_strncmp("echo", ptr, 5))
		return (1);
	else if (!ft_strncmp("cd", ptr, 3))
		return (1);
	else if (!ft_strncmp("pwd", ptr, 4))
		return (1);
	else if (!ft_strncmp("export", ptr, 7))
		return (1);
	else if (!ft_strncmp("unset", ptr, 6))
		return (1);
	else if (!ft_strncmp("env", ptr, 4))
		return (1);
	else if (!ft_strncmp("exit", ptr, 5))
			return (1);
	else
		return (0);
}
