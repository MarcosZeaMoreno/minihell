/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns_to_cmds_lsts.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:44:43 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/22 19:08:07 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cmd_add_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_cmd_last(*lst);
	last->next = new;
}

t_cmd	*ft_cmd_last(t_cmd *lst)
{
	t_cmd	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_realloc_args(t_cmd *cmd, char *new_arg)
{
	char	**new_args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cmd->args != NULL && cmd->args[i] != NULL)
		i++;
	new_args = malloc((i + 2) * sizeof(char *));
	if (new_args == NULL)
	{
		free(new_arg);
		return ;
	}
	while (j < i)
	{
		new_args[j] = cmd->args[j];
		j++;
	}
	new_args[i] = new_arg;
	new_args[i + 1] = NULL;
	free(cmd->args);
	cmd->args = new_args;
}
