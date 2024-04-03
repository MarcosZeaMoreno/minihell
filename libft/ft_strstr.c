/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:08:43 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/23 19:10:03 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		found;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		k = 0;
		j = i;
		found = j;
		while (haystack[j] != '\0' && needle[k] != '\0')
		{
			if (haystack[j] != needle[k])
				found = -1;
			k++;
			j++;
		}
		if (found != -1)
			return ((char *)haystack + found);
		i++;
	}
	return (NULL);
}
