/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:09:15 by mzea-mor          #+#    #+#             */
/*   Updated: 2023/12/14 18:28:25 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_entry(void)
{
	char	*cwd;
	char	buffer[4096 + 1];

	cwd = getcwd(buffer, 4096);
	printf("%s ", cwd);
	printf("\x1b[31mMini Hell: \x1b[0m");
}
