/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:40:11 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/10 17:52:25 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_array2d	get_map(const char *path)
{
	t_array2d	map;

	if (!create_map(path, &map))
		ft_error(0, 0, 0, 1);
	if (!check_map(map))
	{
		retrace_free(map.array, map.size.y);
		ft_error(0, 0, 0, 1);
	}
	return (map);
}

static int	create_images(t_mlx *mlx)
{
	mlx->player.ptr = mlx_xpm_file_to_image(
			mlx->ptr, "textures/player.xpm", &mlx->player.size.x,
			&mlx->player.size.y
			);
	mlx->collectable.ptr = mlx_xpm_file_to_image(
			mlx->ptr, "textures/collectable.xpm", &mlx->collectable.size.x,
			&mlx->collectable.size.y
			);
	mlx->wall.ptr = mlx_xpm_file_to_image(
			mlx->ptr, "textures/wall.xpm", &mlx->wall.size.x, &mlx->wall.size.y
			);
	mlx->space.ptr = mlx_xpm_file_to_image(
			mlx->ptr, "textures/space.xpm", &mlx->space.size.x,
			&mlx->space.size.y
			);
	mlx->exit.ptr = mlx_xpm_file_to_image(
			mlx->ptr, "textures/exit.xpm", &mlx->exit.size.x, &mlx->exit.size.y
			);
	if (!mlx->player.ptr || !mlx->collectable.ptr || !mlx->exit.ptr
		|| !mlx->wall.ptr || !mlx->space.ptr
	)
		return ((int)ft_error("", 0, 0, 0));
	return (1);
}

static int	start_mlx_pointers(t_game *game)
{
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		return ((int)ft_error(ERROR_DISPLAYCONEX, 0, 0, 0));
	game->mlx.win_ptr = mlx_new_window(
			game->mlx.ptr,
			game->map.size.x * IMG_SIZE, game->map.size.y * IMG_SIZE,
			"Demon");
	if (!game->mlx.win_ptr)
		return ((int)ft_error(ERROR_DISPLAYCONEX, 0, 0, 0));
	if (!create_images(&game->mlx))
	{
		destroy_images(&game->mlx);
		mlx_destroy_window(game->mlx.ptr, game->mlx.win_ptr);
		return ((int)ft_error(0, 0, 0, 0));
	}
	return (1);
}

/* start_game:
	1. holds the memory address for the t_game object that will be used during
		the whole game.
	2. calls get_map to save a t_array2d object inside the aforementioned t_game
	3. initializes the mlx pointers:
		3.1. mlx_ptr
		3.2. win_ptr
		3.3. creates all the img_ptr
	4. does other things such as:
		4.1. initialize the steps counter
		4.2. get the beginnning position of the player
		4.3. create hooks
		4.4. print the first instance of the map
		4.5. start the loop */
void	start_game(char *path)
{
	t_game	game;

	game.map = get_map(path);
	if (!start_mlx_pointers(&game))
	{
		retrace_free(game.map.array, game.map.size.y);
		ft_error(0, 0, 0, 1);
	}
	game.mlx.steps = 0;
	ft_array2d_search(game.map, 'P', &game.mlx.position);
	mlx_hook(game.mlx.win_ptr, ON_KEYPRESS, 0, key_hook, &game);
	mlx_hook(game.mlx.win_ptr, ON_DESTROY, 0, destroy_hook, &game);
	print_map(&game);
	mlx_loop(game.mlx.ptr);
}
