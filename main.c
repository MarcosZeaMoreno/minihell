/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:45:41 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/18 18:18:40 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to get pid
 * 
 * @param sig 
 */
void	ft_getpid(t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putstr_fd("Error in fork\n", 2);
		exit(1);
	}
	if (!pid)
		exit(1);
	waitpid(pid, NULL, 0);
	data->pid = pid - 1;
}

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
	data->token = NULL;
	ft_getpid(data);
	ft_get_env_cpy(data, env);
	return (0);
}

int	get_promp(t_data *data, char **env)
{
	char	*usr_input;

	usr_input = readline("\033[1;31mMiniHell: \033[0m");
	ft_parse_input(data, usr_input);
	if (check_builtin(data->token, env) == 0)
		ft_error(usr_input, CMND_NOT_FOUND);
	if (!ft_strncmp("exit", data->token->value, 5))
		return (1);
	else
	{
		add_history(usr_input);
		exec_builtin(data, data->token);
	}
	free(usr_input);
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

	if (ft_init(&data, ac, av, env) == 1)
		return (0);
	while (1)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		if (get_promp(&data, env) == 1)
			break ;
	}
	print_exit();
	return (0);
}
