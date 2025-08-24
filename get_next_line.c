/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsrtn_soft <lsrtn_soft@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:37:55 by lsrtn_soft        #+#    #+#             */
/*   Updated: 2025/08/24 16:02:22 by lsrtn_soft       ###   ########.fr       */
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

char	*read_file(int fd, char *remain)
{
	char	*storage;
	char	*tmp;
	ssize_t	ch_read;

	storage = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!storage)
		return (NULL);
	ch_read = 1;
	while (ch_read > 0 && !ft_strchr(storage, '\n'))
	{
		ch_read = read(fd, storage, BUFFER_SIZE);
		if (ch_read == -1)
		{
			free(remain);
			return (NULL);
		}
		storage[ch_read] = 0;
		if (!remain)
			remain = ft_calloc(1, 1);
		tmp = remain;
		remain = ft_strjoin(tmp, storage);
		free(tmp);
		tmp = NULL;
	}
	return (remain);
}

char	*get_line(char *line)
{
	char	*tmp;
	ssize_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	tmp = (char *)ft_calloc(i + 2, sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		tmp[i] = line[i];
		i++;
	}
	free(line);
	line = NULL;
	return (tmp);
}

char	*get_remain(char *line)
{
	char	*remain;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		remain = ft_substr(line, i + 1, (ft_strlen(line) - i));
		if (!remain)
		{
			free(line);
			return (NULL);
		}
		return (remain);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = read_file(fd, remain);
	remain = get_remain(line);
	line = get_line(line);
	return (line);
}

#include<stdio.h>
#include<fcntl.h>

int	main(void)
{
	char	*text;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	text = get_next_line(fd);
	printf("%s\n", text);
	text = get_next_line(fd);
	printf("%s\n", text);
	text = get_next_line(fd);
	printf("%s\n", text);
	free(text);
	close(fd);
}