/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teatime <teatime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:48:25 by egache            #+#    #+#             */
/*   Updated: 2025/01/10 15:16:38 by teatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buffer, size_t len)
{
	char	*join;
	size_t	str_len;
	size_t	lentotal;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	str_len = ft_strlen(str);
	if (buffer[len] == '\n')
		len++;
	lentotal = str_len + len;
	join = malloc((lentotal + 1) * sizeof(char));
	if (!join)
		return (NULL);
	join[0] = '\0';
	while (++i < str_len)
		join[i] = str[i];
	while (++j < len)
		join[i + j] = buffer[j];
	join[lentotal] = '\0';
	return (join);
}
