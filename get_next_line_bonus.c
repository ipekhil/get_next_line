/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiipek <hiipek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:39:53 by hiipek            #+#    #+#             */
/*   Updated: 2024/12/28 18:35:08 by hiipek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(char *dst, int fd)
{
	char	*buffer;
	int		read_bytes;

	if (!dst)
	{
		dst = malloc(sizeof(char) * 1);
		if (!dst)
			return (NULL);
		dst[0] = '\0';
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_gnl_strchr(dst, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(dst), free(buffer), NULL);
		buffer[read_bytes] = '\0';
		dst = ft_gnl_strjoin(dst, buffer);
	}
	free(buffer);
	return (dst);
}

char	*ft_get_line(char *dst)
{
	char	*line;
	int		i;

	i = 0;
	if (!dst || !dst[i])
		return (NULL);
	while (dst[i] && dst[i] != '\n')
		i++;
	if (dst[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (dst[i] && dst[i] != '\n')
	{
		line[i] = dst[i];
		i++;
	}
	if (dst[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_left_line(char *buff)
{
	char	*rst;
	int		i;
	int		j;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
		return (free(buff), NULL);
	if (buff[i] == '\n')
		i++;
	rst = malloc(sizeof(char) * (ft_gnl_strlen(buff) - i + 1));
	if (!rst)
		return (free(buff), NULL);
	j = 0;
	while (buff[i])
		rst[j++] = buff[i++];
	rst[j] = '\0';
	free(buff);
	return (rst);
}

char	*get_next_line(int fd)
{
	static char	*buff[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = ft_read_line(buff[fd], fd);
	if (!buff[fd])
		return (NULL);
	line = ft_get_line(buff[fd]);
	buff[fd] = ft_get_left_line(buff[fd]);
	return (line);
}
