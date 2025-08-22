/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsrtn_soft <lsrtn_soft@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:37:55 by lsrtn_soft        #+#    #+#             */
/*   Updated: 2025/08/22 14:55:30 by lsrtn_soft       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

static char	*_fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

static char	*_set_line(char *line_buffer)
{
	char	*left_c;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	left_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	line_buffer[i + 1] = 0;
	return (left_c);
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = _fill_line_buffer(fd, left_c, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_c = _set_line(line);
	return (line);
}*/

char	*read_file(int fd, char *rest, char **buffer)
{
	int		ch_read;
	char	*storage;

	ch_read = 1;
	while (ch_read != 0)
	{
		ch_read = read(fd, *buffer, BUFFER_SIZE);
		if (ch_read == -1)
		{
			free(rest);
			rest = NULL;
		}
		if (ch_read == 0)
			break ;
		*buffer[ch_read] = 0;
		if (!rest)
			rest = ft_calloc(1, 1);
		storage = rest;
		rest = ft_strjoin(storage, *buffer);
		free(storage);
		storage = NULL;
		if (ft_strchr(*buffer, '\n'))
			break ;
	}
	return (rest);
}

char	*next_line(char *line)
{
	char	*rest;
	ssize_t	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (line[len] == 0 || line[1] == 0)
		return (NULL);
	rest = ft_substr(line, len + 1, ft_strlen(line) - len);
	if (!*rest)
	{
		free(rest);
		rest = NULL;
	}
	line[len + 1] = 0;
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*buffer[1024];
	char		*line;
	static char	*rest;
	
	buffer[fd] = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if ((fd < 0 || fd > 1024) || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(rest);
		rest = NULL;
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	if (!buffer[fd])
		return (NULL);
	line = read_file(fd, rest, buffer[fd]);
	free(buffer[fd]);
	if (!line)
		return (NULL);
	rest = next_line(line);
	return (line);
}

/*#include<stdio.h>
#include<fcntl.h>

int	main(void)
{
	int		fd;
	char	*file;

	fd = open("test.txt", O_RDONLY);
	file = get_next_line(fd);
	printf("%s\n", file);
	free(file);
	close(fd);
}*/
