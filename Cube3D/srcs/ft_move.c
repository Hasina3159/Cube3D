/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:03:12 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/13 22:41:31 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/struct.h"
#include "../includes/functions.h"

void move_forward(t_data *data, double moveSpeed) {
	data->render = 1;
    if (data->worldMap[(int)(data->posX + data->dirX * moveSpeed)][(int)(data->posY)] == 0)
        data->posX += data->dirX * moveSpeed;
    if (data->worldMap[(int)(data->posX)][(int)(data->posY + data->dirY * moveSpeed)] == 0)
        data->posY += data->dirY * moveSpeed;
}

void move_backward(t_data *data, double moveSpeed) {
	data->render = 1;
    if (data->worldMap[(int)(data->posX - data->dirX * moveSpeed)][(int)(data->posY)] == 0)
        data->posX -= data->dirX * moveSpeed;
    if (data->worldMap[(int)(data->posX)][(int)(data->posY - data->dirY * moveSpeed)] == 0)
        data->posY -= data->dirY * moveSpeed;
}

void move_left(t_data *data, double moveSpeed)
{
    double perpDirX = -data->dirY;
    double perpDirY = data->dirX;

	data->render = 1;
    if (data->worldMap[(int)(data->posX + perpDirX * moveSpeed)][(int)(data->posY)] == 0)
        data->posX += perpDirX * moveSpeed;
    if (data->worldMap[(int)(data->posX)][(int)(data->posY + perpDirY * moveSpeed)] == 0)
        data->posY += perpDirY * moveSpeed;
}

void move_right(t_data *data, double moveSpeed)
{
    double perpDirX = data->dirY;
    double perpDirY = -data->dirX;

	data->render = 1;
    if (data->worldMap[(int)(data->posX + perpDirX * moveSpeed)][(int)(data->posY)] == 0)
        data->posX += perpDirX * moveSpeed;
    if (data->worldMap[(int)(data->posX)][(int)(data->posY + perpDirY * moveSpeed)] == 0)
        data->posY += perpDirY * moveSpeed;
}