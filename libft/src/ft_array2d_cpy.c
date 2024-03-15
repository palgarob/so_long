/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2d_cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:47:42 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/13 17:39:09 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*error_aux(const char *message, void (*free_func)(void *),
void *content, int exit_bool)
{
	ft_error(message, free_func, content, exit_bool);
	return (NULL);
}

t_array2d	*ft_array2d_cpy(t_array2d array2d)
{
	t_array2d	*cpy;
	int			i;

	cpy = (t_array2d *)malloc(sizeof(t_array2d));
	if (!cpy)
		return ((t_array2d *)error_aux("", 0, 0, 0));
	cpy->size = array2d.size;
	cpy->array = (char **)malloc(sizeof(char *) * (array2d.size.y + 1));
	if (!cpy->array)
		return ((t_array2d *)error_aux("", free, cpy, 0));
	i = 0;
	while (i < array2d.size.y)
	{
		cpy->array[i] = (char *)malloc(sizeof(char) * (array2d.size.x + 1));
		if (!cpy->array[i])
		{
			retrace_free(cpy->array, i);
			return ((t_array2d *)error_aux("", free, cpy, 0));
		}
		ft_strlcpy(cpy->array[i], array2d.array[i], array2d.size.x + 1);
		i++;
	}
	cpy->array[i] = NULL;
	return (cpy);
}
