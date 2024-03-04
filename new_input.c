/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:41:44 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/04 15:36:59 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function to check if 
 * the first characters in 
 * the string are spaces
 * 
 * @param str The string to check
 * @var i Position counter 
 * @return int Index of the first non-space character
 */
static int	ft_skip_first_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' '))
		i++;
	return (i);
}

static char	*ft_get_input_chunck(char *usr_input, int start, int end)
{
	char	*input_chunk;
	int		i;

	i = 0;
	input_chunk = (char *)malloc(sizeof(char) * (end - start + 1));
	while (start < end)
	{
		input_chunk[i] = usr_input[start];
		i++;
		start++;
	}
	input_chunk[i] = '\0';
	return (input_chunk);
}

void	ft_get_new_input(char *usr_input, t_data *data)
{
	int			i;
	t_list		*var_list;
	t_list		*tmp;
	t_var_name	*var;
	char		*input_chunk;

	i = ft_skip_first_spaces(usr_input);
	var_list = ft_fill_values(usr_input, data);
	tmp = var_list;
	data->input_copy = ft_strdup("");

	while (tmp != NULL && usr_input[i] != '\0')
	{
		var = (t_var_name *)tmp->content;
		if (i != var->start)
		{
			input_chunk = ft_get_input_chunck(usr_input, i, var->start);
			data->input_copy = ft_strjoin(data->input_copy, input_chunk);
			i = var->start;
			free(input_chunk);
		}
		if (i == var->start || tmp->next == NULL)
		{
			if (var->value != NULL)
			{
				data->input_copy = ft_strjoin(data->input_copy, var->value);
				i = var->end + 1;
			}
			else
			{
				input_chunk = ft_strdup("");
				data->input_copy = ft_strjoin(data->input_copy, input_chunk);
				i = var->end + 1;
				free(input_chunk);
			}
		}
		tmp = tmp->next;
	}
	if (usr_input[i] != '\0')
	{
		input_chunk = ft_get_input_chunck(usr_input, i, ft_strlen(usr_input));
		data->input_copy = ft_strjoin(data->input_copy, input_chunk);
		free(input_chunk);
	}
	ft_free_var_list(var_list);
}
