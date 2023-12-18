/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:40:57 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/09/26 13:16:27 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_n;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	while (s1[start] && ft_char_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_set(s1[end - 1], set))
		end--;
	str_n = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str_n)
		return (0);
	while (end > start)
		str_n[i++] = s1[start++];
	str_n[i] = '\0';
	return (str_n);
}
