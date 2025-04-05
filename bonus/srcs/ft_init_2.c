/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:24:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/30 10:42:05 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void	ft_init_struct(t_data *data)
{
	data->mlx = 0;
	data->win = 0;
	data->pos_x = 0;
	data->pos_y = 0;
	data->dir_x = 0;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0;
	data->render = 0;
	data->width = 0;
	data->color_sky = 0;
	data->color_ground = 0;
	data->world_map = 0;
	data->draw_start = 0;
	data->draw_end = 0;
	data->show_mouse = 0;
	data->show_mouse_enter = 0;
}
