/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsrtn_soft <lsrtn_soft@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:39:38 by lsrtn_soft        #+#    #+#             */
/*   Updated: 2025/08/18 20:50:08 by lsrtn_soft       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include<unistd.h>
# include<stdlib.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);


#endif