/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwaymar <lwaymar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:06:45 by maksimelist       #+#    #+#             */
/*   Updated: 2021/11/20 15:26:22 by lwaymar          ###   ########.fr       */
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
char        *ft_strdup(const char *src);
char        *ft_check_ostatok(char *ostatok, char *line);
char        *get_next_line(int fd);

#endif