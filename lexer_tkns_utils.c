/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:21:08 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/10 22:43:24 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_reset_tkn_order(int reset)
{
	static int	order = 0;

	if (reset)
		order = 0;
	else
		order++;
	return (order);
}

int	ft_count_the_same(t_lexer *lexer, char symbol)
{
	int		count;
	int		i;

	count = 0;
	i = lexer->i;
	while (lexer->input[i] == symbol)
	{
		count++;
		i++;
	}
	return (count);
}

char	*ft_str_repeat(char c, int count)
{
	char	*str;
	int		i;

	str = malloc(count + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		str[i] = c;
		i++;
	}
	str[count] = '\0';
	return (str);
}
