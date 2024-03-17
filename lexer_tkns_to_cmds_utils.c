/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns_to_cmds_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:56:18 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/16 23:09:20 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Function that initializes a command structure.
 * @var cmd The command structure.
 * @return t_cmd* The command structure.
 */
t_cmd	*ft_init_cmd(void)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (cmd == NULL)
	{
		ft_putstr_fd("Error: Failed to allocate memory for command\n", 2);
		exit(EXIT_FAILURE);
	}
	cmd->args = NULL;
	cmd->flag_redir = 0;
	cmd->fd[0] = 0;
	cmd->fd[1] = 1;
	cmd->redir = NULL;
	cmd->redir_count[0] = 0;
	cmd->redir_count[1] = 0;
	cmd->save = 0;
	cmd->next = NULL;
	return (cmd);
}

/**
 * @brief Function that frees the command structure.
 * 
 * @var current Pointer to the current command structure.
 * @var next Pointer to the next command structure.
 * @param cmd The command list from data structure.
 */
void	ft_free_cmd(t_cmd *cmd)
{
	t_cmd	*current;
	t_cmd	*next;

	current = cmd;
	while (current != NULL)
	{
		next = current->next;
		if (current->args)
			ft_charpp_free(current->args);
		if (current->redir)
			ft_free_redir(current->redir);
		free(current);
		current = next;
	}
}

/**
 * @brief Function that free a redirect list
 * inside a command structure.
 * 
 * @var current Pointer to the current redirect structure.
 * @var next Pointer to the next redirect structure.
 */
void	ft_free_redir(t_redirect *redir)
{
	t_redirect	*current;
	t_redirect	*next;

	current = redir;
	while (current != NULL)
	{
		next = current->next;
		if (current->file)
			free(current->file);
		if (current->redir_type)
			free(current->redir_type);
		free(current);
		current = next;
	}
}

/**
 * @brief Function that takes the order (node number)
 * of the last token in the token list.
 * 
 * @param tkn_list The head of the token list.
 * @return int The order number.
 */
int	ft_tkn_lst_last(t_tkn_lst *tkn_list)
{
	t_tkn_lst	*current;

	current = tkn_list;
	while (current->next != NULL)
		current = current->next;
	return (current->tkn->order);
}
