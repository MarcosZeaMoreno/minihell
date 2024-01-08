/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:58:29 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/14 17:03:35 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int num)
{
	char	*digit;
	int		len;

	len = 0;
	digit = ft_itoa(num);
	len += ft_putstr(digit);
	free(digit);
	return (len);
}
