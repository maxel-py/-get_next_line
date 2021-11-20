char    *get_next_line(int fd)
{
    static char *reserv;
    char        *buffer;
    char        *current;
    int         read_bytes;
    if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
        return (NULL);
    read_bytes = 1;
    while (ft_strchr(reserv, '\n') == 0 && read_bytes != 0)
    {
        buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
        if (!buffer)
            return (NULL);
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        if (read_bytes == -1)
            return (NULL);
        buffer[read_bytes] = '\0';
        reserv = ft_strjoin(reserv, buffer);
    }
    current = ft_strdup(reserv);
    reserv = ft_strsave(reserv);
    return (current);
}

char *ft_strsave(char *reserv,char *current)
{
    char *p_n;

    if (reserv)    // если остаток вообще есть
        if (ft_strchr(reserv, '\n'))   // если в остатке есть символ '\n'
        {
            p_n = ft_strchr(reserv, '\n');
            (*p_n) = '\0';                           // ставим на его место символ окончания строки
            *current = ft_strdup(reserv);           // до '\0' записываем в line   
            ft_strcpy(reserv, ++p_n);              // обновляем остаток и заносим туда все что после '\0'
        }
        else
        {
            *current = ft_strdup(reserv);
            while (*reserv)
			    *reserv++ = '\0';          // ОБРАТИТЬ ВНИМАНИЕ не понятно зачем нужна функция??
        }  
    else
        *current = (ft_calloc(1, 1));    // можно попробовать поставить просто /0
    return (reserv);
}

int ft_create_line(int fd, char *remainder, char **line)
{
    int             BUFFER_SIZE = 2;
    static int      byte_was_read;
    char            buf[BUFFER_SIZE + 1];
    char            *p_n;

    byte_was_read = read(fd, buf, BUFFER_SIZE);
    buf[byte_was_read] = '\0';
    if (ft_strchr(buf, '\n'))    // если в считанном куске есть '\n', вернуть указатель и присвоить его p_n
    {
        p_n = ft_strchr(buf, '\n');
        *p_n = '\0';
        remainder = ft_strdup(++p_n); // сформировать остаток с символа следующим за '\0'
    }
    *line = ft_strjoin_and_free_oldline(*line, buf);
    return(byte_was_read);
}


int get_next_line(char **line)
{
  int rd = 0;
  int i = 0;
  char ch;
  char *buffer = malloc(100000);
  *line = buffer;
  while ((rd = read(0, &ch, 1)) > 0 && ch != '\n')
    buffer[i++] = ch;
  buffer[i] = '\0';
  return (rd);
}



char    *ft_check_ostatok(char **ostatok, char **line) // проверка наличия отстатка и вхождения в него '\n'
{
    char    *p_n;

    p_n = NULL;
    
    if (**ostatok)    // если остаток вообще есть
        if (ft_strchr(*ostatok, '\n'))   // если в остатке есть символ '\n'
        {
            p_n = ft_strchr(*ostatok, '\n');                         // ставим на его место символ окончания строки
            *p_n = '\0';
            *line = ft_strdup(*ostatok, 0);           // до '\0' записываем в line     
            *ostatok = ft_strdup(++p_n, 1); 
        }
        else
        {
            *line = ft_strdup(*ostatok, 1);
            ft_strclr(*ostatok);          // ОБРАТИТЬ ВНИМАНИЕ не понятно зачем нужна функция??
        }  
    else
        *line = (ft_calloc(1, 1));    // можно попробовать поставить просто /0
    return (p_n);
}

char *get_next_line(int fd)
{
    int             BUFFER_SIZE = 12;
    char            buf[BUFFER_SIZE + 1];
    static int      byte_was_read = 1;
    char            *p_n;
    static char     *ostatok;
    char            *line;

    if (byte_was_read < 1 || BUFFER_SIZE <= 0 || fd < 0)
        return(0);
    p_n = ft_check_ostatok(&ostatok, &line);
    while (!p_n && byte_was_read)
    { 
        byte_was_read = read(fd, buf, BUFFER_SIZE);
        buf[byte_was_read] = '\0';
        if (ft_strchr(buf, '\n'))
        {
            p_n = ft_strchr(buf, '\n');
            ostatok = ft_strdup(++p_n, 1);
            *p_n = '\0';            
        }
        line = ft_strjoin_and_free_oldline_buf(&line, buf);
    }
    return(line);
}