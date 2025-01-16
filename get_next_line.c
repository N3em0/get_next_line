/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:14:11 by egache            #+#    #+#             */
/*   Updated: 2025/01/16 15:16:23 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "\0";
	char		*str;
	int			fd_read;

	fd_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(2 * sizeof(char));
	if (!str)
		return (free(str), NULL);
	str[0] = '\0';
	str = ft_line(str, buffer, fd_read, fd);
	if (!str)
		return (free(str), NULL);
	return (str);
}

char	*ft_line(char *str, char *buffer, int fd_read, int fd)
{
	int			start;
	static int	pos = 0;

	while (fd_read >= 0)
	{
		if (pos == 0 || buffer[pos] == '\0')
		{
			fd_read = read(fd, buffer, BUFFER_SIZE);
			if (fd_read == 0 && str[0] != '\0')
				return (str);
			if (fd_read <= 0)
				return (free(str), NULL);
			buffer[fd_read] = '\0';
			pos = 0;
		}
		start = pos;
		while (buffer[pos] != '\n' && buffer[pos] != '\0')
			pos++;
		str = ft_fill(str, buffer + start, pos - start);
		if (!str)
			return (free(str), NULL);
		if (buffer[pos] == '\n')
			return (pos++, str);
	}
	return (str);
}

char	*ft_fill(char *str, char *buffer, int len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnjoin(str, buffer, len);
	if (!tmp)
		return (free(str), NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (buffer[len] == '\n')
		tmp[i++] = '\n';
	tmp[i] = '\0';
	free(str);
	return (tmp);
}
// #include <fcntl.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*result;

// 	fd = open(argv[1], O_RDONLY);
// 	while ((result = get_next_line(fd)) != NULL)
// 	{
// 		printf("\n-----------------------------\n");
// 		printf("get_next_line : %s", result);
// 		printf("-----------------------------\n\n");
// 		free(result);
// 	}
// 	printf("done\n");
// 	close(fd);
// 	return (0);
// }
