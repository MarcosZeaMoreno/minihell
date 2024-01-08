/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:46:14 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/08 16:36:09 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function used to detect if a command is valid.
 * 
 * @param usr_input: a pointer that contain the string of readline.
 * @return int: "1" if ok, "0" if error.
 */
int	check_comand(char *usr_input)
{
	if (!ft_strncmp("echo", usr_input, 5))
		return (1);
	else if (!ft_strncmp("cd", usr_input, 3))
		return (1);
	else if (!ft_strncmp("pwd", usr_input, 4))
		return (1);
	else if (!ft_strncmp("export", usr_input, 7))
		return (1);
	else if (!ft_strncmp("unset", usr_input, 6))
		return (1);
	else if (!ft_strncmp("env", usr_input, 4))
		return (1);
	else if (!ft_strncmp("exit", usr_input, 5))
		return (1);
	else if (!ft_strncmp("", usr_input, 1))
		return (1);
	else
		return (0);
}
