/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_value_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:48 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/24 22:15:23 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Toggles the status based on the character in the user input.
 * 
 * @param usr_input user input string
 * @param i index of the character to check
 * @param status status array to toggle based on the character
 * (0) - double quotes
 * (1) - single quotes
 */
static void	ft_toggle_status(char *usr_input, int i, int *status)
{
	if (usr_input[i] == '\"')
		status[0] = (status[0] + 1) % 2;
	if (usr_input[i] == '\'')
		status[1] = (status[1] + 1) % 2;
}

/**
 * @brief Function checks if the character is expandable
 * based on the status of the double and single quotes.
 * 
 * @param c Character to check
 * @param status Integer array of size 2
 * (0) - double quotes
 * (1) - single quotes
 * @return int status of the $ character
 */
static int	ft_is_expandable(char c, int status[2])
{
	return (((c == '$' && (status[0] == 0 && status[1] == 0))
			|| (c == '$' && (status[0] == 1 && status[1] == 1))));
}

/**
 * @brief Function to get the expandable name
 * from the user input.
 * @param usr_input User input string
 * @param i Index of the character to start from
 * @var start Start index of the expandable variable
 * @return char* Name of the expandable variable
 */
static char	*ft_get_expandable_name(char *usr_input, int *i)
{
	int	start;

	start = (*i)++;
	while (usr_input[*i] && (ft_isalnum(usr_input[*i]) || usr_input[*i] == '_'))
		(*i)++;
	return (ft_substr(usr_input, start + 1, *i - start - 1));
}

/**
 * @brief Function to get the name 
 * of the expandable variable from 
 * the user input.
 * 
 * @param usr_input User input string
 * @var status Integer array of size 2
 * (0) - double quotes
 * (1) - single quotes
 * @var i Index of the character to start from
 * @return t_var_name* Structure containing the 
 * name and position of the expandable variable 
 * in the user input.
 */
t_var_name	*ft_var_name(char *usr_input)
{
	int				i;
	int				status[2];
	t_var_name		*result;

	result = malloc(sizeof(t_var_name));
	if (!result)
		return (NULL);

	status[0] = 0;
	status[1] = 0;
	i = 0;
	while (usr_input[i])
	{
		ft_toggle_status(usr_input, i, status);
		if (ft_is_expandable(usr_input[i], status))
		{
			result->name = ft_get_expandable_name(usr_input, &i);
			result->pos = i;
			return (result);
		}
		i++;
	}
	free(result);
	return (NULL);
}
