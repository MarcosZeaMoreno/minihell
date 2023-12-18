/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:42:40 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/10/03 11:42:12 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		*ptr;

	i = 0;
	ptr = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			ptr = (char *)&s[i];
		i++;
	}
	if (s[i] == (char) c)
	{
		ptr = (char *)&s[i];
		return (ptr);
	}
	return (ptr);
}
