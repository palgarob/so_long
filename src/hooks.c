/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:49:00 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/13 17:32:34 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	add_print_step(t_game *game)
{
	game->mlx.steps++;
	ft_printf("%d\n", game->mlx.steps);
}

static void	run_into_wall(t_game *game, int keycode)
{
	if (keycode == KEY_W || keycode == KEY_TOP)
		game->mlx.position.y += 1;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		game->mlx.position.y -= 1;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		game->mlx.position.x += 1;
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		game->mlx.position.x -= 1;
}

static void	check_movement(t_game *game, int keycode)
{
	t_point	position_buf;

	if (keycode != KEY_A && keycode != KEY_D && keycode != KEY_W
		&& keycode != KEY_S && keycode != KEY_TOP && keycode != KEY_DOWN
		&& keycode != KEY_LEFT && keycode != KEY_RIGHT)
		return ;
	if (
		game->map.array[game->mlx.position.y][game->mlx.position.x] == 'E' &&
		!ft_array2d_search(game->map, 'C', &position_buf))
	{
		ft_printf("Congratulations, you won!");
		destroy_hook(game);
	}
	else if (
		(game->map.array[game->mlx.position.y][game->mlx.position.x] == 'E'
		&& ft_array2d_search(game->map, 'C', &position_buf))
		|| game->map.array[game->mlx.position.y][game->mlx.position.x] == '1'
	)
		run_into_wall(game, keycode);
	else
		add_print_step(game);
}

/* destroy_hook:
1. frees the map array
2. destroys the window
3. destroy the images
4. prints an exiting message
5. exits the program */
int	destroy_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	retrace_free(game->map.array, game->map.size.y);
	mlx_destroy_window(game->mlx.ptr, game->mlx.win_ptr);
	destroy_images(&game->mlx);
	ft_printf("\nYou have exited the program");
	exit(0);
}

/* key_hook takes the key pressed as a parameter and changes the position of the
player accordingly, then checks how the movement should be processed. After
that, looks for the previous position of the player in the map array, changes it
for a space, inserts the new player position in the map array and prints the
whole map again. */
int	key_hook(int keycode, void *param)
{
	t_game	*game;
	t_point	position_buf;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
		destroy_hook(game);
	else if (keycode == KEY_W || keycode == KEY_TOP)
		game->mlx.position.y -= 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->mlx.position.y += 1;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		game->mlx.position.x -= 1;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		game->mlx.position.x += 1;
	check_movement(game, keycode);
	ft_array2d_search(game->map, 'P', &position_buf);
	game->map.array[position_buf.y][position_buf.x] = '0';
	game->map.array[game->mlx.position.y][game->mlx.position.x] = 'P';
	print_map(game);
	return (0);
}
