/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:25:15 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/02/14 12:06:56 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**strdup_2d(char **src)
{
	int		i;
	int		len;
	char	**dst;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	dst = malloc(sizeof(char *) * (len + 1));
	if (!dst)
		return (NULL);
	while (src[i])
	{
		dst[i] = strdup(src[i]);
		if (!dst[i])
		{
			for (int j = 0; j < i; j++) //quidado con el for loops (Norminette)
				free(dst[j]);
			free(dst);
			return (NULL);
		}
		i++;
	}
	dst[i] = (NULL);
	return (dst);
}
