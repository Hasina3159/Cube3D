/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:09:36 by fhajanol          #+#    #+#             */
/*   Updated: 2025/01/11 10:31:45 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void move(int keycode, void *param)
{
    t_mlx_container *mlx = (t_mlx_container *)param;
    // ft_printf("key: %d\n", keycode);
    if (keycode == 65362)
        mlx->px += 5;
    else if (keycode == 65364)
        mlx->px -= 5;
    else if (keycode == 65361)
        mlx->py -= 5;
    else if (keycode == 65363)
        mlx->py += 5;
    else if (keycode == 102)
        mlx->rot -= 5;
    else if (keycode == 106)
        mlx->rot += 5;
    else
        return;
    raytrace(mlx, mlx->px, mlx->py, mlx->rot);
    (void)keycode;
    (void)param;
}

int close_window(int keycode, void *param)
{
    t_mlx_container *mlx = (t_mlx_container *)param;
    if (keycode == 65307)
    {
        mlx_destroy_window(mlx->mlx, mlx->window);
        exit(0);
    }
    move(keycode, param);
    return (0);
}

void draw_colored_square(t_mlx_container *container, int x, int y, int size, int color)
{
    void *image;
    int *pixels;
    int i, j;
    image = mlx_new_image(container->mlx, size, size);
    if (!image)
    {
        return;
    }
    pixels = (int *)mlx_get_data_addr(image, &(int){0}, &(int){0}, &(int){0});
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            pixels[i * size + j] = color;
    mlx_put_image_to_window(container->mlx, container->window, image, x, y);
    mlx_destroy_image(container->mlx, image);
}

// void draw_colored_square(t_mlx_container *container, int x, int y, int left_height, int right_height, int color)
// {
//     void *image;
//     int *pixels;
//     int i, j;
//     int size = MAX(left_height, right_height);

//     image = mlx_new_image(container->mlx, size, size);
//     if (!image)
//         return;
//     pixels = (int *)mlx_get_data_addr(image, &(int){0}, &(int){0}, &(int){0});
//     for (j = 0; j < size; j++)
//     {
//         int line_height = left_height + (right_height - left_height) * j / size;
//         int offset = (size - line_height) / 2;
//         for (i = 0; i < line_height; i++)
//         {
//             if (i + offset >= 0 && i + offset < size)
//                 pixels[(i + offset) * size + j] = color;
//         }
//     }
//     mlx_put_image_to_window(container->mlx, container->window, image, x, y);
//     mlx_destroy_image(container->mlx, image);
// }
#include <unistd.h>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    t_mlx_container mlx;
    mlx.width = 800;
    mlx.height = 600;
    mlx.mlx = mlx_init();
    mlx.window = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "simple window");
    mlx.image = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
    mlx.image_2 = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
    int *pix = (int *)mlx_get_data_addr(mlx.image_2, &(int){0}, &(int){0}, &(int){0});
    for (int i = 0; i < mlx.height / 2; i++)
        for (int j = 0; j < mlx.width; j++)
            pix[i * mlx.width + j] = 0xffffff;
    for (int i = 0; i < mlx.height / 2; i++)
        for (int j = 0; j < mlx.width; j++)
            pix[i * mlx.width + j] = 0x0000ff;
    if (!mlx.image)
        return 1;
    mlx.pixels = (int *)mlx_get_data_addr(mlx.image, &(int){0}, &(int){0}, &(int){0});
    if (!mlx.window)
        return 1;
    mlx_hook(mlx.window, 2, 1L << 0, close_window, &mlx);
    mlx_hook(mlx.window, 17, 0, close_window, &mlx);
    mlx.px = 210;
    mlx.py = 350;
    mlx.rot = 0;
    raytrace(&mlx, mlx.px, mlx.py, mlx.rot);
    mlx_loop(mlx.mlx);
    return 0;
}