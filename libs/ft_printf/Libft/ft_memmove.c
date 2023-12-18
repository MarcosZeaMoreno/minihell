/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:46:36 by mzea-mor          #+#    #+#             */
/*   Updated: 2023/09/13 12:11:10 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!len || src == dst)
		return (dst);
	if (dst > src)
	{
		while (len--)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
/*
int main(void)
{
    char    str[] = "patata";
    char    str1[] = "";

    printf("-%s <---- Destino\n",str1);
    ft_memmove(str1, str, 6);
    printf("-%s <---- Resultado destino\n",str1);
}*/
