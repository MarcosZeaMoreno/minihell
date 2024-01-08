/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:09:15 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/08 16:34:09 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to print a prompt with the actual directory
 * and the name of the proyect.
 * 
 */
void	print_entry(void)
{
	char	*cwd;
	char	buffer[4096 + 1];

	cwd = getcwd(buffer, 4096);
	ft_printf("%s %sMiniHell:%s", cwd, RED, RST);
}

/**
 * @brief Function used to print an exit.
 * 
 */
void	print_exit(void)
{
	ft_printf("%s%s%s\n", CYAN, "Goodbye!", RST);
}

/**
 * @brief Function to print a header.
 * 
 */
void	print_header(void)
{
	ft_printf(RED "*************************************************\n" RST);
	ft_printf(RED "*   _ _ _     _                      _          *\n" RST);
	ft_printf(RED "*  | | | |___| |___ ___ _____ ___   | |_ ___    *\n" RST);
	ft_printf(RED "*  | | | | -_| |  _| . |     | -_|  |  _| . |   *\n" RST);
	ft_printf(RED "*  |_____|___|_|___|___|_|_|_|___|  |_| |___|   *\n" RST);
	ft_printf(RED "*                                               *\n" RST);
	ft_printf(RED "*                                               *\n" RST);
	ft_printf(RED "*         _____ _     _    __ __     _ _        *\n" RST);
	ft_printf(RED "*        |     |_|___|_|  |  |  |___| | |       *\n" RST);
	ft_printf(RED "*        | | | | |   | |  |     | -_| | |       *\n" RST);
	ft_printf(RED "*        |_|_|_|_|_|_|_|  |__|__|___|_|_|       *\n" RST);
	ft_printf(RED "*                                               *\n" RST);
	ft_printf(RED "*************************************************\n" RST);
}

