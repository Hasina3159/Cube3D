/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:47:25 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/08 12:23:24 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	draw_pt1(t_data *data, t_vline_var *var)
{
	var->dda = &data->dda;
	var->y = data->draw_start;
	key_render(data);
	var->screen = &data->screen;
	if (var->dda->side == 0)
		var->sprite = &data->image_wall_n;
	else if (var->dda->side == 2)
		var->sprite = &data->image_wall_s;
	else if (var->dda->side == 1)
		var->sprite = &data->image_wall_e;
	else if (var->dda->side == 3)
		var->sprite = &data->image_wall_w;
	var->sprite->sprite_x = (int)(data->dda.wall_hit_coord
			* (double)(var->sprite->width));
	if (var->y < 0)
		var->y = 0;
	var->max = data->draw_end;
	if (data->draw_end >= SCREENHEIGHT)
		var->max = SCREENHEIGHT - 1;
}

void	draw_pt2(t_data *data, t_vline_var *var)
{
	while (var->i <= var->max)
	{
		var->screen->pixels[var->i * SCREENWIDTH
			+ data->dda.x] = data->color_sky;
		var->i++;
	}
	while (var->y <= var->max)
	{
		var->new_y = (int)((var->y - data->draw_start)
				* ((double)var->sprite->height / (data->draw_end
						- data->draw_start)));
		if (var->y >= SCREENHEIGHT)
			break ;
		var->screen->pixels[var->y * SCREENWIDTH
			+ data->dda.x] = var->sprite->pixels[(int)(var->new_y
				* var->sprite->width + var->sprite->sprite_x)];
		var->y++;
	}
	var->i = var->max + 1;
	while (var->max > 0 && var->i <= SCREENHEIGHT)
	{
		var->screen->pixels[var->i * SCREENWIDTH
			+ data->dda.x] = data->color_ground;
		var->i++;
	}
}

void	draw_vertical_line(t_data *data)
{
	t_vline_var	*var;

	var = ft_calloc(sizeof(t_vline_var), 1);
	if (!var)
		return ;
	draw_pt1(data, var);
	var->i = 0;
	draw_pt2(data, var);
	free(var);
}
