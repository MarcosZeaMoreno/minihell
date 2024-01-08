/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:20:09 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/20 17:34:37 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof (t_list));
	if (!lst)
		return (0);
	lst -> content = (void *) content;
	lst -> next = NULL;
	return (lst);
}
