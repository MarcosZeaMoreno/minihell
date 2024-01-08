/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:23:41 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/19 00:58:20 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	len1;
	size_t	len2;
	char	*dest;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		dest = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (dest == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			dest[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			dest[len1] = s2[i];
			len1++;
		}
		dest[len1] = '\0';
		return (dest);
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	char	*str3;

// 	str1 = "";
// 	str2 = "";
// 	str3 = "Jaime";
// 	printf("%s\n", ft_strjoin(str1, str2));
// 	printf("%s\n", ft_strjoin(str1, str3));
// 	return (0);
// }