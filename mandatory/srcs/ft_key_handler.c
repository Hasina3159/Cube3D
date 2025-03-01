/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:44:29 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/28 16:02:04 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key_data.key_w = 1;
	else if (keycode == KEY_S)
		data->key_data.key_s = 1;
	else if (keycode == KEY_A)
		data->key_data.key_a = 1;
	else if (keycode == KEY_D)
		data->key_data.key_d = 1;
	else if (keycode == KEY_LEFT)
		data->key_data.key_left = 1;
	else if (keycode == KEY_RIGHT)
		data->key_data.key_right = 1;
	else if (keycode == KEY_ESC)
		clean_up(data);
	return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key_data.key_w = 0;
	else if (keycode == KEY_S)
		data->key_data.key_s = 0;
	else if (keycode == KEY_A)
		data->key_data.key_a = 0;
	else if (keycode == KEY_D)
		data->key_data.key_d = 0;
	else if (keycode == KEY_LEFT)
		data->key_data.key_left = 0;
	else if (keycode == KEY_RIGHT)
		data->key_data.key_right = 0;
	else if (keycode == KEY_ESC)
		clean_up(data);
	data->render = 0;
	return (0);
}

void	init_key(t_key *key_data)
{
	if (key_data == NULL)
		return ;
	key_data->key_w = 0;
	key_data->key_a = 0;
	key_data->key_s = 0;
	key_data->key_d = 0;
	key_data->key_left = 0;
	key_data->key_right = 0;
	return ;
}

void	key_render(t_data *data)
{
	t_key	*key_data;

	if (data == NULL)
		return ;
	key_data = &data->key_data;
	if (key_data->key_w == 1)
		move_forward(data);
	if (key_data->key_a == 1)
		move_left(data);
	if (key_data->key_s == 1)
		move_backward(data);
	if (key_data->key_d == 1)
		move_right(data);
	if (key_data->key_left == 1)
		rotate_left(data);
	if (key_data->key_right == 1)
		rotate_right(data);
	return ;
}
