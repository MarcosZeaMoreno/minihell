/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:32:04 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/08 14:34:21 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlen_char(const char *string, char c)
{
	int	counter;

	counter = 0;
	while (string[counter] != c)
	{
		counter++;
	}
	return (counter);
}

char	*ft_strtok(char *input, char d)
{
	char	*result;
	int		i;

	if (input == NULL)
		return (NULL);
	if (!ft_strchr(input, d))
		return (NULL);
	result = (char *)malloc(sizeof(char) * (strlen_char(input, d) + 1));
	i = strlen_char(input, d) - 1;
	while (i > -1)
	{
		result[i] = input[i];
		i--;
	}
	result[strlen_char(input, d)] = '\0';
	return (result);
}
