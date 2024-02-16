/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_names_extract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:37:36 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/16 20:15:45 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_valid_var(char *str)
{
	if (ft_isalpha(*str) || *str == '_')
	{
		while (ft_isalnum(*str) || *str == '_')
			str++;
		return (1);
	}
	return (0);
}

static char	**ft_realloc_values(char **values, int count)
{
	values = (char **)realloc(values, (count + 1) * sizeof(char *));
	if (!values)
		return (NULL);
	return (values);
}

static char	**ft_add_var_to_values(char **values, char *usr_input, int *count)
{
	int		i;

	i = 0;
	while (ft_isalnum(usr_input[i]) || usr_input[i] == '_')
		i++;
	values = ft_realloc_values(values, *count);
	if (!values)
		return (NULL);
	values[*count] = (char *)calloc(i + 1, sizeof(char));
	ft_strncpy(values[*count], usr_input, i);
	(*count)++;
	return (values);
}

char	**ft_all_var_names(char **usr_input)
{
	char	**values;
	int		in_single_quotes;
	int		values_count;

	in_single_quotes = 0;
	values_count = 0;
	values = NULL;
	while (**usr_input)
	{
		if (**usr_input == '\'')
			in_single_quotes = !in_single_quotes;
		if (**usr_input == '$' && !in_single_quotes)
		{
			(*usr_input)++;
			if (ft_is_valid_var(*usr_input))
				values = ft_add_var_to_values(values, *usr_input, &values_count);
		}
		(*usr_input)++;
	}
	values = ft_realloc_values(values, values_count);
	values[values_count] = NULL;
	return (values);
}