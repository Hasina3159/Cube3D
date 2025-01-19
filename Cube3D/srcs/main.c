/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:09:36 by fhajanol          #+#    #+#             */
/*   Updated: 2025/01/19 16:07:45 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int show_mouse (t_data *data)
{
	data->show_mouse = 1;
	mlx_mouse_show(data->mlx, data->win);
}

int hide_mouse (t_data *data)
{
	data->show_mouse = 0;
	if (data->show_mouse_enter == 0)
	mlx_mouse_hide(data->mlx, data->win);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int world_map[MAPWIDTH][MAPHEIGHT] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
												0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
												1}, {1, 0, 0, 0, 0, 0, 0, 0, 0,
												0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
												0, 0, 0, 1}, {1, 0, 0, 0, 0, 0,
												0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
												0, 0, 0, 0, 0, 0, 1}, {1, 4, 4,
												4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0,
												0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
												{1, 4, 0, 4, 0, 0, 0, 0, 4, 0,
												0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
												0, 0, 1}, {1, 4, 0, 0, 0, 0, 5,
												0, 4, 0, 0, 0, 2, 2, 2, 0, 0, 0,
												0, 0, 0, 0, 0, 1}, {1, 4, 0, 4,
												0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0,
												0, 0, 0, 0, 0, 0, 0, 0, 1}, {1,
												4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0,
												0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
												1}, {1, 4, 0, 0, 0, 0, 0, 0, 0,
												0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
												0, 0, 0, 1}, {1, 4, 4, 4, 4, 4,
												4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0,
												0, 0, 0, 0, 0, 0, 1}, {1, 1, 1,
												1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
												1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
	data.pos_y = 12;
	data.pos_x = 21;
	data.dir_x = -1;
	data.dir_y = 0;
	data.plane_x = 0;
	data.plane_y = 0.66;
	data.render = 0;
	data.mlx = mlx_init();
	data.show_mouse = 0;
	data.show_mouse_enter = 0;
	init_key (&data.key_data);
	ft_load_xpm_image(&data, &data.image_wall_n, "./test_4.xpm");
	ft_load_xpm_image(&data, &data.image_wall_s, "./test_1.xpm");
	ft_load_xpm_image(&data, &data.image_wall_e, "./test_2.xpm");
	ft_load_xpm_image(&data, &data.image_wall_w, "./test_3.xpm");
	data.win = mlx_new_window(data.mlx, SCREENWIDTH, SCREENHEIGHT,
			"Cube3D Petera");
	data.screen.img = mlx_new_image(data.mlx, SCREENWIDTH, SCREENHEIGHT);
	data.screen.pixels = (int *)mlx_get_data_addr(data.screen.img, &data.screen.bpp, &data.screen.size_line, &data.screen.endian);
	for (int i = 0; i < MAPWIDTH; i++)
	{
		for (int j = 0; j < MAPHEIGHT; j++)
		{
			data.world_map[i][j] = world_map[i][j];
		}
	}
	init_fps(&data.fps);

	mlx_hook(data.win, 2, 1L << 0, handle_keypress, &data);
	mlx_loop_hook(data.mlx, (int (*)(void *))perform_raycasting, &data);
	mlx_hook(data.win, 3, 1L << 1, handle_keyrelease, &data);
	mlx_hook(data.win, 10, 1L << 21, show_mouse, &data);
	mlx_hook(data.win, 9, 1L << 21, hide_mouse, &data);
	perform_raycasting(&data);
	mlx_loop(data.mlx);
	return (0);
}
