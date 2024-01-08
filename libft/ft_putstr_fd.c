/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:53:27 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/19 20:03:45 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the string s to the file descriptor fd.
** Param. #1 The string to output.
** Param. #2 The file descriptor.
** Return value None.
** Libc functions write(2).
** Compile with gcc -Wextra -Werror -Wall ft_putstr_fd.c libft.h ft_strlen.c
*/

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// int	main(void)
// {
// 	char	*string;

// 	string = "Welcome to 42!";
// 	ft_putstr_fd(string, 1);
// 	return (0);
// }