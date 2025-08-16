/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsrtn_soft <lsrtn_soft@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:37:55 by lsrtn_soft        #+#    #+#             */
/*   Updated: 2025/08/16 00:25:54 by lsrtn_soft       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->string[i] && i < BUFFER_SIZE)
		{
			if (list->string[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;
	
	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return (NULL);
		}
		buf[char_read] = 0;
		add_node(list, buf);
	}
}

void	add_node(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*current_node;

	current_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	if (current_node == NULL)
		*list = new_node;
	else
		current_node->next = new_node;
	new_node->string = buf;
	new_node->next = NULL;
}

t_list	*find_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	polished_list(t_list **list)
{
	t_list	*last;
	t_list	*clean;
	char	*buf;
	int		i;
	int		j;

	buf = malloc(BUFFER_SIZE + 1);
	clean = malloc(sizeof(t_list));
	if (!buf || !clean)
		return ;
	last = find_last_node(*list);
	i = 0;
	j = 0;
	while (last->string[i] && last->string[i] != '\n')
		i++;
	while (last->string[i])
	{
		buf[j] = last->string[i];
		i++;
		j++;
	}
	buf[j] = '\0';
	clean->string = buf;
	clean->next = NULL;
	dealloc(list, clean, buf);
}

void	dealloc(t_list **list, t_list *clean, char *buf)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->string);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean->string[0])
		*list = clean;
	else
	{
		free(buf);
		free(clean);
	}
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next;

	if (!list)
		return (NULL);
	str_len = line_len(list);
	next = malloc(str_len + 1);

	copy_str(list, next);
	return (next);
}

int	line_len(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->string[i] != 0)
		{
			if (list->string[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}

	return (len);
}

void	copy_str(t_list *list, char *str)
{
	int	i;
	int	j;

	if (list == NULL)
		return ;
	j = 0;
	while (list)
	{
		while (list->string[i] != 0)
		{
			if (list->string[i] == '\n')
			{
				str[j] = '\n';
				j++;
				str[j] = '\0';
			}
			str[j] = list->string[i];
			i++;
			j++;
		}
		list = list->next;
	}
	str[j] = 0;
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next = get_line(list);
	polished_list(&list);
	return (next);
}
