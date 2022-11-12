/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:21:04 by yel-mass          #+#    #+#             */
/*   Updated: 2022/11/10 09:47:14 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

char	*ft_myread(int fd, char *buf)
{
	int		bytes;
	char	*new_buffer;

	bytes = 1;
	new_buffer = malloc(BUFFER_SIZE + 1);
	if (!new_buffer)
		return (NULL);
	while (bytes > 0 && ft_strchr(buf, '\n') == -1)
	{
		bytes = read(fd, new_buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free (new_buffer);
			if (!buf)
				return (NULL);
			return (buf);
		}
		new_buffer[bytes] = '\0';
		if (buf != 0)
			buf = ft_strjoin(buf, new_buffer);
		else
			buf = ft_strdup(new_buffer);
	}
	free(new_buffer);
	return (buf);
}

char	*ft_myline(char *buff)
{
	int		i;
	char	*line;

	if (buff[0] == '\0')
		return (NULL);
	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	line = ft_substr(buff, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_mynewbuffer(char *buf)
{
	int		i;
	char	*newbuffer;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	newbuffer = ft_substr(buf, i + 1, ft_strlen(buf) - i);
	if (!newbuffer)
	{
		free(buf);
		return (NULL);
	}
	free(buf);
	return (newbuffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(buffer[fd], '\n') == -1)
		buffer[fd] = ft_myread(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = ft_myline(buffer[fd]);
	buffer[fd] = ft_mynewbuffer(buffer[fd]);
	return (line);
}
