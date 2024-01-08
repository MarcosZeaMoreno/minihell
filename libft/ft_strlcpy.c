/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:53:21 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/08 15:30:25 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>                       /* to use printf() */

size_t	ft_strlcpy(char *dst, const char *src, size_t	dstsize)
{
	size_t	i;

	i = 0;
	if ((src[i] || dst[i]) && dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	const char	*str = "string to try to copy";
// 	size_t		sz;
// 	size_t		szmine;
// 	char		bf[10];

// 	bf[9] = '\0';
// 	printf("string: \"%s\"\n\n", str);
// 	printf("buffer before copy: \"%s\"\n", bf);
// 	sz = strlcpy(bf, str, sizeof(bf));
// 	szmine = ft_strlcpy(bf, str, sizeof(bf));
// 	if (sz >= sizeof(bf))
// 		printf("reduced: from %zu to %lu simbols !\n", sz, sizeof(bf) - 1);
// 	if (szmine >= sizeof(bf))
// 		printf("with mine: from %zu to %lu simbols !\n", szmine, sizeof(bf) - 1);
// 	printf(":  \"%s\"\n", bf);
// 	return (0);
// }
