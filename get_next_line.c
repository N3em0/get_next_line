/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:14:11 by egache            #+#    #+#             */
/*   Updated: 2024/12/20 05:23:14 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 100

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			fd_read;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (buffer[0])
		buffer[0] = '\0';
	fd_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (free(str), NULL);
	str[0] = '\0';
	while (fd_read >= 0 && ft_checkbl(buffer) == 0)
	{
		printf("\nfd_read avant read : %d\n", fd_read);
		printf("buffer avant read : %s\n", buffer);
		fd_read = read(fd, buffer, BUFFER_SIZE);
		printf("fd_read : %d\n", fd_read);
		printf("checkbl : %d\n", ft_checkbl(buffer));
		printf("buffer : %s\n", buffer);
		str = ft_strjoin(str, buffer);
		printf("str : %s\n", str);
		if (fd_read == 0 && str[0] == '\0')
		{
			printf("\nfree et bzero\n");
			free(str);
			return (NULL);
		}
	}
	while (buffer[i] != '\n')
		i++;
	printf("i 1 : %d\n", i);
	if (buffer[i] == '\n')
	{
		i++;
		printf("i apres if : %d\n", i);
	}
	while (*buffer && buffer[j] != '\n' && j < BUFFER_SIZE)
	{
		buffer[j] = buffer[i + j];
		j++;
		printf("buffer remplacant : %s\n", buffer);
	}
	return (str);
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
