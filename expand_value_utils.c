/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_value_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:48 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/24 19:02:00 by vkatason         ###   ########.fr       */
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
 * @brief Function to extract the expandable variable 
 * name from the user input.
 * 
 * @param usr_input User input string
 * @param data Main data structure
 * @return char* The name of the expandable variable
 */
char	*ft_var_name(char *usr_input)
{
	int				i;
	int				status[2];
	char			*var_name;
	static int		pos;

	status[0] = 0;
	status[1] = 0;
	i = pos;
	while (usr_input[i])
	{
		ft_toggle_status(usr_input, i, status);
		if (ft_is_expandable(usr_input[i], status))
		{
			pos = i;
			var_name = ft_get_expandable_name(usr_input, &i);
			pos = i;
			return (var_name);
		}
		i++;
	}
	pos = 0;
	return ((void *)0);
}
