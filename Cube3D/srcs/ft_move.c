/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:03:12 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/16 21:53:21 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void	move_forward(t_data *data, double move_speed)
{
	data->render = 1;
	if (data->world_map[(int)(data->pos_x + data->dir_x
			* move_speed)][(int)(data->pos_y)] == 0)
		data->pos_x += data->dir_x * move_speed;
	if (data->world_map[(int)(data->pos_x)][(int)(data->pos_y + data->dir_y
			* move_speed)] == 0)
		data->pos_y += data->dir_y * move_speed;
}

void	move_backward(t_data *data, double move_speed)
{
	data->render = 1;
	if (data->world_map[(int)(data->pos_x - data->dir_x
			* move_speed)][(int)(data->pos_y)] == 0)
		data->pos_x -= data->dir_x * move_speed;
	if (data->world_map[(int)(data->pos_x)][(int)(data->pos_y - data->dir_y
			* move_speed)] == 0)
		data->pos_y -= data->dir_y * move_speed;
}

void	move_left(t_data *data, double move_speed)
{
	double	perp_x_dir;
	double	perp_y_dir;

	perp_x_dir = -data->dir_y;
	perp_y_dir = data->dir_x;
	data->render = 1;
	if (data->world_map[(int)(data->pos_x + perp_x_dir
			* move_speed)][(int)(data->pos_y)] == 0)
		data->pos_x += perp_x_dir * move_speed;
	if (data->world_map[(int)(data->pos_x)][(int)(data->pos_y + perp_y_dir
			* move_speed)] == 0)
		data->pos_y += perp_y_dir * move_speed;
}

void	move_right(t_data *data, double move_speed)
{
	double	perp_x_dir;
	double	perp_y_dir;

	perp_x_dir = data->dir_y;
	perp_y_dir = -data->dir_x;
	data->render = 1;
	if (data->world_map[(int)(data->pos_x + perp_x_dir
			* move_speed)][(int)(data->pos_y)] == 0)
		data->pos_x += perp_x_dir * move_speed;
	if (data->world_map[(int)(data->pos_x)][(int)(data->pos_y + perp_y_dir
			* move_speed)] == 0)
		data->pos_y += perp_y_dir * move_speed;
}
