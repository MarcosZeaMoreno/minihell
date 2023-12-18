/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:50:19 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/11/02 14:03:55 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*index;
	int		len;

	len = ft_num_len(n);
	index = (char *)malloc(sizeof(char) * (len + 1));
	if (!index)
		return (0);
	index[len] = '\0';
	while (len != 0)
	{
		index[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (index);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*index;
	int		len;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		index = ft_uitoa(n);
		len += ft_printstring(index);
		free(index);
	}
	return (len);
}
