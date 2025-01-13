/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:47:25 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/13 22:47:36 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/struct.h"
#include "../includes/functions.h"

void draw_vertical_line(t_data *data, int x, int drawStart, int drawEnd, int color)
{
	int y = drawStart;
	int	i = 0;
	int *pixels;

	pixels = (int*)mlx_get_data_addr(data->img, &data->bpp, &data->size_line, &data->endian);
	while (drawStart < 2000 && i <= drawEnd)
	{
		pixels[i * screenWidth + x] = 0x1133ff;
		i++;
	}

	while (y <= drawEnd) {
		pixels[y * screenWidth + x] = color;
		y++;
	}

	i = drawEnd + 1;
	while (drawEnd > 0 && i <= screenHeight)
	{
		pixels[i * screenWidth + x] = 0x331111;
		i++;
	}
}


void perform_raycasting(t_data *data)
{
	for (int x = 0; x < screenWidth; x++) {
		double cameraX = 2 * x / (double)screenWidth - 1; // Coordonnée sur le plan caméra
		double rayDirX = data->dirX + data->planeX * cameraX;
		double rayDirY = data->dirY + data->planeY * cameraX;

		int mapX = (int)data->posX;
		int mapY = (int)data->posY;

		double sideDistX, sideDistY;
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		int stepX, stepY;
		int hit = 0;
		int side;

		// Calcul des pas initiaux
		if (rayDirX < 0) {
			stepX = -1;
			sideDistX = (data->posX - mapX) * deltaDistX;
		} else {
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
		}
		if (rayDirY < 0) {
			stepY = -1;
			sideDistY = (data->posY - mapY) * deltaDistY;
		} else {
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->posY) * deltaDistY;
		}

		// DDA
		while (hit == 0) {
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (data->worldMap[mapX][mapY] > 0) hit = 1;
		}

		// Calcul de la distance à la paroi
		if (side == 0)
			perpWallDist = (mapX - data->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - data->posY + (1 - stepY) / 2) / rayDirY;

		// Calcul de la hauteur de la ligne
		int lineHeight = (int)(screenHeight / perpWallDist);
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;

		// Couleur des murs
		int color;
		if (side == 0)
			color = 0xFF0000; // Rouge
		else
			color = 0x00FF00; // Vert

		//if (data->render == 0)
	//		return;
		draw_vertical_line(data, x, drawStart, drawEnd, color);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);

}