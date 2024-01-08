/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:45:41 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/08 16:54:18 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Inits main data structure
 * 
 */
void	ft_data_init(t_data *data)
{
	data->env_copy = NULL;
	data->env_copy->key = NULL;
	data->env_copy->value = NULL;
	data->env_copy->next = NULL;
}

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
//	t_data	data;
	char	*usr_input;
	//char	*env_copy;

	(void)ac;
	(void)av;
	(void)env;
//ft_data_init(&data);
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
