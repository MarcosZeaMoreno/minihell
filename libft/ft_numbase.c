/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:07:10 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/14 17:02:55 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_numbase(unsigned int num, char *set)
{
	static char	buffer[50];
	char		*ptr;
	int			base;

	base = ft_strlen(set);
	ptr = &buffer[49];
	*ptr = '\0';
	*--ptr = set[num % base];
	num /= base;
	while (num != 0)
	{
		*--ptr = set[num % base];
		num /= base;
	}
	return (ptr);
}
