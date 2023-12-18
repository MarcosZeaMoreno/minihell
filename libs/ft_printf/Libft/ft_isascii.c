/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:14:53 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/09/23 11:50:44 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int main(void)
{
	char hola = ',';
	char hola1 = ' ';
	char hola2 = 'a';

	printf("%d\n", ft_isascii(hola));
	printf("%d\n", ft_isascii(hola1));
	printf("%d\n", ft_isascii(hola2));
}*/
