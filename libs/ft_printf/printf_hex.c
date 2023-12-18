/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:55:40 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/11/02 14:00:39 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int n, const char xX)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, xX);
		ft_put_hex(n % 16, xX);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (xX == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (xX == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int n, const char xX)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(n, xX);
	return (ft_hex_len(n));
}
