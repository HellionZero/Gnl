/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsrtn_soft <lsrtn_soft@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:38:13 by lsrtn_soft        #+#    #+#             */
/*   Updated: 2025/08/24 13:15:39 by lsrtn_soft       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char			*dest;
	unsigned int	i;

	dest = (char *) malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if(!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (malloc(1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    char *res;
    int i;
    int j;
    
    i = 0;
    j = 0;
    res = (char *) malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1) * sizeof(char));
    if (!res)
        return (NULL);
    while (s1[i])
	{
        res[i] = s1[i];
		i++;
	}
    while (s2[j])
	{
        res[j + i] = s2[j];
		j++;
	}
    res[j + i] = 0;
    return (res);
}

void	*ft_calloc(size_t count, size_t size)
{
	char		*chr;
	size_t		i;

	i = 0;
	chr = malloc(count * size);
	if (!chr)
		return (NULL);
	while (i < count * size)
	{
		chr[i] = 0;
		i++;
	}
	return (chr);
}

void	*ft_memcpy(void *s1, void *s2, size_t n)
{
	size_t	i;
	char	*src;
	char	*dst;

	dst = (char *)s1;
	src = (char *) s2;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
void	*ft_realloc(void *ptr, size_t size)
{
	void	*rsz_ptr;

	if (!ptr)
		return (malloc(size));
	if (!size)
		return (ptr);
	rsz_ptr = malloc(size);
	ft_memcpy(rsz_ptr, ptr, size);
	return (rsz_ptr);
}

char *ft_strchr(const char *s, int c)
{
    unsigned int    i;
    char            cc;
    
    cc = (char) c;
    i = 0;
    while (s[i])
    {
        if (s[i] == cc)
            return ((char *) &s[i]);
        i++;
    }
	return (0);
}
