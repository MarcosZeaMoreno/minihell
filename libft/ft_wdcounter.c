/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdcounter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:15:33 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/18 18:56:49 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wdcounter(char const *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] != c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] == c && str[i] != '\0')
			i++;
	}
	return (words);
}
