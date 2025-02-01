/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:47:25 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/01 16:17:02 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void calculate_fps(t_data *data)
{
    static int 		frames = 0;
    static double 	start_time = 0.0;
    static double 	fps = 0.0;
    double 			current_time;
	char 			output[50];
	
	current_time = (double)clock() / CLOCKS_PER_SEC;
    if (start_time == 0.0)
        start_time = current_time;
    frames++;
    if (current_time - start_time >= 1.0)
    {
        fps = frames / (current_time - start_time);
        frames = 0;
        start_time = current_time;
    }
	snprintf(output, 50, "FPS : %f", fps);
	mlx_string_put(data->mlx, data->win, 10, 20, 0XFFFF00, output);   
}

void	draw_vertical_line(t_data *data)
{
	int	y;
	int	i;
	int	max;
	t_img	*sprite;
	t_img	*screen;
	t_dda	*dda;


	dda = &data->dda;
	y = data->draw_start;
	i = 0;
	key_render (data);

	screen = &data->screen;
	if (dda->side == 0)
		sprite = &data->image_wall_n;
	else if (dda->side == 2)
		sprite = &data->image_wall_s;
	else if (dda->side == 1)
		sprite = &data->image_wall_e;
	else if (dda->side == 3)
		sprite = &data->image_wall_w;
	sprite->sprite_x = (int)(data->dda.wall_hit_coord * (double)(sprite->width));
	if (y < 0)
		y = 0;
	max = data->draw_end;
	if (data->draw_end >= SCREENHEIGHT)
		max = SCREENHEIGHT - 1;
	while (i <= max)
	{
		screen->pixels[i * SCREENWIDTH + data->dda.x] = 0x1133ff;
		i++;
	}
	while (y <= max)
	{
		int	new_y;
		new_y = (int)((y - data->draw_start) * ((double)sprite->height / (data->draw_end - data->draw_start)));
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

void	perform_raycasting(t_data *data)
{
	t_dda	*dda;
	e_bool	show;
	e_bool	in;
	int		start;
	int		end;

	dda = &data->dda;
	show = false;
	if (data->show_mouse == 0 && data->show_mouse_enter == 0)
		move_mouse_to_center(data);
	start = -1;
	end = -1;
	dda->x = 0;
	dda->old_map_x = (int)data->pos_x;
	dda->old_map_y = (int)data->pos_y;
	while (dda->x < SCREENWIDTH)
	{
		in = false;
		data->sprite.render = false;
		dda->camera_x = 2 * dda->x / (double)SCREENWIDTH - 1;
		dda->ray_dir_x = data->dir_x + data->plane_x * dda->camera_x;
		dda->ray_dir_y = data->dir_y + data->plane_y * dda->camera_x;
		dda->map_x = (int)data->pos_x;
		dda->map_y = (int)data->pos_y;
		dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
		dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
		dda->hit = 0;
		if (dda->ray_dir_x < 0)
		{
			dda->step_x = -1;
			dda->side_dist_x = (data->pos_x - dda->map_x) * dda->delta_dist_x;
		}
		else
		{
			dda->step_x = 1;
			dda->side_dist_x = (dda->map_x + 1.0 - data->pos_x)
				* dda->delta_dist_x;
		}
		if (dda->ray_dir_y < 0)
		{
			dda->step_y = -1;
			dda->side_dist_y = (data->pos_y - dda->map_y) * dda->delta_dist_y;
		}
		else
		{
			dda->step_y = 1;
			dda->side_dist_y = (dda->map_y + 1.0 - data->pos_y)
				* dda->delta_dist_y;
		}
		while (dda->hit == 0)
		{
			if (dda->side_dist_x < dda->side_dist_y)
			{
				dda->side_dist_x += dda->delta_dist_x;
				dda->map_x += dda->step_x;
				if (dda->step_x < 0)
					dda->side = 0;
				else
					dda->side = 2;
			}
			else
			{
				dda->side_dist_y += dda->delta_dist_y;
				dda->map_y += dda->step_y;
				if (dda->step_y < 0)
					dda->side = 1;
				else
					dda->side = 3;			
			}
			if (data->world_map[dda->map_x][dda->map_y] == '1')
			{
				dda->hit = 1;
				break;
			}
			if (data->world_map[dda->map_x][dda->map_y] == 'B')
			{
				data->sprite.render = true;
				data->sprite.pos_z = ft_dist_calculator(data->pos_x, data->pos_y, data->sprite.pos_x, data->sprite.pos_y);
				data->sprite.screen_x = dda->x;
				data->sprite.screen_height = (int) (SCREENHEIGHT / data->sprite.pos_z);
				data->sprite.draw_start = (SCREENHEIGHT / 2) - (data->sprite.screen_height / 2);
				data->sprite.draw_end = (SCREENHEIGHT / 2) + (data->sprite.screen_height / 2);
				//printf("SH : %d, posY : %d, height : %d, dist : %f\n", data->sprite.screen_height, data->sprite.draw_start, SCREENHEIGHT, data->sprite.pos_z);
				if (start == -1)
				{
					start = dda->x;
					show = true;
				}
				in = true;
			}
		}

		if (end == -1 && start != -1 && in == false)
			end = dda->x;
			
		if (dda->side % 2 == 0)
			dda->dist_ortho_wall = (dda->map_x - data->pos_x + (1 - dda->step_x)
					/ 2) / dda->ray_dir_x;
		else
			dda->dist_ortho_wall = (dda->map_y - data->pos_y + (1 - dda->step_y)
					/ 2) / dda->ray_dir_y;
		dda->line_height = (int)(SCREENHEIGHT / dda->dist_ortho_wall);
		data->draw_start = -dda->line_height / 2 + SCREENHEIGHT / 2;
		data->draw_end = dda->line_height / 2 + SCREENHEIGHT / 2;
		dda->old_map_x = dda->map_x;
		dda->old_map_y = dda->map_y;
		if (dda->side % 2 == 0)
			dda->wall_hit_coord = data->pos_y + dda->dist_ortho_wall * dda->ray_dir_y;
		else
			dda->wall_hit_coord = data->pos_x + dda->dist_ortho_wall * dda->ray_dir_x;
		dda->wall_hit_coord -= (int)(dda->wall_hit_coord);
		if (dda->dist_ortho_wall < 0.001)
    		dda->dist_ortho_wall = 0.001;

		draw_vertical_line(data);
	if (data->sprite.render)
		draw_sprite(data);
		dda->x++;
	}
	if (show)
		printf("start : %d, end : %d, delta : %d, dist : %f, sh : %d, proportion : %f\n", start, end, end - start, data->sprite.pos_z, data->sprite.screen_height, data->sprite.screen_height / (end - start));
	ft_draw_mini_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->screen.img, 0, 0);
	update_fps(&data->fps);
	calculate_fps(data);
}
