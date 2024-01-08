/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:54:40 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/14 17:03:56 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	unsigned long	num;
	int				res;

	num = (unsigned long)ptr;
	res = 0;
	if (num > 15)
		res += ft_putptr((void *)(num / 16));
	res += ft_putchar("0123456789abcdef"[num % 16]);
	return (res);
}
