/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:32:11 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/28 20:42:16 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// /**
//  * @brief Function to print the result of the 
//  * variable check ft_check_vars. 
//  * 
//  * @param usr_input User input string
//  * @param data Main data structure
//  */
// void	print_var_check_vars(char *usr_input, t_data *data)
// {
// 	t_var_name	*var_name;
// 	int			result;

// 	var_name = ft_var_name(usr_input);
// 	while (var_name != NULL)
// 	{
// 		result = ft_check_vars(var_name->name, data);
// 		if (result == 1)
// 			ft_printf("Variable check passed.\n");
// 		else if (result == -1)
// 			ft_printf("Undefined variable found.\n");
// 		else
// 			ft_printf("Invalid result.\n");
// 		usr_input += var_name->pos;
// 		free(var_name->name);
// 		free(var_name);
// 		var_name = ft_var_name(usr_input);
// 	}
// }

// /**
//  * @brief Function to print the names 
//  * of the expandable variables in the user input.
//  * 
//  * @param usr_input User input string
//  * @param data Main data structure
//  */
// void	print_var_names(char *usr_input)
// {
// 	t_var_name	*var_name;

// 	var_name = ft_var_name(usr_input);
// 	while (var_name != NULL)
// 	{
// 		if (getenv(var_name->name) != NULL)
// 		{
// 			ft_printf("Expandable and existing variable name: %s\n",
// 				var_name->name);
// 		}
// 		usr_input += var_name->pos;
// 		free(var_name->name);
// 		free(var_name);
// 		var_name = ft_var_name(usr_input);
// 	}
// }

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
}

