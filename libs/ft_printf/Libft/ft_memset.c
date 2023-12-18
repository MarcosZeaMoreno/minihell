/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:59:23 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/09/23 11:57:38 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Memset -- fill a byte string with a byte value
* The memset() function writes len bytes of value c 
(converted to an unsigned char) to the string b.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
