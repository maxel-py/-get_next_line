/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksimelistratov <maksimelistratov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:44:57 by maksimelist       #+#    #+#             */
/*   Updated: 2021/11/25 20:03:55 by maksimelist      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	a;

	a = c;
	if (!c)
		return ((char *)str + ft_strlen(str));
	while (*str)
	{
		if (*str == a)
			return ((char *)str);
		str++;
	}
	return (0);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = dest;
	while (i < len)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	size_max;

	size_max = 18446744073709551615U;
	if (size && (count > size_max / size))
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while (src[i] && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
