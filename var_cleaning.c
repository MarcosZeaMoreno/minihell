/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_cleaning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:31:17 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/01 14:10:19 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_var_list(t_list *vars)
{
	t_list		*current;
	t_list		*next;
	t_var_name	*var;

	current = vars;
	while (current != NULL)
	{
		var = (t_var_name *)current->content;
		free(var->name);
		free(var->value);
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
}
