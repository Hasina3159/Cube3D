/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer_part2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:52:56 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/01 11:03:07 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	rc_part1(t_data *data, t_dda *dda)
{
	dda->camera_x = 2 * dda->x / (double)SCREENWIDTH - 1;
	dda->ray_dir_x = data->dir_x + data->plane_x * dda->camera_x;
	dda->ray_dir_y = data->dir_y + data->plane_y * dda->camera_x;
	dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
	dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (data->pos_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - data->pos_x) * dda->delta_dist_x;
	}
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (data->pos_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - data->pos_y) * dda->delta_dist_y;
	}
}

// replace while loop to recursive function;

void	rc_part2(t_data *data, t_dda *dda)
{
	if (dda->hit != 0)
		return ;
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
		dda->hit = 1;
	rc_part2(data, dda);
}

void	rc_part3(t_data *data, t_dda *dda)
{
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
		dda->wall_hit_coord = data->pos_y + dda->dist_ortho_wall
			* dda->ray_dir_y;
	else
		dda->wall_hit_coord = data->pos_x + dda->dist_ortho_wall
			* dda->ray_dir_x;
	dda->wall_hit_coord -= (int)(dda->wall_hit_coord);
	if (dda->dist_ortho_wall < 0.001)
		dda->dist_ortho_wall = 0.001;
	draw_vertical_line(data);
	data->z_dist[dda->x] = dda->dist_ortho_wall;
}

void	perform_raycasting(t_data *data)
{
	t_dda	*dda;
	e_bool	show;
	int		start;
	int		end;

	dda = &data->dda;
	show = false;
	start = -1;
	end = -1;
	dda->x = 0;
	dda->old_map_x = (int)data->pos_x;
	dda->old_map_y = (int)data->pos_y;
	while (dda->x < SCREENWIDTH)
	{
		dda->hit = 0;
		dda->map_x = (int)data->pos_x;
		dda->map_y = (int)data->pos_y;
		rc_part1(data, dda);
		rc_part2(data, dda);
		rc_part3(data, dda);
		dda->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->screen.img, 0, 0);
}
