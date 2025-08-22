/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsrtn_soft <lsrtn_soft@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:39:38 by lsrtn_soft        #+#    #+#             */
/*   Updated: 2025/08/22 14:54:18 by lsrtn_soft       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line_bonus(int fd);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *s1, void *s2, size_t n);
void	*ft_realloc(void *ptr, size_t size);
char	*ft_strdup(char *s1);
char 	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	fill_str(char *res, char *s1, char *s2);

#endif