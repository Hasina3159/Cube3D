/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:03:12 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/14 13:29:37 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void	move_forward(t_data *data)
{
	char	content_x;
	char	content_y;

	content_x = data->world_map[(int)(data->pos_x + data->dir_x
			* MOVE_SPEED * MOVE_SPEED_FACTOR)][(int)(data->pos_y)];
	content_y = data->world_map[(int)(data->pos_x)][(int)(data->pos_y + data->dir_y
			* MOVE_SPEED * MOVE_SPEED_FACTOR)];
	data->render = 1;
	if (content_x == 'o')
		data->pos_x += data->dir_x * MOVE_SPEED;
	if (content_y == 'o')
		data->pos_y += data->dir_y * MOVE_SPEED;
}

void	move_backward(t_data *data)
{
	char	content_x;
	char	content_y;

	content_x = data->world_map[(int)(data->pos_x - data->dir_x
			* MOVE_SPEED * MOVE_SPEED_FACTOR)][(int)(data->pos_y)];
	content_y = data->world_map[(int)(data->pos_x)][(int)(data->pos_y - data->dir_y
			* MOVE_SPEED * MOVE_SPEED_FACTOR)];
	data->render = 1;
	if (content_x == 'o')
		data->pos_x -= data->dir_x * MOVE_SPEED;
	if (content_y == 'o')
		data->pos_y -= data->dir_y * MOVE_SPEED;
}

void	move_left(t_data *data)
{
	double	permouse_x_dir;
	double	permouse_y_dir;

	permouse_x_dir = -data->dir_y;
	permouse_y_dir = data->dir_x;
	data->render = 1;
	if (data->world_map[(int)(data->pos_x + permouse_x_dir
			* MOVE_SPEED * MOVE_SPEED_FACTOR)][(int)(data->pos_y)] == 'o')
		data->pos_x += permouse_x_dir * MOVE_SPEED; 
	if (data->world_map[(int)(data->pos_x)][(int)(data->pos_y + permouse_y_dir
			* MOVE_SPEED * MOVE_SPEED_FACTOR)] == 'o')
		data->pos_y += permouse_y_dir * MOVE_SPEED;
}

void	move_right(t_data *data)
{
	double	permouse_x_dir;
	double	permouse_y_dir;

	permouse_x_dir = data->dir_y;
	permouse_y_dir = -data->dir_x;
	data->render = 1;
	if (data->world_map[(int)(data->pos_x + permouse_x_dir
			* MOVE_SPEED * MOVE_SPEED_FACTOR)][(int)(data->pos_y)] == 'o')
		data->pos_x += permouse_x_dir * MOVE_SPEED;
	if (data->world_map[(int)(data->pos_x)][(int)(data->pos_y + permouse_y_dir
			* MOVE_SPEED * MOVE_SPEED_FACTOR)] == 'o')
		data->pos_y += permouse_y_dir * MOVE_SPEED; 
}

