/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:50:51 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/16 21:35:49 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
// #include <string.h>
// #include <stdio.h>

char	*ft_strdup(char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!new)
		return (NULL);
	while (*s1)
		new[i++] = *s1++;
	new[i] = '\0';
	return (new);
}

// int	main(int ac, char *av[])
// {
// 	char	*minefunction;
// 	char	*original;

// 	if (ac == 2)
// 	{
// 		minefunction = ft_strdup(av[1]);
// 		original = strdup(av[1]);
// 		printf(":%s:\n:%s:\n", minefunction, original);
// 	}
// 	return (0);
// }