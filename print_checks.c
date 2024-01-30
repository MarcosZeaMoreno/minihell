/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:24:22 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/30 03:46:50 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Fuction prints the result of ft_rm_quotes
 * as a new string.
 * 
 * @param usr_input 
 */
void	print_rm_quotes(char *usr_input)
{
	char	*input_copy;

	input_copy = ft_strdup(usr_input);
	ft_rm_quotes(&input_copy);
	ft_printf("%s\n", input_copy);
	free(input_copy);
}

/**
 * @brief Function prints the result of ft_var_name:
 * the name of the first variable found in the string.
 * 
 * @param str user input string
 */
void	print_var_name(char *str)
{
	char	*var_name;

	var_name = ft_var_name(str);
	if (var_name != NULL)
	{
		ft_printf("First variable name: %s\n", var_name);
		free(var_name);
	}
	else
		ft_printf("No variable found.\n");
}

/**
 * @brief Function prints the result of ft_var_value:
 * the value of the first variable found in the string
 * is equal to the value of the variable in the environment.
 * 
 * @param str user input string
 */
void	print_var_check_vars(char *usr_input, t_data *data)
{
	int	result;

	result = ft_check_vars(usr_input, data);
	if (result == 1)
		ft_printf("Variable check passed.\n");
	else if (result == -1)
		ft_printf("Undefined variable found.\n");
	else
		ft_printf("Invalid result.\n");
}

/**
 * @brief Function prints the original user input
 * and the result of ft_clean_input: the user input
 * with replaced variables.
 * 
 * @param str user input string
 */
void	print_replaced_input(char *usr_input, t_data *data)
{
	if (usr_input != NULL)
	{
		ft_printf("Original input: %s\n", usr_input);
		ft_clean_input(&usr_input, data);
		ft_printf("Replaced input: %s\n", usr_input);
	}
	else
		ft_printf("No input.\n");
}

/**
 * @brief Function prints tokens from the user input
 * with the type and value of each token
 * (see enum e_tkn_type in lexer.h)
 * 
 * @param str user input string
 */
void	print_tkn(t_tkn *tkn)
{
	const char	*tkn_types[] = {
		"TKN_WHITESPACE",
		"TKN_SEMICOLON",
		"TKN_PIPE",
		"TKN_DOUBLE_PIPE",
		"TKN_REDIR_IN",
		"TKN_REDIR_OUT",
		"TKN_REDIR_APPEND",
		"TKN_REDIR_HERE_DOC",
		"TKN_DOLLAR",
		"TKN_AMPER",
		"TKN_DOUBLE_AMPER",
		"TKN_TILDE",
		"TKN_SNGL_QUOTE",
		"TKN_WORD",
		"TKN_STRING"};

	ft_printf("TKN#%d\n", tkn->order);
	ft_printf("TYPE: %s\n", tkn_types[tkn->e_type]);
	ft_printf("VALUE: %s\n\n", tkn->value);
}

