/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:28:23 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/18 21:06:27 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_delone(t_env *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->value);
		free (lst);
	}
}

void	lst_delone_token(t_token *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->value);
		free (lst);
	}
}

void	lst_clear(t_env **lst, void (*del)(void *))
{
	t_env	*tmp;

	if (lst != 0 && *lst != 0)
	{
		while (*lst != 0)
		{
			tmp = (*lst)->next;
			lst_delone(*lst, del);
			*lst = tmp;
		}
	}
}

void	lst_clear_token(t_token **lst, void (*del)(void *))
{
	t_token	*tmp;

	if (lst != 0 && *lst != 0)
	{
		while (*lst != 0)
		{
			tmp = (*lst)->next;
			lst_delone_token(*lst, del);
			*lst = tmp;
		}
	}
}
