/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:27:25 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/29 18:56:11 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

void	suppress_output(void)
{
	struct termios	termios_p;

	if (tcgetattr(0, &termios_p) != 0)
		perror("Minishell: tcgetattr");
	termios_p.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &termios_p) != 0)
		perror("Minishell: tcsetattr");
}

/**
 * @brief Funtion to handle the sigint
 * 
 * @param sig 
 */
void	handle_sigint(int sig)
{
    if (sig == SIGINT)
    {
		write(1, "\n", 1);
        rl_on_new_line();  // readline function to update the prompt line
        rl_replace_line("", 0);  // clear the current line in readline
        rl_redisplay();  // redisplay the prompt
    }
}

/**
 * @brief Funtion to handle the sigquit
 * 
 * @param sig 
 */
void	handle_sigquit(int sig)
{
	if (sig == SIGQUIT)
	{
		write(1, "\n", 1);
		rl_on_new_line();  // readline function to update the prompt line
		rl_replace_line("", 0);  // clear the current line in readline
		rl_redisplay();  // redisplay the prompt
    }
}
