/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksimelistratov <maksimelistratov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:06:45 by maksimelist       #+#    #+#             */
/*   Updated: 2021/11/23 18:04:16 by maksimelist      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void        *ft_calloc(size_t count, size_t size);
size_t      ft_strlen(const char *s);
char        *ft_strjoin(char const *s1, char const s2);
char        *ft_strjoin_and_free_oldline_buf(char *line, char buf);
char        *ft_strdup_and_free_oldline_buf(char *line);
char        *ft_strdup(const char *src);
void        ft_check_ostatok(char **ostatok, char **line);
char        *get_next_line(int fd);

#endif