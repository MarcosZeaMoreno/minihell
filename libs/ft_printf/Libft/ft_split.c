/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:31:34 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/10/03 12:30:02 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int		i;
	int		m;

	i = 0;
	m = 0;
	while (*s)
	{
		if (*s != c && m == 0)
		{
			m = 1;
			i++;
		}
		else if (*s == c)
			m = 0;
		s++;
	}
	return (i);
}

static char	*w_dup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	int			index;
	char		**split;

	i = 0;
	j = 0;
	index = -1;
	split = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = w_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
/*
int main()
{
	char a[] = "estoesunejemplo";
	printf("%s\n", *ft_split(a, 'm'));
}*/