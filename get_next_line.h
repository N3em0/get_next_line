/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teatime <teatime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:41:10 by egache            #+#    #+#             */
/*   Updated: 2025/01/10 01:53:20 by teatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdio.h" //for printf remove after
# include "stdlib.h"
# include "unistd.h"

char			*get_next_line(int fd);
// char			*ft_strdup(const char *src);
size_t	ft_strlen(char *str);
// char			*ft_strcat(char *dest, char *src);
char			*ft_strjoin(char *str, char *buffer, size_t len);
// int				ft_checkbl(char *str);
// static void		ft_bzero(char *str);
char *ft_fill   (char *str, char *buffer, int pos, int len);

#endif
