/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:45:05 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/10/07 13:08:09 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/* int main (void)
{
	   int i;
 
        i = 0;
        while (i < 530)
        {
                if (ft_isalpha(i) != isalpha(i))
                        {printf("MAL");
						exit(0);}
                i++;
						
        }
		printf("BIEN");
        exit(1);
} */
