/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:25:36 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/19 20:31:56 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Puts number to the file descriptor */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

/* int	main(void)
{
	int	num;

	num = 42;
	ft_putnbr_fd(num, 1);
	return (0);
} */

// Compile with gcc -Wextra -Wall -Werror ft_putnbr_fd.c 
// ft_putstr_fd.c ft_putchar_fd.c ft_strlen.c
