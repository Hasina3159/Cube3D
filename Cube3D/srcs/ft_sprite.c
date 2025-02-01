/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:58:53 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/01 16:24:11 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include "../includes/defines.h"
#include "../includes/functions.h"

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
				//map[y][x] = 'o';
				*px = (double)x + 0.5;
				*py = (double)y + 0.5;
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}


void	draw_sprite(t_data *data)
{
	int	y;
	int	i;
	int	max;
	t_img	*sprite;
	t_img	*screen;
	t_dda	*dda;

	sprite = &data->sprite.image;
	dda = &data->dda;
	y = data->sprite.draw_start;
	i = 0;
	key_render (data);

	screen = &data->screen;
	if (y < 0)
		y = 0;
	max = data->sprite.draw_end;
	if (data->sprite.draw_end >= SCREENHEIGHT)
		max = SCREENHEIGHT - 1;
	while (i <= max)
	{
		screen->pixels[i * SCREENWIDTH + data->dda.x] = 0x1133ff;
		i++;
	}
	while (y <= max)
	{
		int	new_y;
		new_y = (int)((y - data->sprite.draw_start) * ((double)sprite->height / (data->sprite.draw_end - data->sprite.draw_start)));
		if (y >= SCREENHEIGHT)
			break;
		screen->pixels[y * SCREENWIDTH + data->dda.x] = sprite->pixels[(int)(new_y * sprite->width + sprite->sprite_x)];
		y++;
	}
	i = max + 1;
	while (max > 0 && i <= SCREENHEIGHT)
	{
		screen->pixels[i * SCREENWIDTH + data->dda.x] = 0x331111;
		i++;
	}
}
