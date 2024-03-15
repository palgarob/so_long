/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:56:41 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/10 17:22:46 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Saves a t_array2d in the map pointer, taken from the file at the path */
int	create_map(const char *path, t_array2d *map)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ((int)ft_error("", 0, 0, 0));
	map->array = ft_array2d_create(fd, 10);
	if (!map->array)
		ft_error("", 0, 0, 0);
	if (!ft_array2d_size(map->array, &map->size))
		return (0);
	return (1);
}
