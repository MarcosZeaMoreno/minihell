/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:47:17 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/19 14:08:13 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stddef.h>
// #include <stdio.h>
// #include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	count;
	char	*position;
	int		last;

	count = 0;
	position = (char *)s;
	last = -1;
	while (count <= ft_strlen(position))
	{
		if (position[count] == (char)c)
			last = count;
		count++;
	}
	if (last != -1)
	{
		while (last > 0)
		{
			s++;
			last--;
		}
		return ((char *)s);
	}
	else
		return (0);
}

// int	main(void)
// {
// 	const char	*str;
// 	int			position;

// 	str = s;
// 	position = '\0';
// 	printf("string we have: %s\n", str);
// 	printf("result: :%s:\n", ft_strrchr(str, position));
// 	printf("_result: :%s:\n", strrchr(str, position));
// 	return (0);
// }
