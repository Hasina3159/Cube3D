/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:41:18 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/16 21:48:33 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void	rotate_left(t_data *data)
{
	double	old_x_dir;
	double	old_x_plane;

	old_x_dir = data->dir_x;
	old_x_plane = data->plane_x;
	data->render = 1;
	data->dir_x = data->dir_x * cos(ROTATION_SPEED) - data->dir_y * sin(ROTATION_SPEED);
	data->dir_y = old_x_dir * sin(ROTATION_SPEED) + data->dir_y * cos(ROTATION_SPEED);
	data->plane_x = data->plane_x * cos(ROTATION_SPEED) - data->plane_y
		* sin(ROTATION_SPEED);
	data->plane_y = old_x_plane * sin(ROTATION_SPEED) + data->plane_y * cos(ROTATION_SPEED);
}

void	rotate_right(t_data *data)
{
	double	old_x_dir;
	double	old_x_plane;

	old_x_dir = data->dir_x;
	old_x_plane = data->plane_x;
	data->render = 1;
	data->dir_x = data->dir_x * cos(-ROTATION_SPEED) - data->dir_y * sin(-ROTATION_SPEED);
	data->dir_y = old_x_dir * sin(-ROTATION_SPEED) + data->dir_y * cos(-ROTATION_SPEED);
	data->plane_x = data->plane_x * cos(-ROTATION_SPEED) - data->plane_y
		* sin(-ROTATION_SPEED);
	data->plane_y = old_x_plane * sin(-ROTATION_SPEED) + data->plane_y
		* cos(-ROTATION_SPEED);
}

void move_mouse_to_center(t_data *data)
{
	t_dda	*dda;
	int		dx;
	int		dy;

	dda = &data->dda;
	mlx_mouse_get_pos(data->mlx, data->win, &dda->mouse_x, &dda->mouse_y);
	if (dda->mouse_x < (SCREENWIDTH / 2))
		rotate_left(data);
	else if (dda->mouse_x > (SCREENWIDTH / 2))
		rotate_right(data);
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
