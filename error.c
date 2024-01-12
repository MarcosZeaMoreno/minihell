/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:25:58 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/12 16:39:31 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *usr_input, int type_error)
{
	ft_printf("%sMiniHell:%s", RED, RST);
	if (type_error == 1)
		ft_printf(" %s: command not found\n", usr_input);
}
