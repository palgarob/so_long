/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2d_valid_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:54:36 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/13 17:38:59 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_fillable(char **tab, t_point size,
t_point position, const char *fillable)
{
	int	checker;
	int	i;

	i = 0;
	checker = 0;
	while (fillable[i])
	{
		if (tab[position.y][position.x] == fillable[i++])
		{
			checker = 1;
			break ;
		}
	}
	if (
		position.x < size.x
		&& position.x >= 0
		&& position.y < size.y
		&& position.y >= 0
		&& checker
	)
		return (1);
	return (0);
}

static void	flood_fill(char **tab, t_point size,
t_point position, const char *fillable)
{
	t_point	next;

	if (check_fillable(tab, size, position, fillable))
	{
		tab[position.y][position.x] = 'F';
		next.y = position.y;
		next.x = position.x + 1;
		flood_fill(tab, size, next, fillable);
		next.y = position.y + 1;
		next.x = position.x;
		flood_fill(tab, size, next, fillable);
		next.y = position.y;
		next.x = position.x - 1;
		flood_fill(tab, size, next, fillable);
		next.y = position.y - 1;
		next.x = position.x;
		flood_fill(tab, size, next, fillable);
	}
}

void	asdf(int *epa, t_array2d *cpy)
{
	t_point	exi;

	ft_array2d_search(*cpy, 'E', &exi);
	if (
		cpy->array[exi.y + 1][exi.x] == '1'
		&& cpy->array[exi.y - 1][exi.x] == '1'
		&& cpy->array[exi.y][exi.x + 1] == '1'
		&& cpy->array[exi.y][exi.x - 1] == '1'
	)
		*epa = 1;
}

int	ft_array2d_valid_path(t_array2d array2d,
t_point begin, const char *floodplain)
{
	t_array2d	*cpy;
	int			check;

	cpy = ft_array2d_cpy(array2d);
	if (!cpy)
		return (0);
	flood_fill(cpy->array, cpy->size, begin, floodplain);
	check = 0;
	while (*floodplain)
	{
		if (ft_array2d_search(*cpy, *floodplain, &begin))
			check = 1;
		floodplain++;
	}
	asdf(&check, cpy);
	if (check)
	{
		retrace_free(cpy->array, cpy->size.y);
		return ((int)ft_error(ERROR_VALIDPATH, free, cpy, 0));
	}
	retrace_free(cpy->array, cpy->size.y);
	free(cpy);
	return (1);
}

/* int	main(void)
{
	t_array2d	array2d;
	int			fd;
	int			i;
	t_point		begin;
	
	fd = open("../../map/map1.ber", O_RDONLY);
	array2d.array = ft_array2d_create(fd, '\n');
	ft_array2d_size(array2d.array, &array2d.size);
	i = 0;
	while (array2d.array[i])
		ft_printf("%s\n", array2d.array[i++]);
	ft_array2d_search(array2d, 'P', &begin);
	if (ft_array2d_valid_path(array2d, begin, "0CEP"))
		ft_printf("HOLA\n");
	else
		ft_printf("ADIOS\n");
	flood_fill(array2d.array, array2d.size, begin, "E0CP");
	i = 0;
	while (array2d.array[i])
		ft_printf("%s\n", array2d.array[i++]);
} */
