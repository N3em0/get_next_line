/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teatime <teatime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:48:25 by egache            #+#    #+#             */
/*   Updated: 2025/01/09 18:23:51 by teatime          ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] != '\n' && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *str, char *buffer, size_t len)
{
	char	*join;
	size_t	str_len;
	size_t buffer_len;
	size_t lentotal;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str_len = ft_strlen(str);
	buffer_len = len;
	if (buffer[buffer_len] == '\n')
		buffer_len += 1;
	lentotal = str_len + buffer_len;
	join = malloc((lentotal + 1) * sizeof(char));
	if (!join)
		return (NULL);
	join[0] = '\0';
	while (i < str_len)
		join[i++] = str[i];
	while (j < buffer_len)
		join [i + j++] = buffer[j];
	join[lentotal] = '\0';
	return (join);
}

// int	ft_checkbl(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\n')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_remove(char *buffer)
// {
// 	int	i;

// 	i = 0;
// 	while
// }
