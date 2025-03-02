/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:03:12 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/01 08:07:48 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <stdbool.h>

e_bool	ft_out_of_map(char **map, int x, int y)
{
	if (x <= 0 || y <= 0 || x >= ft_get_split_size(map) - 1
		|| y >= ft_strlen(map[x]) - 1)
		return (false);
	return (true);
}

void	move_forward(t_data *data)
{
	double	new_pos_x;
	double	new_pos_y;
	int		map_x;
	int		map_y;

	new_pos_x = data->pos_x + data->dir_x * MOVE_SPEED * MOVE_SPEED_FACTOR
		* data->fps.delta_time;
	new_pos_y = data->pos_y + data->dir_y * MOVE_SPEED * MOVE_SPEED_FACTOR
		* data->fps.delta_time;
	map_x = (int)new_pos_x;
	map_y = (int)new_pos_y;
	data->render = 1;
	if (ft_out_of_map(data->world_map, map_x, (int)data->pos_y) \
	&& (data->world_map[map_x][(int)data->pos_y] == 'o'
		|| (data->door.door_open
			&& data->world_map[map_x][(int)data->pos_y] == 'D')))
		data->pos_x = (new_pos_x - data->pos_x) / MOVE_SPEED_FACTOR
			+ data->pos_x;
	if (ft_out_of_map(data->world_map, (int)data->pos_x, map_y) \
	&& (data->world_map[(int)data->pos_x][map_y] == 'o'
		|| (data->door.door_open
			&& data->world_map[(int)data->pos_x][map_y] == 'D')))
		data->pos_y = (new_pos_y - data->pos_y) / MOVE_SPEED_FACTOR
			+ data->pos_y;
}

void	move_backward(t_data *data)
{
	double	new_pos_x;
	double	new_pos_y;
	int		map_x;
	int		map_y;

	new_pos_x = data->pos_x - data->dir_x * MOVE_SPEED * MOVE_SPEED_FACTOR
		* data->fps.delta_time;
	new_pos_y = data->pos_y - data->dir_y * MOVE_SPEED * MOVE_SPEED_FACTOR
		* data->fps.delta_time;
	map_x = (int)new_pos_x;
	map_y = (int)new_pos_y;
	data->render = 1;
	if (ft_out_of_map(data->world_map, map_x, (int)data->pos_y) \
	&& (data->world_map[map_x][(int)data->pos_y] == 'o'
		|| (data->door.door_open
			&& data->world_map[map_x][(int)data->pos_y] == 'D')))
		data->pos_x = (new_pos_x - data->pos_x) / MOVE_SPEED_FACTOR
			+ data->pos_x;
	if (ft_out_of_map(data->world_map, (int)data->pos_x, map_y) \
	&& (data->world_map[(int)data->pos_x][map_y] == 'o'
		|| (data->door.door_open
			&& data->world_map[(int)data->pos_x][map_y] == 'D')))
		data->pos_y = (new_pos_y - data->pos_y) / MOVE_SPEED_FACTOR
			+ data->pos_y;
}

void	move_left(t_data *data)
{
	double	new_pos_x;
	double	new_pos_y;
	int		map_x;
	int		map_y;

	new_pos_x = data->pos_x - data->dir_y * MOVE_SPEED * MOVE_SPEED_FACTOR
		* data->fps.delta_time;
	new_pos_y = data->pos_y + data->dir_x * MOVE_SPEED * MOVE_SPEED_FACTOR
		* data->fps.delta_time;
	map_x = (int)new_pos_x;
	map_y = (int)new_pos_y;
	data->render = 1;
	if (ft_out_of_map(data->world_map, map_x, (int)data->pos_y)
		&& data->world_map[map_x][(int)data->pos_y] == 'o')
		data->pos_x = (new_pos_x - data->pos_x) / MOVE_SPEED_FACTOR
			+ data->pos_x;
	if (ft_out_of_map(data->world_map, (int)data->pos_x, map_y)
		&& data->world_map[(int)data->pos_x][map_y] == 'o')
		data->pos_y = (new_pos_y - data->pos_y) / MOVE_SPEED_FACTOR
			+ data->pos_y;
}

void	move_right(t_data *data)
{
	double	new_pos_x;
	double	new_pos_y;
	int		map_x;
	int		map_y;

	new_pos_x = data->pos_x + data->dir_y * MOVE_SPEED * MOVE_SPEED_FACTOR
		* data->fps.delta_time;
	new_pos_y = data->pos_y - data->dir_x * MOVE_SPEED * MOVE_SPEED_FACTOR
		* data->fps.delta_time;
	map_x = (int)new_pos_x;
	map_y = (int)new_pos_y;
	data->render = 1;
	if (ft_out_of_map(data->world_map, map_x, (int)data->pos_y)
		&& data->world_map[map_x][(int)data->pos_y] == 'o')
		data->pos_x = (new_pos_x - data->pos_x) / MOVE_SPEED_FACTOR
			+ data->pos_x;
	if (ft_out_of_map(data->world_map, (int)data->pos_x, map_y)
		&& data->world_map[(int)data->pos_x][map_y] == 'o')
		data->pos_y = (new_pos_y - data->pos_y) / MOVE_SPEED_FACTOR
			+ data->pos_y;
}
