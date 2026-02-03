/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:11:23 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/01/30 14:41:25 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *s1, char *s2)
{
	char	*temp;

	if (!s1)
		return (ft_strjoin("", s2));
	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next = ft_calloc(ft_strlen(buffer) - i, 1);
	if (!next)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	free(buffer);
	return (next);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		bytes;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(res), NULL);
		buffer[bytes] = '\0';
		if (bytes == 0)
			break ;
		res = ft_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (!res[0])
		return (free(res), NULL);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
