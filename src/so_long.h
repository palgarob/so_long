/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:56:33 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/13 17:59:59 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// for open, close, read and write
# include <unistd.h>
// for open's flags
# include <fcntl.h>
// for exit, malloc and free
# include <stdlib.h>
// for strerror
# include <string.h>
// for perror
# include <stdio.h>
// for errno
# include <errno.h>
// for the MiniLibX
# include "../minilibx_opengl_20191021/mlx.h"
// for the libft
# include "../libft/src/libft.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_TOP 126
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_LEFT 123

# define ON_KEYPRESS 2
# define ON_DESTROY 17

# define ERROR_BORDER "Error\nThe borders of the map must be walls"
# define ERROR_CHAR "Error\nThe map only admits the following chars: \"10PCE\""
# define ERROR_BEGINPOINT "Error\nThere must be only one beginning point"
# define ERROR_NUMCOLLECTABLE "Error\nThere must be at least one collectable"
# define ERROR_NUMEXIT "Error\nThere must only be one exit"
# define ERROR_ARGNUM "Error\nThe number of arguments must be 1"
# define ERROR_BERFILE "Error\nThe file passed must be of type .ber"
# define ERROR_DISPLAYCONEX "Error\nConnection to the display failed"

# define IMG_SIZE 80

typedef struct s_img
{
	void	*ptr;
	t_point	size;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win_ptr;
	t_img	player;
	t_point	position;
	int		steps;
	t_img	wall;
	t_img	exit;
	t_img	space;
	t_img	collectable;
}	t_mlx;

typedef struct s_game
{
	t_mlx		mlx;
	t_array2d	map;
}	t_game;

int		create_map(const char *path, t_array2d *map);
int		check_map(t_array2d map);

void	print_map(t_game *game);
void	start_game(char *path);
void	destroy_images(t_mlx *mlx);

int		destroy_hook(void *param);
int		key_hook(int keycode, void *mlx);

#endif
