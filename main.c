/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:45:41 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/08 18:49:30 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Inits main data structure
 * 
 */
void ft_data_init(t_data *data)
{
	data->env_copy = NULL;
}

t_data *ft_get_env_cpy(t_data *data, char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		if (data->env_copy == NULL)
		{
			data->env_copy = malloc(sizeof(t_env));
			data->env_copy->key = ft_strtok(env[i], '=');
			data->env_copy->value = ft_strtok(env[i], '\0');
			data->env_copy->next = NULL;
		}
		else
		{
			ft_lstadd_back(*data->env_copy, ft_lstnew(data->env_copy));
		}
		i++;
	}
	return (data);	
}

void ft_print_env_copy(t_data *data)
{
	t_env *tmp;

	tmp = data->env_copy;
	while (tmp != NULL)
	{
		ft_printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
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
	t_data	data;
	char	*usr_input;
	//char	*envp;

	(void)ac;
	(void)av;
	(void)env;
	ft_data_init(&data);
	print_header();
	ft_get_env_cpy(&data, env);
	ft_print_env_copy(&data);
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
