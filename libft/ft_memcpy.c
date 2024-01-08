/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:41:37 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/09 20:09:54 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	while (n--)
		*d++ = *s++;
	return (dst);
}

// int	main(void)
// {
// 	char	source[] = "Too many stuff to copy";
// 	char	destination [100];

// 	ft_memcpy(destination, source, ft_strlen(source)+1);
// 	printf("Copied string is %s", destination);

// 	int	nums[] = {10, 20, 30, 40, 50};
// 	int	n = sizeof(nums)/sizeof(nums[0]);
// 	int	numdest[n];
// 	int	i;

// 	ft_memcpy(numdest, nums, sizeof(nums));
// 	printf("\nCopied array is ");
// 	i = 0;
// 	while (i < n)
// 	{
// 		printf ("%d ", numdest[i]);
// 		i++;
// 	}
// 	return (0);
// }
