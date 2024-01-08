/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:56:17 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/17 17:07:58 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlcpy(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	j = gnl_strlen(src);
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*str;

	if (gnl_strlen(s) == 0)
		return (NULL);
	if (start > gnl_strlen(s))
	{
		len = 0;
		start = 0;
	}
	if (start + len > gnl_strlen(s) || len == 0)
		len = gnl_strlen(s) - start;
	if (len > gnl_strlen(s))
		len = gnl_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	gnl_strlcpy(str, (s + start), len + 1);
	return (str);
}

char	*gnl_read_and_save(char *block, int fd, int *n)
{
	char	*buf;
	char	*temp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (block);
	*n = read(fd, buf, BUFFER_SIZE);
	if (*n == -1)
		temp = NULL;
	else if (*n > 0)
	{
		buf[*n] = '\0';
		temp = gnl_strjoin(block, buf);
	}
	else
	{
		temp = gnl_strjoin(block, "");
	}
	free (buf);
	return (temp);
}

char	*gnl_get_and_free(char **block, int len, int null_block)
{
	char	*line;

	line = gnl_substr(*block, 0, len);
	free(*block);
	if (null_block)
		*block = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*block;
	int			line_len;
	int			n;
	char		*old_block;

	n = 0;
	while (fd >= 0 && BUFFER_SIZE > 0 && n >= 0)
	{
		old_block = block;
		if (gnl_strchr(block, '\n'))
		{
			line_len = gnl_strlen_line(block) + 1;
			block = gnl_substr(old_block, line_len, 0);
			return (gnl_get_and_free(&old_block, line_len, 0));
		}
		else
		{
			block = gnl_read_and_save(old_block, fd, &n);
			free(old_block);
			if (n == 0)
				return (gnl_get_and_free(&block, 0, 1));
		}
	}
	return (NULL);
}
