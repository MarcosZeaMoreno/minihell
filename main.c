/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:45:41 by mzea-mor          #+#    #+#             */
/*   Updated: 2023/12/27 12:49:59 by vkatason         ###   ########.fr       */
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
 */
int	main(int ac, char **av, char **env)
{
	char	*usr_input; // He cambiado el nombre de ptr a usr_input

	(void)ac;
	(void)av;
	(void)env;

	print_header();
	while (1)
	{
		print_entry();
		signal(SIGINT, handle_sigint);
		usr_input = readline("");
		if (check_comand(usr_input) == 0)
		{
			print_entry();
			ft_printf("%s: command not found\n", usr_input);
		}
		if (!ft_strncmp("exit", usr_input, 5))
			break ;
	}
	print_exit();
	return (0);
}
