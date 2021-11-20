#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


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

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
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
    return (&str[0]);
}
char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
        if (*s == (char)c)
            return ((char*)s);
		s++;   
	}
	return (NULL);
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

char		*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
	dest[i] = src[i];
	return (dest);
}


char *ft_strjoin_and_free_oldline_buf(char **line, char buf)
{
    char    *tmp;

    tmp = *line;
    *line = ft_strjoin(*line, buf);
    free(tmp);
    
    return(*line);
}

char    *ft_check_ostatok(char **ostatok, char **line) // проверка наличия отстатка и вхождения в него '\n'
{
    *line = (ft_calloc(1, 1));
    if (*ostatok)
    {
        while(**ostatok != '\n' && **ostatok != '\0')
        {
            *line = ft_strjoin_and_free_oldline_buf(line, **ostatok);
            (*ostatok)++;
        }
        *line = ft_strjoin_and_free_oldline_buf(line, **ostatok); // добавляем к концу \n
        (*ostatok)++;
        *ostatok = ft_strdup(*ostatok); // остаток  до '/0' добавляем в остаток
        if (**ostatok == '\0')
            *ostatok = NULL;
        return(*ostatok);
    }               
    else
        return(NULL);
}

char *get_next_line(int fd)
{
    int             BUFFER_SIZE = 3;
    char            buf[BUFFER_SIZE + 1];
    static int      byte_was_read = 1;
    static char     *ostatok;
    char            *line;
    int             i = 0;

    if (byte_was_read < 1 || BUFFER_SIZE <= 0 || fd < 0)
        return(0);
    ft_check_ostatok(&ostatok, &line);
    while (!ostatok && byte_was_read)
    { 
        byte_was_read = read(fd, buf, BUFFER_SIZE);
        buf[byte_was_read] = '\0';
        i = 0;
        while(buf[i] != '\n' && buf[i] != '\0')
            line = ft_strjoin_and_free_oldline_buf(&line, buf[i++]);  
        line = ft_strjoin_and_free_oldline_buf(&line, buf[i]);
        if (buf[i] != '\0')
            ostatok = ft_strdup(&buf[++i]); 
    }
    return(line);
}


int main()
{
    int		fd;
    // char    *line = NULL;

    fd = open("./test.txt", O_RDONLY);
    // while((line = get_next_line(fd)))
    // {
    //    printf("%s",line); 
    //    free(line);
    // }
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    return(0);
}

/*
buf = malloc(BUFFER_SIZE * sizeof(char));
if (!pointer)
		return (NULL);
*/