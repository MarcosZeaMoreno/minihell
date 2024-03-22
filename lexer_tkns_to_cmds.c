/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns_to_cmds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:56:09 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/22 19:06:31 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tkns_to_cmds(t_data *data)
{
	t_cmd		*tmp;
	t_tkn_lst	*tkn_lst;
	t_tkn		*tkn;
	int			last_tkn;

	tkn_lst = data->tkns;
	ft_print_tkn_lst(data);
	last_tkn = ft_tkn_lst_last(tkn_lst);
	tmp = ft_init_cmd();
	data->cmd = tmp;
	if (ft_tkns_error_exit(data) == 1)
		return ;
	while (tkn_lst)
	{
		tkn = tkn_lst->tkn;
		if (tkn->e_type == TKN_PIPE)
		{
			if (ft_valid_pipe(tkn_lst, data) == 0)
				return ;
			tmp->next = ft_init_cmd();
			tmp = tmp->next;
			tkn_lst = tkn_lst->next;
		}
		else if (tkn->e_type == TKN_REDIR_IN
			|| tkn->e_type == TKN_REDIR_OUT
			|| tkn->e_type == TKN_REDIR_APPEND
			|| tkn->e_type == TKN_REDIR_HERE_DOC)
		{
			ft_add_redir_to_cmd(data, tmp, &tkn_lst);
			tmp->flag_redir = 1;
		}
		else
			ft_add_arg_to_cmd(tmp, &tkn_lst);
	}
}

void	ft_add_arg_to_cmd(t_cmd *cmd, t_tkn_lst **tkn_lst)
{
	t_tkn_lst	*tkns;
	int			i;

	tkns = *tkn_lst;
	i = 0;
	while (*tkn_lst != NULL && (*tkn_lst)->tkn->e_type != TKN_PIPE
		&& (*tkn_lst)->tkn->e_type != TKN_REDIR_IN
		&& (*tkn_lst)->tkn->e_type != TKN_REDIR_OUT
		&& (*tkn_lst)->tkn->e_type != TKN_REDIR_APPEND
		&& (*tkn_lst)->tkn->e_type != TKN_REDIR_HERE_DOC)
	{
		ft_realloc_args(cmd, ft_strdup((*tkn_lst)->tkn->value));
		printf("FIRST_ARG[%i]: %s\n", i, cmd->args[i]);
		i++;
		*tkn_lst = (*tkn_lst)->next;
	}
}

void	ft_add_redir_to_cmd(t_data *data, t_cmd *cmd, t_tkn_lst **tkns_lst)
{
	t_redirect	*redir;
	t_tkn_lst	*tkns;

	tkns = *tkns_lst;
	if (cmd->redir == NULL)
	{
		cmd->redir = ft_calloc(1, sizeof(t_redirect));
		redir = cmd->redir;
	}
	else
	{
		redir = cmd->redir;
		while (redir->next != NULL)
			redir = redir->next;
		redir->next = ft_calloc(1, sizeof(t_redirect));
		redir = redir->next;
	}
	redir->redir_type = ft_strdup(tkns->tkn->value);
	if (tkns->next == NULL)
	{
		ft_error("newline", 13);
		data->exit_status = 258;
		return ;
	}
	else
		redir->file = ft_strdup(tkns->next->tkn->value);
	*tkns_lst = (*tkns_lst)->next;
	if (*tkns_lst != NULL)
		*tkns_lst = (*tkns_lst)->next;
}

int	ft_tkns_error_exit(t_data *data)
{
	t_tkn_lst	*tkns;

	tkns = data->tkns;
	while (tkns != NULL)
	{
		if (tkns->tkn->e_type == TKN_ERROR)
		{
			ft_error(tkns->tkn->value, 14);
			data->exit_status = 258;
			return (1);
		}
		tkns = tkns->next;
	}
	return (0);
}

int	ft_valid_pipe(t_tkn_lst *tkns, t_data *data)
{
	if (tkns->prev == NULL || tkns->next == NULL)
	{
		ft_error(tkns->tkn->value, 13);
		data->exit_status = 258;
		return (0);
	}
	else
		return (1);
}



