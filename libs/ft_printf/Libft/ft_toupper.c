/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:50:54 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/09/23 12:16:43 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
int main(void)
{
	int i = 'v';
	int j = 'f';

	printf("%c - %c <---- Test 1\n", i, ft_toupper(i));
	printf("%c - %c <---- Test 2\n", j, ft_toupper(j));
}*/
