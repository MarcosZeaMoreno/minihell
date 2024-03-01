/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:32:11 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/01 12:31:37 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Debug helping function to print the result
 * of variable check for the user input string.
 * 
 * @param usr_input
 * @param data
 * @var var_list The list of variables found in the user input string
 * @var tmp The pointer to the current node in the list
 * @var var_name The structure that holds the variable name
 * and its position in the string
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
		result = ft_check_vars(tmp, data);
		if (result == 1)
			ft_printf("Variable check passed for %s.\n", var_name->name);
		else if (result == -1)
			ft_printf("Undefined variable found: %s.\n", var_name->name);
		tmp = tmp->next;
	}
	if (var_list != NULL)
		ft_free_var_list(var_list);
}

/**
 * @brief This function prints the variables from the list
 * of expandable variables found in the user input string.
 * 
 * @param vars 
 * @var current The pointer to the list that tracks
 * current node in the list
 * @var var The structure that holds the variable name
 */
void	ft_print_vars(t_list *vars)
{
	t_list		*current;
	t_var_name	*var;

	current = vars;
	while (current != NULL)
	{
		var = (t_var_name *)current->content;
		ft_printf("Variable: %s\n", var->name);
		ft_printf("Start: %d\n", var->start);
		ft_printf("End: %d\n", var->end);
		current = current->next;
	}
	ft_printf("-------- End of variable list --------\n");
	ft_free_var_list(vars);
}

/**
 * @brief Function to print the variables from the env_copy list
 * @var tmp The pointer to the current node in the list
 * @param data Main data structure
 */
void	print_env_vars(t_data *data)
{
	t_env	*tmp;

	tmp = data->env_copy;
	while (tmp != NULL)
	{
		ft_printf("Key: %s, Value: %s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
