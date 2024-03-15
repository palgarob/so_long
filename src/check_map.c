/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:24:46 by pedropaloma       #+#    #+#             */
/*   Updated: 2023/12/11 17:25:19 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This file contains the function check_map. This function first gets the
size of the map using the path parameter and the check_size function and then
checks:
1.1 that the map has the correct characters, i.e. "01PCE"
1.2 that there is the correct number of characters, i.e. 1P, 1E and >=1C
2. that the borders of the map are walls (1s)
3. that there is a valid path from the beginning point of the P to the exit
(E).
If every criteria is met, then the function returns 1, else 0.*/

#include "so_long.h"

static int	check_map_borders(t_array2d map)
{
	int	i;

	i = 0;
	while (map.array[0][i])
	{
		if (map.array[0][i] != '1')
			return ((int)ft_error(ERROR_BORDER, 0, 0, 0));
		if (map.array[map.size.y - 1][i] != '1')
			return ((int)ft_error(ERROR_BORDER, 0, 0, 0));
		i++;
	}
	i = 0;
	while (i < map.size.y)
	{
		if (map.array[i][0] != '1')
			return ((int)ft_error(ERROR_BORDER, 0, 0, 0));
		if (map.array[i][map.size.x - 1] != '1')
			return ((int)ft_error(ERROR_BORDER, 0, 0, 0));
		i++;
	}
	return (1);
}

static int	count_chars(char x, int *p, int *c, int *e)
{
	if (x == 'P')
		*p += 1;
	else if (x == 'C')
		*c += 1;
	else if (x == 'E')
		*e += 1;
	else if (x != '1' && x != '0')
		return ((int)ft_error(ERROR_CHAR, 0, 0, 0));
	return (1);
}

static int	count_map_chars(t_array2d map, int *p, int *c, int *e)
{
	t_point	position;

	*p = 0;
	*c = 0;
	*e = 0;
	position.x = 0;
	position.y = 0;
	while (position.y < map.size.y)
	{
		while (position.x < map.size.x)
		{
			if (!count_chars(map.array[position.y][position.x], p, c, e))
				return (0);
			position.x++;
		}
		position.y++;
		position.x = 0;
	}
	return (1);
}

static int	check_map_chars(t_array2d map)
{
	int	p_count;
	int	c_count;
	int	e_count;

	if (!count_map_chars(map, &p_count, &c_count, &e_count))
		return (0);
	if (p_count != 1)
		return (ft_error(ERROR_BEGINPOINT, 0, 0, 0));
	if (c_count < 1)
		return (ft_error(ERROR_NUMCOLLECTABLE, 0, 0, 0));
	if (e_count != 1)
		return (ft_error(ERROR_NUMEXIT, 0, 0, 0));
	return (1);
}

/* This function returns a 1 if the map is valid and a 0 otherwise. It checks:
1. That there are only valid chars and a correct number of each of them
2. That the borders of the map are walls
3. that there is a valid a path from the beginning point of the player
to the exit */
int	check_map(t_array2d map)
{
	t_point	begin;

	if (!check_map_chars(map))
		return (0);
	if (!check_map_borders(map))
		return (0);
	ft_array2d_search(map, 'P', &begin);
	if (!ft_array2d_valid_path(map, begin, "0PC"))
		return (0);
	return (1);
}
