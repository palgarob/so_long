/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:13:38 by pepaloma          #+#    #+#             */
/*   Updated: 2023/12/11 17:32:41 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This file contains functions for error handling*/

#include "libft.h"

int	ft_error(const char*message,
void (*free_func)(void *), void *content, int exit_bool)
{
	if (message)
		perror(message);
	if (free_func)
		free_func(content);
	if (exit_bool)
		exit(1);
	else
		return (0);
}
