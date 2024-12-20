/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:41:10 by egache            #+#    #+#             */
/*   Updated: 2024/12/20 02:45:23 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdio.h" //for printf remove after
# include "stdlib.h"
# include "unistd.h"

char			*get_next_line(int fd);
char			*ft_strdup(const char *src);
size_t	ft_strlen(char *str);
char			*ft_strcat(char *dest, char *src);
char			*ft_strjoin(char *str, char *buffer);
int				ft_checkbl(char *str);
static void		ft_bzero(char *str);

#endif
