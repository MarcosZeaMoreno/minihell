/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:45:41 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/11 14:50:05 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Inits main data structure
 * 
 */
void	ft_data_init(t_data *data)
{
	char	*cwd;
	char	buffer[4096 + 1];

	cwd = getcwd(buffer, 4096);
	data->cwd = cwd;
	data->env_copy = NULL;
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
	ft_data_init(&data);
	print_header();
	ft_get_env_cpy(&data, env);
	// ft_env(data.env_copy);
	while (1)
	{
		print_entry();
		signal(SIGINT, handle_sigint);
		usr_input = readline(" ");
		if (check_builtin(usr_input) == 0)
		{
			print_entry();
			ft_printf(" %s: command not found\n", usr_input);
		}
		if (!ft_strncmp("exit", usr_input, 5))
			break ;
		else
			exec_builtin(&data, usr_input);
	}
	print_exit();
	return (0);
}
