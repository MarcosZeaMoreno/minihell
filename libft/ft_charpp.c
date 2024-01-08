/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charpp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:10:04 by vkatason          #+#    #+#             */
/*   Updated: 2023/09/24 12:38:16 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_charpp_free(char **charpp)
{
	int	i;

	i = 0;
	while (charpp && charpp[i])
	{
		free(charpp[i]);
		charpp[i] = NULL;
		i++;
	}
	if (charpp)
	{
		free(charpp);
		charpp = NULL;
	}
}
