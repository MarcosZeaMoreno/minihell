/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:59:10 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/09/28 19:43:02 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*index;
	int		len;
	long	num;

	num = (long)n;
	len = numlen(n);
	index = malloc(sizeof(char) * (len + 1));
	if (!index)
		return (0);
	if (n < 0)
	{
		index[0] = '-';
		num *= -1;
	}
	if (num == 0)
		index[0] = '0';
	index[len] = '\0';
	while (num > 0)
	{
		len--;
		index[len] = num % 10 + '0';
		num = num / 10;
	}
	return (index);
}
