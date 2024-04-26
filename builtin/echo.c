/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:32:25 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/22 18:58:00 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to handle `echo` command that 
 * prints given arguments to the standard output.
 * Takes arguments passed in the `cmds` array to print
 * to the standard output.
 * If the first argument is "-n", the newline 
 * character at the end of the output is omitted.
 *
 * @param data A pointer to the main data structure.
 * @param cmds An array of strings representing the arguments to be printed.
 * @var flag A flag to indicate whether the newline character should be omitted.
 * @var i The index of the current argument in the `cmds` array.
 */
void	ft_echo(t_data *data, char **cmds)
{
	int	flag;
	int	i;

	(void)data;
	flag = 0;
	i = 1;
	if (cmds[i] != NULL && !ft_strncmp("-n", cmds[i], 3))
	{
		flag = 1;
		i++;
	}
	while (cmds[i] != NULL)
	{
		ft_printf_fd(1, "%s", cmds[i]);
		if (cmds[i + 1] != NULL)
			ft_printf_fd(1, " ");
		i++;
	}
	if (flag == 0)
		ft_printf_fd(1, "\n");
}
