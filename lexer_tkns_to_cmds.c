/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns_to_cmds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:56:09 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/21 11:39:07 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_tkns_to_cmd(t_data *data)
// {
// 	t_tkn_lst	*tkns;
// 	t_cmd		*new_command;
// 	t_redirect	*new_redir;

// 	tkns = data->tkns;
// 	new_command = ft_init_cmd();
// 	if (ft_tkns_error_exit(data) != 1)
// 	{
// 		while (tkns != NULL)
// 		{
// 			new_command = ft_init_cmd();
// 			while (tkns->tkn->e_type != TKN_PIPE)
// 			{
// 				while (tkns->tkn->e_type != TKN_REDIR_APPEND
// 					|| tkns->tkn->e_type != TKN_REDIR_OUT
// 					|| tkns->tkn->e_type != TKN_REDIR_IN
// 					|| tkns->tkn->e_type != TKN_REDIR_HERE_DOC)
// 				{

					
// 					new_command->redir = ft_init_redir();
					
// 					new_command->flag_redir = 1;
// 					data->cmd->redir = ft_fill_redir(data->cmd->redir, tkns);
// 				}
// 	tkns = tkns->next;
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
// 			}
// 			{
// 				while (tkns->tkn->e_type == TKN_REDIR_APPEND
// 					|| tkns->tkn->e_type == TKN_REDIR_OUT
// 					|| tkns->tkn->e_type == TKN_REDIR_IN
// 					|| tkns->tkn->e_type == TKN_REDIR_HERE_DOC)
// 				{
// 					new_comma
					
// 					data->cmd->flag_redir = 1;
// 					data->cmd->redir = ft_fill_redir(data->cmd->redir, tkns);
// 				}
// 			}
// 			}
// 			if (tkns->tkn->e_type != TKN_PIPE && ft_valid_pipe(tkns, data))
// 			{
// 				new_command = ft_fill_cmd(new_command, tkns);
// 				ft_lstadd_back_cmd(&data->cmd, new_command);
// 				new_command = ft_init_cmd();
// 			}
// 			tkns = tkns->next;
// 		}
// 	}
// }


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



