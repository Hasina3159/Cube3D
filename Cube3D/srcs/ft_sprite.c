/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:58:53 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/08 12:50:07 by ntodisoa         ###   ########.fr       */
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

void draw_sprite(t_data *data)
{
    int y;
    int max;
    t_img *sprite;
    t_img *screen;
    t_dda *dda;
    int     index;
    int stripe;
    int tex_x;
    int new_y;
    int color;
    int i;
    
    sprite = &data->sprite.image[ft_gettime()];
    dda = &data->dda;
    y = data->sprite.draw_start;
    screen = &data->screen;

    if (y < 0)
        return;
    
    max = data->sprite.draw_end;
    if (data->sprite.draw_end >= SCREENHEIGHT)
        max = SCREENHEIGHT - 1;
    stripe = data->sprite.screen_x;
    while (stripe < data->sprite.screen_x + data->sprite.screen_height)
    {
        if (stripe >= 0 && stripe < SCREENWIDTH && data->z_dist[stripe] >= data->sprite.pos_z)
        {
            int tex_x = (int)((stripe - data->sprite.screen_x) * ((double)sprite->width / data->sprite.screen_height));
            y = data->sprite.draw_start;
            while (y <= data->sprite.draw_end)
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
                y++;
            }
        }
        stripe++;
    }

    i = data->sprite.draw_end + 1;
    while (i < SCREENHEIGHT)
    {
        screen->pixels[i * SCREENWIDTH + data->dda.x] = 0x331111;
        i++;
    }
}