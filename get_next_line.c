/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:14:11 by egache            #+#    #+#             */
/*   Updated: 2024/12/14 04:44:37 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			fd_read;

	buffer[0] = '\0';
	fd_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (fd_read > 0 && ft_checkbl(buffer) == 0)
	{
		//printf("fd_read before : %d\n", fd_read);
		fd_read = read(fd, buffer, BUFFER_SIZE);
		//printf("fd_read after : %d\n", fd_read);
		str = ft_strjoin(str, buffer);
	}
	return (str);
}

#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*result;

	fd = open("test.txt", O_RDONLY);
	// fd = 0;
	// printf("%s", get_next_line(fd));
	// result = get_next_line(fd);
	// printf("result : %s\n", result);
	while ((result = get_next_line(fd)) != NULL)
	{
		printf("%s", result);
		free(result);
	}
	close(fd);
	//free(result);
	return (0);
}
