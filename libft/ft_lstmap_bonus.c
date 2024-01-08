/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:00:51 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/25 19:45:47 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;

	if (!lst && !f)
		return (NULL);
	newlist = 0;
	while (lst)
	{
		newnode = ft_lstnew (0);
		if (!newnode)
		{
			ft_lstclear (&newlist, del);
			return (NULL);
		}
		newnode->content = f(lst->content);
		ft_lstadd_back(&newlist, newnode);
		lst = lst -> next;
	}
	return (newlist);
}
