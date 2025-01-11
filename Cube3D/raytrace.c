/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 07:49:59 by fhajanol          #+#    #+#             */
/*   Updated: 2025/01/11 10:41:11 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int isCollide(char *cmap, int x, int y, int size)
{
    int i;
    int px = 0;
    int py = 0;
    for (i = 0; cmap[i]; i++)
    {
        if (cmap[i] == '\n')
        {
            py++;
            px = 0;
            continue;
        }
        if (cmap[i] == '0')
        {
            if (x >= size * px && x <= size * px + size && y >= size * py && y <= size * py + size)
                return 1;
        }
        px++;
    }
    return 0;
}

void color(t_mlx_container *mlx, int x, int y, int col)
{
    mlx->pixels[y * mlx->width + x] = col;
}

void raytrace(t_mlx_container *mlx, int px, int py, int rot)
{
    char *cmap = "0000000000000000\n0    0     0   0\n0     0        0\n0         0    0\n0              0\n0      0   0   0\n0              0\n0       0      0\n0              0\n0       0      0\n0              0\n0       00     0\n0              0\n0              0\n0000000000000000\n";
    (void)cmap;
    int num = mlx->width / 10;
    float pi = 4 * atan(1);
    for (int i = 0; i < mlx->height; i++)
        for (int j = 0; j < mlx->width; j++)
            mlx->pixels[i * mlx->width + j] = 0x02F;
    // mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image_2, 0, 0);
    for (int i = -num / 2; i < num / 2; i++)
    {
        for (int j = 0; j < 1500; j++)
        {
            int y = j * sin((i + rot) * pi / 180);
            int x = j * cos((i + rot) * pi / 180);
            if (isCollide(cmap, px + x, py + y, 50) && mlx->height - j > 0)
            {
                int xx = (num / 2 + i) * 10;
                int yy = mlx->height / 2 - (mlx->height - j) / 2;
                // for(int p = 0; p < yy; p++)
                //     for (int k = 0; k < 10; k++)
                //         color(mlx, xx + k, p, 0x000000);
                for (int l = 0; l < mlx->height - j; l++)
                {
                    for (int k = 0; k < 10; k++)
                        color(mlx, xx + k, yy + l, 0x00FF00);
                }
            }
        }
    }
    mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
}
