/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:55:44 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/11/02 14:08:37 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printstring(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnum(int n)
{
	int		cont;
	char	*num;

	cont = 0;
	num = ft_itoa(n);
	cont = ft_printstring(num);
	free(num);
	return (cont);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
