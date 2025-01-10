/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teatime <teatime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:41:10 by egache            #+#    #+#             */
/*   Updated: 2025/01/10 15:18:34 by teatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include "stdlib.h"
# include "unistd.h"

char    *get_next_line(int fd);
size_t  ft_strlen(char *str);
char    *ft_strjoin(char *str, char *buffer, size_t len);
char    *ft_fill(char *str, char *buffer, int len);
char    *ft_line(char *str, char *buffer, int fd_read, int fd);

#endif