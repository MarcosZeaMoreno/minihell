/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns_to_cmds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:56:09 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/19 18:57:07 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tkns_to_cmd(t_data *data)
{
	t_tkn_lst	*tkns;
	t_cmd		*tmp;

	ft_tkns_error_exit(data);
	tkns = data->tkns;
	tmp = ft_init_cmd();
	while (tkns != NULL)
	{
		if (tkns->tkn->e_type == TKN_PIPE)
		{
			ft_cmd_pipe(tkns, data);
			tmp = ft_fill_cmd(tmp, tkns, tkns->tkn->order);
			ft_lstadd_back_cmd(&data->cmd, tmp);
			tmp = ft_init_cmd();
		}
		tkns = tkns->next;
	}
}

void	ft_tkns_error_exit(t_data *data)
{
	t_tkn_lst	*tkns;

	tkns = data->tkns;
	while (tkns != NULL)
	{
		if (tkns->tkn->e_type == TKN_ERROR)
		{
			ft_error(tkns->tkn->value, 14);
			data->exit_status = 258;
			return ;
		}
		tkns = tkns->next;
	}
}

void	ft_cmd_pipe(t_tkn_lst *tkns, t_data *data)
{
	if (tkns->tkn->e_type == TKN_PIPE)
	{
		if (tkns->prev == NULL || tkns->next == NULL)
		{
			ft_error(tkns->tkn->value, 13);
			data->exit_status = 258;
			return ;
		}
	}
}

t_cmd	*ft_fill_cmd(t_cmd *cmd, t_tkn_lst *tkns, int pos)
{
	int			i;
	int			arg_count;
	t_tkn_lst	*tmp;

	tmp = tkns;
	i = 1;
	while
	return (cmd);
}