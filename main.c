/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:45:41 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/12 17:35:54 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Inits main data structure
 * 
 */
int	ft_init(t_data *data, int ac, char **av, char **env)
{
	(void)av;
	if (ac > 1)
	{
		ft_putstr_fd("The program no needs any argument\n", 2);
		return (1);
	}
	print_header();
	data->env_copy = NULL;
	ft_get_env_cpy(data, env);
	return (0);
}

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
	t_data	data;
	char	*usr_input;

	(void)ac;
	(void)av;
	if (ft_init(&data, ac, av, env) == 1)
		return (0);
	while (1)
	{
		signal(SIGINT, handle_sigint);
		usr_input = readline("\033[1;31mMiniHell: \033[0m");
		if (check_builtin(usr_input) == 0)
			ft_error(usr_input, CMND_NOT_FOUND);
		if (!ft_strncmp("exit", usr_input, 5))
			break ;
		else
		{
			add_history(usr_input);
			exec_builtin(&data, usr_input);
		}
		free(usr_input);
	}
	print_exit();
	return (0);
}
