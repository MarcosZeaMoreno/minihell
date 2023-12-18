/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:45:41 by mzea-mor          #+#    #+#             */
/*   Updated: 2023/12/18 13:10:31 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* variables de entorno
* echar un ojo a: readdir, closedir, getcwd, getenv
*/
int	main(int ac, char **av, char **env)
{
	char *ptr;

	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		print_entry();
		signal(SIGINT, handle_sigint);
		ptr = readline("");
		if (!ft_strncmp("exit", ptr, 4))
			break ;
	}
	return (0);
}
