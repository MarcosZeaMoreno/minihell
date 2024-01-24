/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:13:29 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/24 18:48:55 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief The function calculates the new size 
 * of a string after replacing occurrences of 
 * a value with another env_value.
 *
 * @param usr_input The user input string.
 * @param value The value to be replaced (variable name).
 * @param env_value The replacement value (variable value).
 * @return The new size of the string after replacement.
 */
static int	ft_get_new_size(char *usr_input, char *value, char *env_value)
{
	int	count;
	int	len_old;
	int	len_str;

	len_old = ft_strlen(value);
	len_str = ft_strlen(usr_input);
	count = 0;
	usr_input = ft_strstr(usr_input, value);
	while (usr_input != NULL)
	{
		count++;
		usr_input += len_old;
		usr_input = ft_strstr(usr_input, value);
	}
	if (count == 0)
		return (len_str);
	else
		return ((len_str - (count * len_old)) + (count * ft_strlen(env_value)));
}

static char	*create_dollar_value(char *value)
{
	char	*dollar_value;

	dollar_value = (char *)malloc(sizeof(char) * (strlen(value) + 2));
	ft_strcpy(dollar_value, "$");
	ft_strcat(dollar_value, value);
	return (dollar_value);
}

static void	copy_env_value(char **new_str, char **cpy, char *dollar_value,
		char *env_value)
{
	ft_strcpy(*new_str, env_value);
	*new_str += ft_strlen(env_value);
	*cpy += ft_strlen(dollar_value);
}

/**
 * @brief Function replaces occurrences of a variable name in 
 * the user input with an variable value.
 *
 * @param usr_input The address of a pointer to the user input string.
 * @param value The value to be replaced in the user input (variable name).
 * @param env_value The variable value to replace the occurrences with.
 */
void	ft_replace_input(char **usr_input, char *value, char *env_value)
{
	char	*new_str;
	char	*dollar_value;
	char	*start;
	char	*cpy;

	dollar_value = create_dollar_value(value);
	new_str = (char *)malloc(sizeof(char) * (ft_get_new_size(*usr_input,
					dollar_value, env_value) + 1));
	start = new_str;
	cpy = *usr_input;
	while (*cpy)
	{
		if (ft_strncmp(cpy, dollar_value, strlen(dollar_value)) == 0)
			copy_env_value(&new_str, &cpy, dollar_value, env_value);
		else
			*new_str++ = *cpy++;
	}
	*new_str = '\0';
	free(*usr_input);
	*usr_input = start;
	free(dollar_value);
}
