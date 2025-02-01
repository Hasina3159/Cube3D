/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:08:23 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/01 16:11:21 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void    ft_draw_square (t_data *data, int x, int y, int color)
{
	int	*img;
	int		tmp_x;
	int     tmp_y;

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

void ft_draw_mini_map(t_data *data)
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
				ft_draw_square(data, x * SQUARE_SIZE + x, y * SQUARE_SIZE + y, 0x00FF0000);
			x++;
		}
		y++;
	}
	ft_draw_square(data, (int)data->pos_y * SQUARE_SIZE + (int)data->pos_y, (int)data->pos_x * SQUARE_SIZE + (int)data->pos_x, 0x55FFFF00);
}
