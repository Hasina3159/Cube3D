/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:41:18 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/13 22:41:39 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/struct.h"
#include "../includes/functions.h"

void rotate_left(t_data *data, double rotSpeed) {
	double oldDirX = data->dirX;
	double oldPlaneX = data->planeX;

	data->render = 1;
	data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
	data->dirY = oldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
	data->planeX = data->planeX * cos(rotSpeed) - data->planeY * sin(rotSpeed);
	data->planeY = oldPlaneX * sin(rotSpeed) + data->planeY * cos(rotSpeed);
}

void rotate_right(t_data *data, double rotSpeed) {
	double oldDirX = data->dirX;
	double oldPlaneX = data->planeX;

	data->render = 1;
	data->dirX = data->dirX * cos(-rotSpeed) - data->dirY * sin(-rotSpeed);
	data->dirY = oldDirX * sin(-rotSpeed) + data->dirY * cos(-rotSpeed);
	data->planeX = data->planeX * cos(-rotSpeed) - data->planeY * sin(-rotSpeed);
	data->planeY = oldPlaneX * sin(-rotSpeed) + data->planeY * cos(-rotSpeed);
}