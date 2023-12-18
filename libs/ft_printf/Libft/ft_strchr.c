/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:10:48 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/10/07 13:23:36 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (ptr[i] == (unsigned char)c)
			return (ptr + i);
		i++;
	}
	ptr = (char *)&s[i];
	if (s[i] == (char) c)
		return (ptr);
	if (c == '\0')
		return (ptr + i);
	return (0);
}
