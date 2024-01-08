/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:53:54 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/14 15:55:05 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	gnl_strlen_line(char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] != '\n')
	{
		len++;
	}
	return (len);
}

size_t	gnl_strlcat(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dlen;
	unsigned int	slen;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	dlen = gnl_strlen(dst);
	slen = gnl_strlen(src);
	j = dlen;
	if (dstsize == 0 || dstsize <= dlen)
		return (slen + dstsize);
	while (src[i] != '\0' && i < dstsize - dlen - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len = gnl_strlen(s1) + gnl_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	gnl_strlcpy(str, s1, len + 1);
	gnl_strlcat(str, s2, len + 1);
	return (str);
}

char	*gnl_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == s[i])
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
