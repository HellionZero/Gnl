/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsrtn_soft <lsrtn_soft@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:38:13 by lsrtn_soft        #+#    #+#             */
/*   Updated: 2025/08/18 20:49:43 by lsrtn_soft       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		chr[i] == 0;
		i++;
	}
	return (chr);
}

char	*ft_strdup()
{
	
}