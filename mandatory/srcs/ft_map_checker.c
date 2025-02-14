/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:38:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/14 12:41:55 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../includes/defines.h"
#include "../includes/functions.h"

e_bool	ft_is_valid_char (char c, char *s)
{
	int	i;

	if (s == NULL)
		return (false);
	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (true);
		i++;
	}
	return (false);
}


void  ft_flood_fill (char **map, int x, int y, e_bool *ret)
{
	if (map == NULL || (x < 1 || y < 1) || y >= ft_get_split_size(map) - 1 || *ret == false)
	{
		*ret = false;
		return;
	}

	if (ft_is_valid_char(map[y][x + 1], " ") || map[y][x + 1] == 0)
		*ret = false;
	if (ft_is_valid_char(map[y + 1][x], " ") || map[y + 1][x] == 0)
		*ret = false;
	if (ft_is_valid_char(map[y][x - 1], " ") || map[y][x - 1] == 0)
		*ret = false;
	if (ft_is_valid_char(map[y - 1][x], " ") || map[y - 1][x] == 0)
		*ret = false;
	if (*ret == false)
	{
		printf("pos (%d, %d)\n", x, y);
		return;
	}
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
			if (is_ok == false)
			{
				printf("Error!\nInvalid Map\n");
				return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

char	ft_get_player_position(char **map, double *px, double *py)
{
	int		x;
	int		y;
	char	c;

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
				c = map[y][x];
				map[y][x] = 'o';
				*px = (double)x;
				*py = (double)y;
				return (c);
			}
			x++;
		}
		y++;
	}
	return (0);
}

e_bool ft_check_map_char(char **map)
{
	int	i;
	int	j;
	int	perso_count;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[j])
		{
			if (!ft_is_valid_char(map[i][j], "01NSEW "))
			{
				printf("Error!\nMap contains Invalid character [%c].\n", map[i][j]);
				return (false);
			}
			else if (ft_is_valid_char(map[i][j], "01NSEW"))
			 	perso_count++;
			j++;
		}
		i++;
	}
	return (true);
}
