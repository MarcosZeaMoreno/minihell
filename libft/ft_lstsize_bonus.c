/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:42:11 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/25 14:43:54 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
