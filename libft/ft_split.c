/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:52:22 by vkatason          #+#    #+#             */
/*   Updated: 2023/09/30 16:51:45 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)

{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
			i++;
		}
		else
		i++;
	}
	return (word);
}

static int	ft_wordsize(char const *s, char c, int i)

{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

/** @brief Function that separates one string 
 *  to various depending on separator
 *  @param s string of chars
 *  @param c any char separator
 *  @return char** array of separated string
 */
char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = -1;
	word = ft_wordcount(s, c);
	strs = (char **)malloc((word + 1) * sizeof(char *));
	if (!(strs))
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_wordsize(s, c, i);
		strs[j] = ft_substr(s, i, size);
		if (!strs[j])
			return (ft_free(strs, j), NULL);
		i += size;
	}
	strs[j] = 0;
	return (strs);
}
