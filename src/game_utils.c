/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:15:08 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/09 14:38:30 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_image(t_game *game, int x, int y)
{
	mlx_put_image_to_window(
		game->mlx.ptr, game->mlx.win_ptr, game->mlx.space.ptr,
		x * IMG_SIZE, y * IMG_SIZE
		);
	if (game->map.array[y][x] == '1')
		mlx_put_image_to_window(
			game->mlx.ptr, game->mlx.win_ptr, game->mlx.wall.ptr,
			x * IMG_SIZE, y * IMG_SIZE
			);
	else if (game->map.array[y][x] == 'C')
		mlx_put_image_to_window(
			game->mlx.ptr, game->mlx.win_ptr, game->mlx.collectable.ptr,
			x * IMG_SIZE, y * IMG_SIZE
			);
	else if (game->map.array[y][x] == 'E')
		mlx_put_image_to_window(
			game->mlx.ptr, game->mlx.win_ptr, game->mlx.exit.ptr,
			x * IMG_SIZE, y * IMG_SIZE
			);
	else if (game->map.array[y][x] == 'P')
		mlx_put_image_to_window(
			game->mlx.ptr, game->mlx.win_ptr, game->mlx.player.ptr,
			x * IMG_SIZE, y * IMG_SIZE
			);
}

/* Destroys all the img_ptr in case they are not a null void * */
void	destroy_images(t_mlx *mlx)
{
	if (mlx->player.ptr)
		mlx_destroy_image(mlx->ptr, mlx->player.ptr);
	if (mlx->collectable.ptr)
		mlx_destroy_image(mlx->ptr, mlx->collectable.ptr);
	if (mlx->wall.ptr)
		mlx_destroy_image(mlx->ptr, mlx->wall.ptr);
	if (mlx->space.ptr)
		mlx_destroy_image(mlx->ptr, mlx->space.ptr);
	if (mlx->exit.ptr)
		mlx_destroy_image(mlx->ptr, mlx->exit.ptr);
}

/* Prints the map into the window, first the spaces in all tiles and then the
rest according to the array */
void	print_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map.size.y)
	{
		while (x < game->map.size.x)
		{
			print_image(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
