/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksimelistratov <maksimelistratov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 09:47:03 by maksimelist       #+#    #+#             */
/*   Updated: 2021/11/26 13:21:22 by maksimelist      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int main()
{
    int		fd;
    char    *line;

    fd = open("./test.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s",line);
    while(line)
    {
        line = get_next_line(fd);
        printf("%s",line);
    }
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    return(0);
}