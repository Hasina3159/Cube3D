/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:38:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/04/04 14:09:47 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	ft_flood_fill(char **map, int x, int y, t_bool *ret)
{
	if (map == NULL || (x < 1 || y < 1) || y >= (int)ft_get_split_size(map) - 1
		|| *ret == false)
	{
		*ret = false;
		return ;
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
		return ;
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

t_bool	ft_check_map(char **map)
{
	t_bool	is_ok;
	int		x;
	int		y;
	char	**new_map;

	new_map = NULL;
	new_map = ft_clone_map(map);
	is_ok = true;
	if (map == NULL || new_map == NULL)
		return (false);
	y = 0;
	while (new_map[y] && is_ok == true)
	{
		x = 0;
		while (new_map[y][x] && is_ok == true)
		{
			if (new_map[y][x] == '0')
				ft_flood_fill(new_map, x, y, &is_ok);
			x++;
		}
		y++;
	}
	ft_free_split(new_map);
	return (is_ok);
}

char	ft_get_player_position(char **map, double *px, double *py)
{
	int		x;
	int		y;
	char	c;

	if (map == NULL)
		return (false);
	y = -1;
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W'
				|| map[y][x] == 'E')
			{
				c = map[y][x];
				map[y][x] = '0';
				*px = (double)x + 0.5;
				*py = (double)y + 0.5;
				return (c);
			}
			x++;
		}
	}
	return (0);
}

t_bool	ft_check_map_char_loop(int *i, int *player_count, char **map)
{
	int	j;

	j = 0;
	while (map[*i][j])
	{
		if (ft_is_valid_char(map[*i][j], "NSEW"))
			*player_count = *player_count + 1;
		if (!ft_is_valid_char(map[*i][j], "01NSEWDB "))
			return (false);
		j++;
	}
	*i = *i + 1;
	return (true);
}

t_bool	ft_check_map_char(char **map)
{
	int	i;
	int	player_count;

	i = 0;
	player_count = 0;
	if (map == NULL)
		return (false);
	while (map[i])
	{
		if (ft_strlen(map[i]) == 0)
			return (false);
		if (ft_check_map_char_loop(&i, &player_count, map) == false)
			return (false);
	}
	if (player_count != 1)
		return (false);
	return (true);
}
