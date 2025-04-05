/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:08:23 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/30 10:42:09 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void	ft_draw_square(t_data *data, int x, int y, int color)
{
	int	*img;
	int	tmp_x;
	int	tmp_y;

	img = data->screen.pixels;
	tmp_x = x;
	while (tmp_x < x + SQUARE_SIZE)
	{
		tmp_y = y;
		while (tmp_y < y + SQUARE_SIZE)
		{
			img[tmp_y * SCREENWIDTH + tmp_x] = color;
			tmp_y++;
		}
		tmp_x++;
	}
}

void	ft_draw_mini_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->world_map[y])
	{
		x = 0;
		while (data->world_map[y][x])
		{
			if (data->world_map[y][x] == '1')
				ft_draw_square(data, x * SQUARE_SIZE + x, y * SQUARE_SIZE + y,
					0x00FF0000);
			else if (data->world_map[y][x] == 'D')
				ft_draw_square(data, x * SQUARE_SIZE + x, y * SQUARE_SIZE + y,
					0x0011FF11);
			x++;
		}
		y++;
	}
	ft_draw_square(data, (int)data->pos_y * SQUARE_SIZE + (int)data->pos_y,
		(int)data->pos_x * SQUARE_SIZE + (int)data->pos_x, 0x55FFFF00);
}

char	**ft_clone_map(char **map)
{
	int		i;
	int		j;
	char	**new_map;

	new_map = (char **)malloc(sizeof(char *) * (ft_get_split_size(map) + 1));
	if (!new_map)
		return (NULL);
	i = -1;
	while (map[++i])
		new_map[i] = ft_strdup(map[i]);
	new_map[i] = NULL;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (new_map[i][j])
		{
			if (new_map[i][j] != '1' && new_map[i][j] != ' ')
				new_map[i][j] = '0';
			j++;
		}
	}
	return (new_map);
}
