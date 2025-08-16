/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsrtn_soft <lsrtn_soft@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:39:38 by lsrtn_soft        #+#    #+#             */
/*   Updated: 2025/08/15 23:10:11 by lsrtn_soft       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42

# include<unistd.h>
# include<stdlib.h>

typedef struct s_list
{
	char			*string;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

#endif