/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teatime <teatime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:14:11 by egache            #+#    #+#             */
/*   Updated: 2025/01/07 21:44:59 by teatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

#define BUFFER_SIZE 10000

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "\0";
	static int 	pos = 0;
	char		*str;
	char		*line;
	int			fd_read;
	int	i;
	int start;
	int len;

	i = 0;
	fd_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(2);
	if (!str)
		return (free(str), NULL);
	str[0] = '\0';
	while (fd_read >= 0)
	{
		printf("\nfd_read avant read : %d\n", fd_read);
		printf("buffer avant read : %s\n", buffer);
		if (pos == 0 || buffer[pos] == '\0')
		{
			fd_read = read(fd, buffer, BUFFER_SIZE);
			if (fd_read <= 0)
			{
                if (fd_read == 0 && str[0] != '\0')
                    return (str);
				printf("\nfree et bzero\n");
				free(str);
				return (NULL);
			}
			buffer[fd_read] = '\0';
			pos = 0;
		}
		printf("fd_read : %d\n", fd_read);
		printf("buffer : %s\n", buffer);
		start = pos;
		printf("start: %d\n", start);
		while (buffer[pos] != '\n' && buffer[pos] != '\0')
			pos++;
		len = pos - start;
		line = ft_strjoin(str, buffer + start, len);
		if (!line)
		{
			free (str);
			return NULL;
		}
		printf("str : %s\n", str);
		free (str);
		str = line;
		if (buffer[pos] == '\n')
		{
			pos++;
			return (str);
		}
	}
}
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*result;

	fd = open(argv[1], O_RDONLY);
	while ((result = get_next_line(fd)) != NULL)
	{
		printf("\n--------------------------\n");
		printf("get_next_line : %s\n", result);
		printf("--------------------------\n");
		free(result);
	}
	printf("done\n");
	close(fd);
	return (0);
}
