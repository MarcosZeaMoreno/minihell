/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:45:41 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/08 16:34:53 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Main function 
 * 
 * @param ac Argument count
 * @param av Argument value
 * @param env Enviroment vars
 * @return int
 * @warning He cambiado el nombre de ptr a usr_input
 */
int	main(int ac, char **av, char **env)
{
	char	*usr_input;

	(void)ac;
	(void)av;
	(void)env;
	print_header();
	while (1)
	{
		print_entry();
		signal(SIGINT, handle_sigint);
		usr_input = readline(" ");
		if (check_comand(usr_input) == 0)
		{
			print_entry();
			ft_printf(" %s: command not found\n", usr_input);
		}
		if (!ft_strncmp("exit", usr_input, 5))
			break ;
	}
	print_exit();
	return (0);
}
