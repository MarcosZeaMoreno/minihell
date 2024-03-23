/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:45:41 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/03/23 20:30:44 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to get enviroment copy
 * 
 * @param data: a pointer to the data structure.
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
	data->input_copy = NULL;
	data->exit_status = 0;
	data->tkns = NULL;
	data->cmd = NULL;
	data->fd[1] = dup(1);
	data->fd[0] = dup(0);
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
int	get_prompt(t_data *data)
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
	ft_parser(usr_input, data);
	ft_print_cmds(data);
	if (data->cmd)
		execute_pipeline(data);
	if (data->cmd && data->cmd->args && !ft_strncmp("exit",
			data->cmd->args[0], 5) && data->cmd->args[1] == NULL)
		return (1);
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
		if (get_prompt(&data) == 1)
			break ;
	}
	print_exit();
	return (0);
}
