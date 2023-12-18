/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:07:33 by mzea-mor          #+#    #+#             */
/*   Updated: 2022/09/23 19:06:44 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int			s1_size;
	static char	*dup;
	char		*dup_offset;

	s1_size = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * s1_size + 1);
	if (dup == NULL)
		return ((char *) NULL);
	dup_offset = dup;
	while (*s1)
	{
		*dup_offset = *s1;
		dup_offset++;
		s1++;
	}
	*dup_offset = '\0';
	return (dup);
}
