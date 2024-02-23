/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:40:47 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/23 13:45:25 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
char	*ft_var_name(char *str)
{
	char	*value;
	int		i;

	while (*str)
	{
		if (*str == '$')
		{
			str++;
			i = 0;
			while (ft_isalnum(str[i]) == 1 || str[i] == '_')
				i++;
			value = (char *)calloc(i + 1, sizeof(char));
			ft_strncpy(value, str, i);
			return (value);
		}
		str++;
	}
	return (NULL);
}

/**
 * @brief Function checks if the variable exists in the env_copy list
 * 
 * @param usr_input string to check
 * @param data main data structure
 * @return int 1 if the variable exists, -1 if not
 */
int	ft_check_vars(char *usr_input, t_data *data)
{
	char	*value;
	char	*env_value;

	value = ft_var_name(usr_input);
	while (value != NULL)
	{
		env_value = get_env_value(data->env_copy, value);
		if (env_value == NULL)
		{
			ft_printf_fd(2, "%s: Variable is undefined.\n", value);
			free(value);
			return (-1);
		}
		usr_input = ft_strchr(usr_input, '$');
		if (usr_input != NULL)
			usr_input += 1;
		free(value);
		value = ft_var_name(usr_input);
	}
	return (1);
}

int	ft_clean_input(char **usr_input, t_data *data)
{
	char	*value;
	char	*env_value;

	if (ft_strchr(*usr_input, '$') == NULL)
		return (1);
	if (ft_check_vars(*usr_input, data) == -1)
		return (-1);
	while (ft_strchr(*usr_input, '$') != NULL)
	{
		value = ft_var_name(*usr_input);
		env_value = get_env_value(data->env_copy, value);
		if (env_value == NULL)
		{
			ft_printf_fd(2, "%s: Variable is undefined.\n", value + 1);
			free(value);
			return (-1);
		}
		ft_replace_input(usr_input, value, env_value);
		free(value);
	}
	return (1);
}
