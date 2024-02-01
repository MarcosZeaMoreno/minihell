/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:32:04 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/24 18:14:24 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*stock;
	char		*ptr;

	if (str != NULL)
		stock = str;
	if (stock == NULL)
		return NULL;
	while (ft_strchr(delim, *stock))
		stock++;
	if (*stock == '\0') {
		stock = NULL;
		return NULL;
	}
	ptr = stock;
	while (*stock != '\0' && !ft_strchr(delim, *stock))
		stock++;
    if (*stock != '\0')
	{
		*stock = '\0';
		stock++;
	}
	else
		stock = NULL;
	return (ptr);
}
