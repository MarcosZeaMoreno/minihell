/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:32:25 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/03/23 20:03:40 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(t_data *data, char **cmds)
{
	int		flag;
	int		i;

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
