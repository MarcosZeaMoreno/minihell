/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:09:15 by mzea-mor          #+#    #+#             */
/*   Updated: 2023/12/21 15:31:51 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_entry(void)
{
	char	*cwd;
	char	buffer[4096 + 1];

	cwd = getcwd(buffer, 4096);
	ft_printf("%s %sMini-Hell: %s", cwd, RED, RST);
}

void	print_exit(void)
{
	ft_printf("%s%s%s\n", CYAN, "Goodbye!", RST);
}

void	print_header(void)
{
	printf("");
	printf("");
	printf("");
	printf("");
	printf("");
	printf("");
	printf("");
	printf("");
	printf("");
	printf("");
	printf("");
	printf("");
}