/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer_part3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:26:43 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/23 08:51:08 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	set_side(t_data *data, t_raycast_var *var)
{
	(void)data;
	if (var->dda->side_dist_x < var->dda->side_dist_y)
	{
		var->dda->side_dist_x += var->dda->delta_dist_x;
		var->dda->map_x += var->dda->step_x;
		if (var->dda->step_x < 0)
			var->dda->side = 0;
		else
			var->dda->side = 2;
	}
	else
	{
		var->dda->side_dist_y += var->dda->delta_dist_y;
		var->dda->map_y += var->dda->step_y;
		if (var->dda->step_y < 0)
			var->dda->side = 1;
		else
			var->dda->side = 3;
	}
}

void	raycast_pt1(t_data *data, t_raycast_var *var)
{
	var->dda = &data->dda;
	var->show = false;
	if (data->show_mouse == 0 && data->show_mouse_enter == 0)
		move_mouse_to_center(data);
	var->start = -1;
	var->end = -1;
	var->dda->x = 0;
	var->dda->old_map_x = (int)data->pos_x;
	var->dda->old_map_y = (int)data->pos_y;
	data->sprite.render = false;
}

void	rc_inner_pt1(t_data *data, t_raycast_var *var)
{
	data->door.door_hit = false;
	var->dda->camera_x = 2 * var->dda->x / (double)SCREENWIDTH - 1;
	var->dda->ray_dir_x = data->dir_x + data->plane_x * var->dda->camera_x;
	var->dda->ray_dir_y = data->dir_y + data->plane_y * var->dda->camera_x;
	var->dda->map_x = (int)data->pos_x;
	var->dda->map_y = (int)data->pos_y;
	var->dda->delta_dist_x = fabs(1 / var->dda->ray_dir_x);
	var->dda->delta_dist_y = fabs(1 / var->dda->ray_dir_y);
	var->dda->hit = 0;
	if (var->dda->ray_dir_x < 0)
	{
		var->dda->step_x = -1;
		var->dda->side_dist_x = (data->pos_x - var->dda->map_x)
			* var->dda->delta_dist_x;
	}
	else
	{
		var->dda->step_x = 1;
		var->dda->side_dist_x = (var->dda->map_x + 1.0 - data->pos_x)
			* var->dda->delta_dist_x;
	}
}

void	rc_inner_pt2(t_data *data, t_raycast_var *var)
{
	if (var->dda->ray_dir_y < 0)
	{
		var->dda->step_y = -1;
		var->dda->side_dist_y = (data->pos_y - var->dda->map_y)
			* var->dda->delta_dist_y;
	}
	else
	{
		var->dda->step_y = 1;
		var->dda->side_dist_y = (var->dda->map_y + 1.0 - data->pos_y)
			* var->dda->delta_dist_y;
	}
}
