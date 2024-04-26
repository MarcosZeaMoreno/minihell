/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:28:23 by vkatason          #+#    #+#             */
/*   Updated: 2024/04/24 11:49:25 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief 		Function to delete one node of the list
 * 
 * @param lst: 	a pointer to the list.
 * @param del: 	a pointer to the function that delete the value.
 */
void	lst_delone(t_env *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->value);
		free (lst);
	}
}

/**
 * @brief 		Function clear a list
 * 
 * @param lst: 	a pointer to the list.
 * @param del: 	a pointer to the function that delete the value.
 */
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
