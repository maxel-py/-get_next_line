/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksimelistratov <maksimelistratov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:30:00 by maksimelist       #+#    #+#             */
/*   Updated: 2021/11/21 21:53:49 by maksimelist      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void *ft_calloc(size_t count, size_t size)
{
    int *pointer;
    int i;
    i = 0;

    pointer = (int*)malloc(count*size);
    
    if(pointer == NULL)
        return(NULL);
    while(i<*(int *)pointer)
        *(pointer+i) = 0;
    return((void *)pointer); 
}

size_t      ft_strlen(const char *s)
{
    size_t  len;

    len = 0;
    if (*s)
    {
        while (s[len])
            len++;
        return (len);
    }
    return(0);
}

char    *ft_strjoin(char const *s1, char const s2)
{
    int     i;
    int     j;
    char    *str;

    i = 0;
    j = 0;
    if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1 + ft_strlen(&s2)))))
        return (NULL);
    else
    {
        while (s1[i])
        {
            str[i] = s1[i];
            i++;
        }
        str[i] = s2;
        i++;
        str[i] = '\0';
    }
    return (str);
}


char	*ft_strdup(const char *src)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!(src) || !(cpy))
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}


char *ft_create_line(char *s1, char s2)

{
    int     i;
    int     j;
    char    *str;

    i = 0;
    j = 0;
    if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1 + ft_strlen(&s2)))))
        return (NULL);
    else
    {
        while (s1[i])
        {
            str[i] = s1[i];
            i++;
        }
        str[i] = s2;
        i++;
        str[i] = '\0';
    }
    free(s1);
    return (str);
}


void   ft_check_ostatok(char **ostatok, char **line) // проверка наличия отстатка и вхождения в него '\n'
{

    *line = (ft_calloc(1, 1));
    if (*ostatok)
    {
        while(**ostatok != '\n' && **ostatok != '\0')
        {
            *line = ft_create_line(*line, **ostatok);
            (*ostatok)++;
        }
        *line = ft_create_line(*line, **ostatok); // добавляем к концу \n
        (*ostatok)++;
        *ostatok = ft_strdup(*ostatok); // остаток  до '/0' добавляем в остаток
        if (**ostatok == '\0')
            *ostatok = NULL;
    }
}

char *get_next_line(int fd)
{
    char            *buf;
    static int      byte_was_read = 1;
    static char     *ostatok;
    char            *line = NULL;
    int             i;

    if (fd < 0 || byte_was_read < 1 || BUFFER_SIZE <= 0)
        return(0);
    buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buf)
        return (0);
    ft_check_ostatok(&ostatok, &line);
    while (!ostatok && byte_was_read)
    { 
        byte_was_read = read(fd, buf, BUFFER_SIZE);
        buf[byte_was_read] = '\0';
        i = 0;
        while(buf[i] != '\n' && buf[i] != '\0')
            line = ft_create_line(line, buf[i++]);  
        line = ft_create_line(line, buf[i]);
        if (buf[i] != '\0')
            ostatok = ft_strdup(&buf[++i]); 
    }
    free(buf);
    return(line);
}