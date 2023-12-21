/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:27:25 by mzea-mor          #+#    #+#             */
/*   Updated: 2023/12/21 17:07:26 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Funtion to handle the sigint
 * 
 * @param sig 
 */
void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		print_entry();
		signal(SIGINT, handle_sigint);
	}
}
