/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:41:18 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/01 16:11:21 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void	rotate_left(t_data *data)
{
	double	old_x_dir;
	double	old_x_plane;
	double	rotation;

	rotation = ROTATION_SPEED * data->fps.delta_time;
	if (data->key_data.mouse_left == 1)
		rotation *= 2;
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

	rotation = ROTATION_SPEED * data->fps.delta_time;
	if (data->key_data.mouse_right == 1)
		rotation *= 2;
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

void move_mouse_to_center(t_data *data)
{
	t_dda	*dda;
	int		dx;
	int		dy;

	dda = &data->dda;
	mlx_mouse_get_pos(data->mlx, data->win, &dda->mouse_x, &dda->mouse_y);
	if (dda->mouse_x < (SCREENWIDTH / 2))
		data->key_data.mouse_left = 1;
	else if (dda->mouse_x > (SCREENWIDTH / 2))
		data->key_data.mouse_right = 1;
	else
	{
		data->key_data.mouse_left = 0;
		data->key_data.mouse_right = 0;
	}
	if (dda->mouse_x + 10 < (SCREENWIDTH / 2) )
		mlx_mouse_move(data->mlx, data->win, ((SCREENWIDTH / 2) - 10), dda->mouse_y);
	if (dda->mouse_x - 10 > (SCREENWIDTH / 2) )
		mlx_mouse_move(data->mlx, data->win, ((SCREENWIDTH / 2) + 10), dda->mouse_y);
	if (dda->mouse_y + 10 < (SCREENHEIGHT / 2) )
		mlx_mouse_move(data->mlx, data->win, dda->mouse_x, ((SCREENHEIGHT / 2) - 10));
	if (dda->mouse_y - 10 > (SCREENHEIGHT / 2) )
		mlx_mouse_move(data->mlx, data->win, dda->mouse_x, ((SCREENHEIGHT / 2) + 10));
	mlx_mouse_get_pos(data->mlx, data->win, &dda->mouse_x, &dda->mouse_y);
	dx = abs(dda->mouse_x - (SCREENWIDTH / 2)) - MOUSE_STEP;
	dy = abs(dda->mouse_y - (SCREENHEIGHT / 2)) - MOUSE_STEP;
	if (dda->mouse_x < (SCREENWIDTH / 2) )
		mlx_mouse_move(data->mlx, data->win, dda->mouse_x + MOUSE_STEP + dx, dda->mouse_y);
	if (dda->mouse_x > (SCREENWIDTH / 2) )
		mlx_mouse_move(data->mlx, data->win, dda->mouse_x - MOUSE_STEP - dx, dda->mouse_y);
	if (dda->mouse_y > (SCREENHEIGHT / 2) )
		mlx_mouse_move(data->mlx, data->win, dda->mouse_x, dda->mouse_y - MOUSE_STEP - dy);
	if (dda->mouse_y < (SCREENHEIGHT / 2) )
		mlx_mouse_move(data->mlx, data->win, dda->mouse_x, dda->mouse_y + MOUSE_STEP + dy);
}
