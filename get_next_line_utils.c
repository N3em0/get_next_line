/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:48:25 by egache            #+#    #+#             */
/*   Updated: 2024/12/03 05:17:30 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
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

char	*ft_strjoin(char *str, char *buffer)
{
	char	*join;
	int		len;

	len = ft_strlen(str);
	while (buffer[len] != '\n' && buffer[len])
		len++;
	if (buffer[len] == '\n')
		len++;
	printf("len = %d\n", len);
	join = malloc((len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	join[0] = '\0';
	printf("buffer step by step avant ft_join : %s\n", buffer);
	printf("join step by step avant ft_join : %s\n", join);
		ft_strcat(join, str);
		ft_strcat(join, buffer);
	free(str);
	printf("buffer step by step apres ft_join : %s\n", buffer);
	printf("join step by step apres ft_join : %s\n", join);
	return (join);
}

int	ft_checkbl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// char	*ft_remove(char *buffer)
// {
// 	int	i;

// 	i = 0;
// 	while
// }
