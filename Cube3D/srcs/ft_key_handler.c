/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:44:29 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/16 21:49:57 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

int	handle_keypress(int keycode, t_data *data)
{
	double	move_speed;
	double	rotation_speed;

	move_speed = 0.2;
	rotation_speed = 0.05;
	if (keycode == KEY_W)
		move_forward(data, move_speed);
	else if (keycode == KEY_S)
		move_backward(data, move_speed);
	else if (keycode == KEY_A)
		move_left(data, move_speed);
	else if (keycode == KEY_D)
		move_right(data, move_speed);
	else if (keycode == KEY_LEFT)
		rotate_left(data, rotation_speed);
	else if (keycode == KEY_RIGHT)
		rotate_right(data, rotation_speed);
	else if (keycode == KEY_ESC)
		clean_up(data);
	return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	data->render = 0;
	return (0);
}
