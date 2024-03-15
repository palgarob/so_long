/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:05:09 by pedropaloma       #+#    #+#             */
/*   Updated: 2023/12/10 17:50:55 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* The main:
1. checks the correct number of arguments
2. checks the correct file type
3. calls the start_game function */
int	main(int argc, char *argv[])
{
	if (argc != 2)
		ft_error(ERROR_ARGNUM, 0, 0, 1);
	if (
		!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))
		|| !(
			ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))
			== &argv[1][ft_strlen(argv[1]) - 4]
	)
	)
		ft_error(ERROR_BERFILE, 0, 0, 1);
	start_game(argv[1]);
	return (0);
}
