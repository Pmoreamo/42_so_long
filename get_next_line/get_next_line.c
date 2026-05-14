/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:54:24 by pmorello          #+#    #+#             */
/*   Updated: 2024/08/11 15:38:04 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_fd(int fd, char *buffer)
{
	char	*new_buffer;
	int		b_llegits;

	new_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	b_llegits = 1;
	if (!new_buffer)
		return (free(buffer), buffer = NULL, NULL);
	while (b_llegits > 0 && !ft_strchr(buffer, '\n'))
	{
		b_llegits = read(fd, new_buffer, BUFFER_SIZE);
		if (b_llegits > 0)
		{
			new_buffer[b_llegits] = '\0';
			buffer = ft_strjoin(buffer, new_buffer);
		}
	}
	free(new_buffer);
	if (b_llegits < 0)
		return (free(buffer), buffer = NULL, NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_fd(fd, buffer);
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	line = ft_read_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = ft_new_line(buffer);
	return (line);
}
