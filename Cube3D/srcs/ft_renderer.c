/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:47:25 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/16 21:42:07 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void	draw_vertical_line(t_data *data)
{
	int	y;
	int	i;
	int	*pixels;

	y = data->draw_start;
	i = 0;
	pixels = (int *)mlx_get_data_addr(data->img, &data->bpp, &data->size_line,
			&data->endian);
	while (data->draw_start < 2000 && i <= data->draw_end)
	{
		pixels[i * SCREENWIDTH + data->dda.x] = 0x1133ff;
		i++;
	}
	while (y <= data->draw_end)
	{
		if ((y - data->draw_start) % ((data->draw_end - data->draw_start)
				/ 3) == 0)
			pixels[y * SCREENWIDTH + data->dda.x] = 0x000000;
		else
			pixels[y * SCREENWIDTH + data->dda.x] = data->dda.color;
		y++;
	}
	i = data->draw_end + 1;
	while (data->draw_end > 0 && i <= SCREENHEIGHT)
	{
		pixels[i * SCREENWIDTH + data->dda.x] = 0x331111;
		i++;
	}
}

void	perform_raycasting(t_data *data)
{
	t_dda	*dda;

	dda = &data->dda;
	mlx_mouse_move(data->mlx, data->win, SCREENWIDTH / 2, SCREENHEIGHT / 2);
	mlx_mouse_get_pos(data->mlx, data->win, &dda->p_x, &dda->p_y);
	dda->x = 0;
	while (dda->x < SCREENWIDTH)
	{
		dda->camera_x = 2 * dda->x / (double)SCREENWIDTH - 1;
		dda->ray_dir_x = data->dir_x + data->plane_x * dda->camera_x;
		dda->ray_dir_y = data->dir_y + data->plane_y * dda->camera_x;
		dda->map_x = (int)data->pos_x;
		dda->map_y = (int)data->pos_y;
		dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
		dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
		dda->dist_ortho_wall;
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
				dda->side = 0;
			}
			else
			{
				dda->side_dist_y += dda->delta_dist_y;
				dda->map_y += dda->step_y;
				dda->side = 1;
			}
			if (data->world_map[dda->map_x][dda->map_y] > 0)
				dda->hit = 1;
		}
		if (dda->side == 0)
			dda->dist_ortho_wall = (dda->map_x - data->pos_x + (1 - dda->step_x)
					/ 2) / dda->ray_dir_x;
		else
			dda->dist_ortho_wall = (dda->map_y - data->pos_y + (1 - dda->step_y)
					/ 2) / dda->ray_dir_y;
		dda->line_height = (int)(SCREENHEIGHT / dda->dist_ortho_wall);
		data->draw_start = -dda->line_height / 2 + SCREENHEIGHT / 2;
		if (data->draw_start < 0)
			data->draw_start = 0;
		data->draw_end = dda->line_height / 2 + SCREENHEIGHT / 2;
		if (data->draw_end >= SCREENHEIGHT)
			data->draw_end = SCREENHEIGHT - 1;
		if (dda->side == 0)
			dda->color = 0x885555;
		else
			dda->color = 0x442211;
		draw_vertical_line(data);
		dda->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
