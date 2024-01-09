/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:32:04 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/09 17:48:47 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*lasts;
	int			ch;

	if (str == NULL)
		str = lasts;
	ch = *str++;
	if (ch == '\0')
		return (NULL);
	while (ft_strchr(delim, ch) != NULL && ((ch = *str++) != '\0'));
	--str;
	lasts = str + TODO ft_strcspn(str, delim);
	if (*lasts != '\0')
		*lasts++ = '\0';
	return (str);
}
