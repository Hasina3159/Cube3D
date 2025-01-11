/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:09:39 by fhajanol          #+#    #+#             */
/*   Updated: 2025/01/11 10:29:10 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H
#include "libft/libft.h"
#include "libft/printf/ft_printf.h"
#include "minilibx-linux/mlx.h"
#include "math.h"
#define MAX(a, b) (a) > (b) ? (a) : (b)
typedef struct s_mlx_container
{
    void *mlx;
    void *window;
    void *image;
    int *pixels;
    int px;
    int py;
    int rot;
    int width;
    int height;
    void *image_2;
} t_mlx_container;
void draw_colored_square(t_mlx_container *container, int x, int y, int size, int color);
// void draw_colored_square(t_mlx_container *container, int x, int y, int left_height, int right_height, int color);
void raytrace(t_mlx_container *mlx, int px, int py, int rot);
#endif