/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:26:15 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/10/03 11:55:53 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if ((count == SIZE_MAX && size > 1) || (size == SIZE_MAX && count > 1))
		return (0);
	if (!ptr)
		return (0);
	ft_bzero(ptr, size * count);
	return (ptr);
}
