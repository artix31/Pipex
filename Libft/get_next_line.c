/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:11:46 by amashhad          #+#    #+#             */
/*   Updated: 2025/01/24 00:10:57 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_gnl(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_storage(char *line)
{
	char	*new_line;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gnl(line, '\n');
	if (!ptr)
	{
		new_line = NULL;
		return (ft_free_gnl(&line));
	}
	else
		len = (ptr - line) + 1;
	if (!line[len])
		return (ft_free_gnl(&line));
	new_line = ft_substr_gnl(line, len, ft_strlen(line) - len);
	ft_free_gnl(&line);
	if (!new_line)
		return (NULL);
	return (new_line);
}

char	*new_buf(char *line)
{
	char	*buf;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gnl(line, '\n');
	len = (ptr - line) + 1;
	buf = ft_substr_gnl(line, 0, len);
	if (!buf)
		return (NULL);
	return (buf);
}

char	*readbuf(int fd, char *line)
{
	int		byte;
	char	*buffer;

	byte = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free_gnl(&line));
	buffer[0] = '\0';
	while (byte > 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		byte = read (fd, buffer, BUFFER_SIZE);
		if (byte > 0)
		{
			buffer[byte] = '\0';
			line = ft_strjoin_gnl(line, buffer);
		}
	}
	free(buffer);
	if (byte == -1)
		return (ft_free_gnl(&line));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[FD_SIZE] = {NULL};
	char		*buf;

	if (fd < 0)
		return (NULL);
	if ((line[fd] && !ft_strchr_gnl(line[fd], '\n')) || !line[fd])
		line[fd] = readbuf (fd, line[fd]);
	if (!line[fd])
		return (NULL);
	buf = new_buf(line[fd]);
	if (!buf)
		return (ft_free_gnl(&line[fd]));
	line[fd] = clean_storage(line[fd]);
	return (buf);
}
