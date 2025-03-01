/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 08:26:52 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/01 08:27:16 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

e_bool	ft_get_sprite_position(char **map, double *px, double *py)
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
				map[y][x] = 'o';
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
