/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:40:47 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/19 03:21:13 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function calculates the number of characters 
 * to remove from the string in order to properly 
 * handle the escape sequences. The function iterates 
 * through each character in the input string 
 * and checks if it is part of an escape sequence. 
 * If the input string contains the escape sequence 
 * \", which represents a double quote character, 
 * it correctly identifies this escape sequence 
 * and returns the count of 2, indicating that two 
 * characters (\ and ") need to be removed 
 * in order to properly handle the escape sequence.
 * 
 * @param str input string
 * @return int number of characters to remove
 */
// static int	ft_num_chars_to_rm(char *str)
// {
// 	int		i;
// 	char	prev_symbol;

// 	i = 0;
// 	prev_symbol = '\0';
// 	while (*str)
// 	{
// 		if (*str == '\\' && prev_symbol != '\\')
// 			i++;
// 		else if (*str == '\\' && prev_symbol == '\\')
// 		{
// 			prev_symbol = '\0';
// 			str++;
// 			continue ;
// 		}
// 		else if ((*str == '\'' || *str == '"') && prev_symbol != '\\')
// 			i++;
// 		prev_symbol = *str;
// 		str++;
// 	}
// 	return (i);
// }

/**
 * @brief Retrieves the name of a variable 
 * from a string. The function searches 
 * for a variable in the given string, 
 * indicated by a '$' symbol,
 * and returns the name of the variable. 
 * The variable name is expected to consist of
 * alphanumeric characters only.
 *
 * @param str The string to search for the variable.
 * @return The name of the variable, or NULL if no variable is found.
 */
static char	*ft_var_name(char *str)
{
	char	*value;
	int		i;

	while (*str)
	{
		if (*str == '$')
		{
			str++;
			i = 0;
			while (ft_isalnum(str[i]) == 1)
				i++;
			value = (char *)calloc(i + 1, sizeof(char));
			ft_strncpy(value, str, i);
			return (value);
		}
		str++;
	}
	return (NULL);
}

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

typedef struct s_var
{
	char			*name;
	struct s_var	*next;
}					t_var;

static t_var	*ft_var_name_list(char *str)
{
	t_var *head = NULL;
	t_var *tail = NULL;

	while (*str)
	{
		if (*str == '$')
		{
			str++;
			int i = 0;
			while (ft_isalnum(str[i]) == 1)
				i++;
			char *value = (char *)calloc(i + 1, sizeof(char));
			strncpy(value, str, i);

			t_var *new_var = (t_var *)malloc(sizeof(t_var));
			new_var->name = value;
			new_var->next = NULL;

			if (head == NULL)
			{
				head = new_var;
				tail = new_var;
			}
			else
			{
				tail->next = new_var;
				tail = new_var;
			}

			str += i - 1; // Move to the end of the current variable
		}
		str++;
	}
	return (head);
}

void	print_var_list(char *input)
{
	t_var	*var_list;
	t_var	*current;
	t_var	*next;
	int		i;

	i = 1;
	var_list = ft_var_name_list(input);
	current = var_list;
	while (current != NULL)
	{
		ft_printf("Variable %d: ", i);
		if (current->name != NULL)
			ft_printf("%s\n", current->name);
	current = current->next;
	i++;
	}
	while (var_list != NULL)
	{
		next = var_list->next;
		free(var_list->name);
		free(var_list);
		var_list = next;
	}
}
