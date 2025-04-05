/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 08:26:52 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/30 10:42:17 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

t_bool	ft_get_sprite_position(char **map, double *px, double *py)
{
	int	x;
	int	y;

	if (map == NULL)
		return (false);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'B')
			{
				map[y][x] = '0';
				*px = (double)x;
				*py = (double)y;
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}
