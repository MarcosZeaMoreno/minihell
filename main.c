/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:45:41 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/03/04 00:38:31 by vkatason         ###   ########.fr       */
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
	char	**env_temp;

	(void)av;
	env_temp = strdup_2d(env);
	if (ac > 1)
	{
		ft_putstr_fd("The program no needs any argument\n", 2);
		return (1);
	}
	print_header();
	data->env_copy = NULL;
	data->token = NULL;
	data->input_copy = NULL;
	ft_getpid(data);
	ft_get_env_cpy(data, env_temp);
	return (0);
}

/**
 * @brief Function to get promp
 * 
 * @param data 
 * @param env 
 * @return int 
 */
int	get_promp(t_data *data, char **env)
{
	char	*usr_input;

	if (!data)
		return (-1);
	usr_input = readline("\033[1;31mMiniHell: \033[0m");
	if (usr_input == NULL)
	{
		ft_printf("exit\n");
		return (1);
	}
	add_history(usr_input);
	ft_is_input_error(usr_input);
	ft_print_vars(ft_fill_values(usr_input, data));
	ft_fill_values(usr_input, data);
	ft_parse_input(data, usr_input);
	if (data->token && check_builtin(data->token) == 0)
		check_execve(data, env, data->env_copy);
	if (data->token && data->token->value && !ft_strncmp("exit",
			data->token->value, 5))
		return (1);
	else
		exec_builtin(data, data->token);
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
		suppress_output();
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		if (get_promp(&data, env) == 1)
			break ;
	}
	print_exit();
	return (0);
}
