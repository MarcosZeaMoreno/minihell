/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:48 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/22 15:50:59 by vkatason         ###   ########.fr       */
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
	bool	in_single;
	bool	in_double;
	char	*var_name;
	int		i;

	in_single = false;
	in_double = false;
	while (*str)
	{
		if (*str == '\"')
			in_double = !in_double;
		else if (*str == '\'')
			in_single = !in_single;
		if ((*str == '$' && !in_single)
			|| (*str == '$' && in_single && in_double))
		{
			str++;
			i = 0;
			while (ft_isalnum(str[i]) == 1 || str[i] == '_')
				i++;
			var_name = (char *)calloc(i + 1, sizeof(char));
			ft_strncpy(var_name, str, i);
			return (var_name);
		}
		str++;
	}
	return (NULL);
}
