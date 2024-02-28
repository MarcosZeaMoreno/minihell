/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:32:11 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/28 21:13:11 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to print the result of the 
 * variable check ft_check_vars. 
 * 
 * @param usr_input User input string
 * @param data Main data structure
 */
void	print_var_check_vars(char *usr_input, t_data *data)
{
	t_list		*var_list;
	t_list		*tmp;
	t_var_name	*var_name;
	int			result;

	var_list = ft_var_name(usr_input);
	tmp = var_list;
	while (tmp != NULL)
	{
		var_name = (t_var_name *)tmp->content;
		result = ft_check_vars(var_name->name, data);
		if (result == 1)
			ft_printf("Variable check passed for %s.\n", var_name->name);
		else if (result == -1)
			ft_printf("Undefined variable found: %s.\n", var_name->name);
		else
			ft_printf("Invalid result for %s.\n", var_name->name);
		tmp = tmp->next;
	}
	ft_free_var_list(var_list);
}

/**
 * @brief Function to print the list of variables and their members.
 * 
 * @param vars List of variables
 * @var current Current node of the list
 * @var var Structure containing the name and position of the variable
 */
void	ft_print_vars(t_list *vars)
{
	t_list		*current;
	t_var_name	*var;

	current = vars;
	while (current != NULL)
	{
		var = (t_var_name *)current->content;
		printf("Variable: %.*s\n", var->end - var->start + 1, var->name);
		printf("Start: %d\n", var->start);
		printf("End: %d\n", var->end);
		current = current->next;
	}
	ft_free_var_list(vars);
}

