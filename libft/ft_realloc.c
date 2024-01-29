/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:55:14 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/29 00:12:38 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_allocate_memory(size_t size)
{
	size_t	*ptr;

	ptr = malloc(size + sizeof(size_t));
	if (ptr == NULL)
	{
		return (NULL);
	}
	*ptr = size;
	return (ptr + 1);
}

size_t	get_min_size(size_t old_size, size_t size)
{
	size_t	min_size;

	if (old_size < size)
	{
		min_size = old_size;
	}
	else
	{
		min_size = size;
	}
	return (min_size);
}

void	*ft_realloc(void *ptr, size_t size)
{
	size_t	old_size;
	void	*new_ptr;
	size_t	min_size;

	if (ptr == NULL)
	{
		return (ft_allocate_memory(size));
	}
	if (size == 0)
	{
		free((size_t *)ptr - 1);
		return (NULL);
	}
	old_size = *((size_t *)ptr - 1);
	new_ptr = ft_allocate_memory(size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}
	min_size = get_min_size(old_size, size);
	ft_memcpy(new_ptr, ptr, min_size);
	free((size_t *)ptr - 1);
	return (new_ptr);
}
