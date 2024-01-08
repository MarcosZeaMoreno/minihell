/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:01:46 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/16 20:00:25 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	if (src < dst)
		while (len--)
			d[len] = s[len];
	else
		while (len--)
			*d++ = *s++;
	return (dst);
}

// // Driver program
// int	main(void)
// {
// 	char	source [100] = "Things to move";
// 	char	comparison [100] = "Things to move";

// 	ft_memmove(source + 100, source, strlen(source)+1);
// 	printf(":%s:\n", source);
// 	memmove(comparison + 100, comparison, strlen(comparison)+1);
// 	printf(":%s:\n", comparison);
// 	return (0);
// }
