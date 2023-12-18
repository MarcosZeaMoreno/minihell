/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:59:38 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/12/15 17:58:51 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_check_args(const char str, va_list args)
{
	int	cont;

	cont = 0;
	if (str == 'c')
		cont += ft_printchar(va_arg(args, int));
	else if (str == 's')
		cont += ft_printstring(va_arg(args, char *));
	else if (str == 'p')
		cont += ft_print_ptr(va_arg(args, unsigned long long));
	else if (str == 'd' || str == 'i')
		cont += ft_printnum(va_arg(args, int));
	else if (str == 'u')
		cont += ft_print_unsigned(va_arg(args, unsigned int));
	else if (str == 'x' || str == 'X')
		cont += ft_print_hex(va_arg(args, unsigned int), str);
	else if (str == '%')
		cont += ft_printpercent();
	return (cont);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		j;
	int		cont;
	va_list	args;

	i = 0;
	j = 0;
	cont = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			cont += ft_check_args(str[i], args);
		}
		else
			cont += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (cont);
}
/*
int	main(void)
{
	char var = 'z';
	char var1 = 'R';
	char *var2;
	char *var3 = "STRIIIINGGGGGG";

	ft_printf("Hola%c esto es una p%crueba\n", var, var1);
	ft_printf("esto es un %s :)\n", var2);
	ft_printf("esto es un %s :)\n", var3);
	ft_printf("Esto es un %% porcentaje\n");
}*/