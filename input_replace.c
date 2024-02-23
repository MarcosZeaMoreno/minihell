/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:13:29 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/22 18:03:22 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function returns the new size of the user input string after
 * replacing the variable name with the variable value
 * 
 * @param str - user input string
 * @param old_value - variable name
 * @param new_value - variable value
 * @return int size of the new string
 */
static int	ft_get_new_size(char *str, char *old_value, char *new_value)
{
	int	count;
	int	len_old;
	int	len_str;

	len_old = ft_strlen(old_value);
	len_str = ft_strlen(str);
	count = 0;
	str = ft_strstr(str, old_value);
	while (str != NULL)
	{
		count++;
		str += len_old;
		str = ft_strstr(str, old_value);
	}
	if (count == 0)
		return (len_str);
	else
		return ((len_str - (count * len_old)) + (count * ft_strlen(new_value)));
}

/**
 * @brief a new string with a dollar sign ($) prepended to the given value
 * 
 * @param value The value to prepend with a dollar sign
 * @return The newly created string with the dollar sign prepended
 */
static char	*create_dollar_value(char *value)
{
	char	*dollar_value;

	dollar_value = (char *)malloc(sizeof(char) * (strlen(value) + 2));
	ft_strcpy(dollar_value, "$");
	ft_strcat(dollar_value, value);
	return (dollar_value);
}

/**
 * @brief Copies the value of an environment variable to a new string
 *
 * @param new_str The pointer to the new string where the value will be copied
 * @param cpy The pointer to the original string where 
 * the dollar value is located
 * @param dollar_value The dollar value to be replaced.
 * @param new_value The value of the environment variable to be copied.
 */
static void	copy_env_value(char **new_str, char **cpy, char *dollar_value,
		char *env_value)
{
	ft_strcpy(*new_str, env_value);
	*new_str += ft_strlen(env_value);
	*cpy += ft_strlen(dollar_value);
}

/**
 * @brief Replaces the variable name with the variable value
 * 
 * @param str - user input string
 * @param old_value - variable name
 * @param new_value - variable value
 */
void	ft_replace_input(char **str, char *old_value, char *new_value)
{
	char	*new_str;
	char	*dollar_value;
	char	*start;
	char	*cpy;

	dollar_value = create_dollar_value(old_value);
	new_str = (char *)malloc(sizeof(char) * (ft_get_new_size(*str, dollar_value,
					new_value) + 1));
	start = new_str;
	cpy = *str;
	while (*cpy)
	{
		if (ft_strncmp(cpy, dollar_value, strlen(dollar_value)) == 0)
			copy_env_value(&new_str, &cpy, dollar_value, new_value);
		else
			*new_str++ = *cpy++;
	}
	*new_str = '\0';
	free(*str);
	*str = start;
	free(dollar_value);
}
