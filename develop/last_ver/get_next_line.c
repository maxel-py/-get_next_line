/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksimelistratov <maksimelistratov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:44:46 by maksimelist       #+#    #+#             */
/*   Updated: 2021/11/25 20:33:25 by maksimelist      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = ft_calloc(len1 + len2 + 1, 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcpy(str + len1, s2, len2 + 1);
	free(s1);
	return (str);
}

static char	*ft_create_remainder(char *buf, char *line)
{
	char	*temp_buf;
	int		i;

	i = 0;
	temp_buf = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!temp_buf)
		return (NULL);
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		temp_buf[i] = buf[i];
		i++;
	}
	temp_buf[i] = buf[i];
	if (buf[i] != '\0')
		ft_strlcpy(buf, buf + i + 1, BUFFER_SIZE + 1);
	else
		ft_memset(buf, 0, BUFFER_SIZE + 1);
	line = ft_strjoin(line, temp_buf);
	free(temp_buf);
	return (line);
}

static char	*ft_create_line(char *buf, int fd, int byte_was_read)
{
	char	*line;

	line = (char *)ft_calloc(1, 1);
	while (byte_was_read == BUFFER_SIZE && !ft_strchr(buf, '\n'))
	{
		line = ft_strjoin(line, buf);
		byte_was_read = read(fd, buf, BUFFER_SIZE);
		buf[byte_was_read] = '\0';
	}
	if (byte_was_read < 0)
	{
		free(line);
		return (NULL);
	}
	line = ft_create_remainder(buf, line);
	if (*line)
		return (line);
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static int		byte_was_read;
	static char		*buf;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buf)
	{
		buf = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buf)
			return (NULL);
	}
	if (*buf == '\0')
	{
		byte_was_read = read(fd, buf, BUFFER_SIZE);
		buf[byte_was_read] = '\0';
	}
	line = ft_create_line(buf, fd, byte_was_read);
	if (*buf == '\0')
	{
		free(buf);
		buf = 0;
	}
	return (line);
}
