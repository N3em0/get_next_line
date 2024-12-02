/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:14:11 by egache            #+#    #+#             */
/*   Updated: 2024/12/02 18:34:41 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

#define BUFFER_SIZE 10

char	*get_next_line(int fd)
{
	static char	*buffer;
	int	fd_read;

	// //buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	// if (!buffer)
	// {
	// 	return (NULL);
	// }
	buffer[BUFFER_SIZE + 1] = '\0';
	while (fd_read != 0)
	{


}
}
