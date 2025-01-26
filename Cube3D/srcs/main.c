/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:09:36 by fhajanol          #+#    #+#             */
/*   Updated: 2025/01/26 14:46:33 by ntodisoa         ###   ########.fr       */
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
	if (argc != 2)
		return (0);
	char	*content = ft_get_content(argv[1]);
	int line_index = ft_check_if_all_data_exists(content);
	data.world_map = ft_get_map(content, line_index);
	// ft_print_map(data.world_map);

	if (ft_check_map(data.world_map) == false)
	{
		// ft_print_map(data.world_map);
		return (0);
	}
	ft_get_player_position(data.world_map, &data.pos_y, &data.pos_x);
	// ft_print_map(data.world_map);

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
