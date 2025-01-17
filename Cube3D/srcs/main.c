/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:09:36 by fhajanol          #+#    #+#             */
/*   Updated: 2025/01/17 22:56:32 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	t_data	data;
	int world_map[MAPWIDTH][MAPHEIGHT] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 2, 2,
		2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 2,
		0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0,
		2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1}, {1, 0, 0, 0, 0,
		0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0,
		0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1}, {1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1,
		0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 1},
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
	data.image_wall_x.img_path = "./test_3.xpm";
	data.image_wall_y.img_path = "./test_1.xpm";
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREENWIDTH, SCREENHEIGHT,
			"Cube3D Petera");
	data.img = mlx_new_image(data.mlx, SCREENWIDTH, SCREENHEIGHT);
	for (int i = 0; i < MAPWIDTH; i++)
	{
		for (int j = 0; j < MAPHEIGHT; j++)
		{
			data.world_map[i][j] = world_map[i][j];
		}
	}
	data.image_wall_x.img = mlx_xpm_file_to_image(data.mlx, data.image_wall_x.img_path, &data.image_wall_x.height, &data.image_wall_x.width);
	data.image_wall_y.img = mlx_xpm_file_to_image(data.mlx, data.image_wall_y.img_path, &data.image_wall_y.height, &data.image_wall_y.width);
	mlx_hook(data.win, 2, 1L << 0, handle_keypress, &data);
	mlx_loop_hook(data.mlx, (int (*)(void *))perform_raycasting, &data);
	mlx_hook(data.win, 3, 1L << 1, handle_keyrelease, &data);
	perform_raycasting(&data);
	mlx_loop(data.mlx);
	return (0);
}
