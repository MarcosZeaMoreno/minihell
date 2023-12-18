/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:19:21 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/09/23 11:49:57 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char hola = 'f';
	char hola1 = ' ';
	char hola2 = '3';

	printf("%d\n", ft_isalnum(hola));
	printf("%d\n", ft_isalnum(hola1));
	printf("%d\n", ft_isalnum(hola2));
}*/
