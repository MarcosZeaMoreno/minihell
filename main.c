/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:45:41 by mzea-mor          #+#    #+#             */
/*   Updated: 2023/12/21 17:07:26 by mzea-mor         ###   ########.fr       */
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
	char *ptr;

	(void)ac;
	(void)av;
	(void)env;
	print_header();
	while (1)
	{
		print_entry();
		signal(SIGINT, handle_sigint);
		ptr = readline("");
		if (check_comand(ptr) == 0)
			{
				print_entry();
				ft_printf("%s: command not found\n", ptr);
			}
		if (!ft_strncmp("exit", ptr, 5))
			break ;
	}
	print_exit();
	return (0);
}
