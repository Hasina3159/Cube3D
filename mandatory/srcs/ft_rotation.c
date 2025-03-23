/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:41:18 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/08 12:23:24 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <stdio.h>

void	rotate_left(t_data *data)
{
	double	old_x_dir;
	double	old_x_plane;
	double	rotation;

	rotation = ROTATION_SPEED;
	old_x_dir = data->dir_x;
	old_x_plane = data->plane_x;
	data->render = 1;
	data->dir_x = data->dir_x * cos(rotation) - data->dir_y * sin(rotation);
	data->dir_y = old_x_dir * sin(rotation) + data->dir_y * cos(rotation);
	data->plane_x = data->plane_x * cos(rotation) - data->plane_y
		* sin(rotation);
	data->plane_y = old_x_plane * sin(rotation) + data->plane_y * cos(rotation);
}

void	rotate_right(t_data *data)
{
	double	old_x_dir;
	double	old_x_plane;
	double	rotation;

	rotation = ROTATION_SPEED;
	old_x_dir = data->dir_x;
	old_x_plane = data->plane_x;
	data->render = 1;
	data->dir_x = data->dir_x * cos(-rotation) - data->dir_y * sin(-rotation);
	data->dir_y = old_x_dir * sin(-rotation) + data->dir_y * cos(-rotation);
	data->plane_x = data->plane_x * cos(-rotation) - data->plane_y
		* sin(-rotation);
	data->plane_y = old_x_plane * sin(-rotation) + data->plane_y
		* cos(-rotation);
}
