/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:58:53 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/02 08:32:26 by ntodisoa         ###   ########.fr       */
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

void draw_sprite(t_data *data)
{
    int y;
    int max;
    t_img *sprite;
    t_img *screen;
    t_dda *dda;

    sprite = &data->sprite.image;
    dda = &data->dda;
    y = data->sprite.draw_start;
    screen = &data->screen;

    if (y < 0)
        y = 0;
    
    max = data->sprite.draw_end;
    if (data->sprite.draw_end >= SCREENHEIGHT)
        max = SCREENHEIGHT - 1;

    for (int stripe = data->sprite.screen_x; stripe < data->sprite.screen_x + data->sprite.screen_height; stripe++)
    {
        if (stripe >= 0 && stripe < SCREENWIDTH)
        {
            int tex_x = (int)((stripe - data->sprite.screen_x) * ((double)sprite->width / data->sprite.screen_height));

            for (y = data->sprite.draw_start; y <= data->sprite.draw_end; y++)
            {
                int new_y = (int)((y - data->sprite.draw_start) * ((double)sprite->height / (data->sprite.draw_end - data->sprite.draw_start)));

                if (new_y >= 0 && new_y < sprite->height)
                {
                    int color = sprite->pixels[(int)(new_y * sprite->width + tex_x)];

                    if (color & 0xFF000000 != 0x000000)
                    {
                        screen->pixels[y * SCREENWIDTH + stripe] = color;
                    }
                }
            }
        }
    }

    for (int i = data->sprite.draw_end + 1; i < SCREENHEIGHT; i++)
    {
        screen->pixels[i * SCREENWIDTH + data->dda.x] = 0x331111;
    }
}