/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:38:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/26 14:47:13 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../includes/defines.h"
#include "../includes/functions.h"

void  ft_flood_fill (char **map, int x, int y, e_bool *ret)
{
	if (map == NULL || (x < 1 || y < 1) || y >= ft_get_split_size(map) - 1 || *ret == false)
	{
		*ret = false;
		return;
	}

	if (map[y][x + 1] == ' ' || map[y][x + 1] == 0)
		*ret = false;
	if (map[y + 1][x] == ' ' || map[y + 1][x] == 0)
		*ret = false;
	if (map[y][x - 1] == ' ' || map[y][x - 1] == 0)
		*ret = false;
	if (map[y - 1][x] == ' ' || map[y - 1][x] == 0)
		*ret = false;
	if (*ret == false)
		return;
	map[y][x] = 'o';
	if (map[y][x + 1] == '0')
		ft_flood_fill(map, x + 1, y, ret);
	if (map[y + 1][x] == '0')
		ft_flood_fill(map, x, y + 1, ret);
	if (map[y][x - 1] == '0')
		ft_flood_fill(map, x - 1, y, ret);
	if (map[y - 1][x] == '0')
		ft_flood_fill(map, x, y - 1, ret);
}

e_bool  ft_check_map(char **map)
{
	e_bool	is_ok;
	int		x;
	int		y;

	is_ok = true;
	if (map == NULL)
		return (false);
	y = 0;
	while (map[y] && is_ok == true)
	{
		x = 0;
		while (map[y][x] && is_ok == true)
		{
			if (map[y][x] == '0')
				ft_flood_fill(map, x, y, &is_ok);
			x++;
		}
		y++;
	}
	return (is_ok);
}

e_bool	ft_get_player_position(char **map, double *px, double *py)
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
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
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
