/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:47:25 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/23 10:49:26 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	calculate_fps(t_data *data);
void	draw_vertical_line(t_data *data);
void	set_side(t_data *data, t_raycast_var *var);
void	raycast_pt1(t_data *data, t_raycast_var *var);
void	rc_inner_pt1(t_data *data, t_raycast_var *var);
void	rc_inner_pt2(t_data *data, t_raycast_var *var);
/*inner boucle*/

int	rc_inner_pt3(t_data *data, t_raycast_var *var)
{
	set_side(data, var);
	if (data->world_map[var->dda->map_x][var->dda->map_y] == 'D')
	{
		if (data->door.door_open == false)
		{
			data->door.door_hit = true;
			return (0);
		}
	}
	return (1);
}

int	rc_inner_pt4(t_data *data, t_raycast_var *var)
{
	if (data->world_map[var->dda->map_x][var->dda->map_y] == '1'
		|| var->dda->map_x <= 0 || var->dda->map_y <= 0
		|| var->dda->map_x >= (int)ft_get_split_size(data->world_map) - 1
		|| var->dda->map_y >= (\
			int)ft_strlen(data->world_map[var->dda->map_x]) - 1)
	{
		var->dda->hit = 1;
		return (0);
	}
	var->dist_ortho_wall_x = (double)((var->dda->map_x - data->pos_x + (1
					- var->dda->step_x) / 2) / var->dda->ray_dir_x);
	var->dist_ortho_wall_y = (double)((var->dda->map_y - data->pos_y + (1
					- var->dda->step_y) / 2) / var->dda->ray_dir_y);
	var->t1 = (double)(((int)(var->dist_ortho_wall_x * 1000)) / 1000.0);
	var->t2 = (double)(((int)(var->dda->ray_dir_x * 1000)) / 1000.0);
	var->t3 = (double)(((int)(var->dist_ortho_wall_y * 1000)) / 1000.0);
	var->t4 = (double)(((int)(var->dda->ray_dir_y * 1000)) / 1000.0);
	var->calc1 = var->t1 * var->t2;
	var->calc2 = var->t3 * var->t4;
	var->ray_hit_y = (double)(data->pos_y + var->calc2);
	var->ray_hit_x = (double)(data->pos_x + var->calc1);
	return (1);
}

void	rc_inner_pt5(t_data *data, t_raycast_var *var)
{
	if (var->dda->side % 2 == 0)
		var->ray_hit_y = var->dda->map_y;
	else
		var->ray_hit_y = var->dda->map_x;
	if (fabs(var->ray_hit_x - data->sprite.pos_x) < 0.1 && fabs(var->ray_hit_y
			- data->sprite.pos_y) < 0.1)
	{
		data->sprite.render = true;
		data->sprite.pos_z = ft_dist_calculator(data->pos_x, data->pos_y,
				data->sprite.pos_x, data->sprite.pos_y);
		data->sprite.screen_x = var->dda->x;
		if (data->sprite.pos_z < 0.0001)
			data->sprite.pos_z = 0.0001;
		data->sprite.screen_height = (int)(SCREENHEIGHT / data->sprite.pos_z);
		data->sprite.draw_start = (SCREENHEIGHT / 2)
			- (data->sprite.screen_height / 2);
		data->sprite.draw_end = (SCREENHEIGHT / 2) + (data->sprite.screen_height
				/ 2);
		var->show = true;
	}
}

void	rc_inner_pt6(t_data *data, t_raycast_var *var)
{
	if (var->dda->side % 2 == 0)
		var->dda->dist_ortho_wall = (var->dda->map_x - data->pos_x + (1
					- var->dda->step_x) / 2) / var->dda->ray_dir_x;
	else
		var->dda->dist_ortho_wall = (var->dda->map_y - data->pos_y + (1
					- var->dda->step_y) / 2) / var->dda->ray_dir_y;
	var->dda->line_height = (int)(SCREENHEIGHT / var->dda->dist_ortho_wall);
	data->draw_start = -var->dda->line_height / 2 + SCREENHEIGHT / 2;
	data->draw_end = var->dda->line_height / 2 + SCREENHEIGHT / 2;
	var->dda->old_map_x = var->dda->map_x;
	var->dda->old_map_y = var->dda->map_y;
	if (var->dda->side % 2 == 0)
		var->dda->wall_hit_coord = data->pos_y + var->dda->dist_ortho_wall
			* var->dda->ray_dir_y;
	else
		var->dda->wall_hit_coord = data->pos_x + var->dda->dist_ortho_wall
			* var->dda->ray_dir_x;
	var->dda->wall_hit_coord -= (int)(var->dda->wall_hit_coord);
	if (var->dda->dist_ortho_wall < 0.001)
		var->dda->dist_ortho_wall = 0.001;
	draw_vertical_line(data);
	data->z_dist[var->dda->x] = var->dda->dist_ortho_wall;
	var->dda->x++;
}

void	perform_raycasting(t_data *data)
{
	t_raycast_var	*var;

	var = (t_raycast_var *)ft_calloc(sizeof(t_raycast_var), 1);
	if (!var)
		return ;
	raycast_pt1(data, var);
	while (var->dda->x < SCREENWIDTH)
	{
		rc_inner_pt1(data, var);
		rc_inner_pt2(data, var);
		while (var->dda->hit == 0)
		{
			if (rc_inner_pt3(data, var) == 0 || rc_inner_pt4(data, var) == 0)
				break ;
			rc_inner_pt5(data, var);
		}
		rc_inner_pt6(data, var);
	}
	if (data->sprite.render)
		draw_sprite(data);
	ft_draw_mini_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->screen.img, 0, 0);
	update_fps(&data->fps);
	calculate_fps(data);
	free(var);
}
