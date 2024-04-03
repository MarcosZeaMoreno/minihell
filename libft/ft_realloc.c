/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:55:14 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/29 23:25:47 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!ptr)
		return (malloc(size));
	if (!size)
	{
		if (ptr)
		{
			free(ptr);
			ptr = NULL;
		}
		return (NULL);
	}
	new = malloc(size);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, size);
	free(ptr);
	ptr = NULL;
	return (new);
}
