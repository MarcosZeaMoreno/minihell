/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:16:47 by mzea-mor          #+#    #+#             */
/*   Updated: 2023/09/13 12:11:04 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 The memcpy() function copies n bytes from memory area
 src to memory area dst.  If dst and src
 overlap, behavior is undefined.
 Applications in which dst and src might overlap should use
 memmove(3) instead.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}
/*
int main(void)
{
    char    str[] = "patata";
	char	str1[] = "";

    printf("-%s <---- Destino\n",str1);
    ft_memcpy(str1, str, 3);
    printf("-%s <---- Resultado destino\n",str1);
}*/
