/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:08:30 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/09/23 12:16:04 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
int main(void)
{
    int i = 'V';
    int j = 'F';

	printf("%c - %c <---- Test 1\n", i, ft_tolower(i));
    printf("%c - %c <---- Test 2\n", j, ft_tolower(j));
}*/