/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:58:53 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/30 10:42:18 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

t_sprite_var	*draw_sprite_pt1(t_data *data)
{
	t_sprite_var	*var;

	var = ft_calloc(sizeof(t_sprite_var), 1);
	if (!var)
		return (NULL);
	var->sprite = &data->sprite.image[ft_gettime()];
	var->dda = &data->dda;
	var->y = data->sprite.draw_start;
	var->screen = &data->screen;
	if (var->y < 0)
	{
		free(var);
		return (NULL);
	}
	var->max = data->sprite.draw_end;
	if (data->sprite.draw_end >= SCREENHEIGHT)
		var->max = SCREENHEIGHT - 1;
	var->stripe = data->sprite.screen_x;
	return (var);
}

void	draw_sprite_inner_loop(t_sprite_var *var, t_data *data)
{
	if (var->stripe >= 0 && var->stripe < SCREENWIDTH
		&& data->z_dist[var->stripe] >= data->sprite.pos_z)
	{
		var->tex_x = (int)((var->stripe - data->sprite.screen_x)
				* ((double)var->sprite->width / data->sprite.screen_height));
		var->y = data->sprite.draw_start;
		while (var->y <= data->sprite.draw_end)
		{
			var->new_y = (int)((var->y - data->sprite.draw_start)
					* ((double)var->sprite->height / (data->sprite.draw_end
							- data->sprite.draw_start)));
			if (var->new_y >= 0 && var->new_y < var->sprite->height)
			{
				var->color = var->sprite->pixels[(int)(var->new_y
						* var->sprite->width + var->tex_x)];
				if (var->color & (0xFF000000 != 0x000000))
				{
					var->screen->pixels[var->y * SCREENWIDTH
						+ var->stripe] = var->color;
				}
			}
			var->y++;
		}
	}
}

void	draw_sprite(t_data *data)
{
	t_sprite_var	*var;

	var = draw_sprite_pt1(data);
	if (!var)
		return ;
	while (var->stripe < data->sprite.screen_x + data->sprite.screen_height)
	{
		draw_sprite_inner_loop(var, data);
		var->stripe++;
	}
	var->i = data->sprite.draw_end + 1;
	while (var->i < SCREENHEIGHT)
	{
		var->screen->pixels[var->i * SCREENWIDTH + data->dda.x] = 0x331111;
		var->i++;
	}
	free(var);
}
