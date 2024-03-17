/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns_to_cmds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:56:09 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/17 21:03:54 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_tkns_to_cmd(t_data *data)
// {
// 	t_tkn_lst	*tkns;
// 	t_cmd		*cmd;
// 	int			last_tkn;

// 	ft_tkns_error_exit(data);
// 	tkns = data->tkns;
// 	cmd = data->cmd;
// 	last_tkn = ft_tkn_lst_last(tkns);
// 	while (tkns != NULL) 
// 	{
// 		while (tkns->tkn->e_type != TKN_PIPE)
// 		{
// 			while (tkns->tkn->e_type != TKN_REDIR_IN
// 				&& tkns->tkn->e_type != TKN_REDIR_OUT
// 				&& tkns->tkn->e_type != TKN_REDIR_APPEND
// 				&& tkns->tkn->e_type != TKN_REDIR_HERE_DOC)
// 			{
				
// 			}
// 			{
// 				tkns = tkns->next;
// 			}
// 		}
		
// 		{
// 			if (tkns->tkn->order == last_tkn
// 				|| (tkns->prev == NULL || tkns->next == NULL))
// 			{
// 				ft_error(tkns->tkn->value, 13);
// 				data->exit_status = 258;
// 				return ;
// 			}
// 		}
// 		tkns = tkns->next;
// 	}
// }

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
