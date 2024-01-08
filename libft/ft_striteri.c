/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:07:05 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/19 19:14:22 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** EN: This function applies function f to each character of the string passed
** as an argument. It's also passing its index as first argument. Each
** character is passed by address to f to be modified if necessary.
** Param. #1 The string to iterate.
** Param. #2 The function to apply to each character of s and its index.
** Return value None.
** Libc functions None.
**
** ES A cada carácter de la string ’s’, aplica la función
** ’f’ dando como parámetros el índice de cada
** carácter dentro de ’s’ y la dirección del propio
** carácter, que podrá modificarse si es necesario.
** s: La string que iterar.
** f: La función a aplicar sobre cada carácter.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

/*
** void my_func(unsigned int i, char *str)
** {
** 	printf("My own function: index = %d and the string is %s\n", i, str);
** }
**
** int main()
** {
** 	char str[10] = "Hello.";
** 	printf("The result is %s\n", str);
** 	ft_striteri(str, my_func);
** 	printf("The result is %s\n", str);
** 	return 0;
** }
*/