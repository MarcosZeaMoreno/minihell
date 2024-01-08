/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:20:19 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/14 17:04:45 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_type(char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (type == 'p')
	{
		ft_putstr("0x");
		return (ft_putptr(va_arg(args, void *)) + 2);
	}
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_putstr(
				ft_numbase(va_arg(args, unsigned int), "0123456789")));
	else if (type == '%')
		return (ft_putchar('%'));
	else if (type == 'x')
		return (ft_putstr(
				ft_numbase(va_arg(args, unsigned int), "0123456789abcdef")));
	else if (type == 'X')
		return (ft_putstr(
				ft_numbase(va_arg(args, unsigned int), "0123456789ABCDEF")));
	return (0);
}
