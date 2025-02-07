/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:09:36 by fhajanol          #+#    #+#             */
/*   Updated: 2025/02/07 16:20:48 by ntodisoa         ###   ########.fr       */
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
	return (0);
}

int hide_mouse (t_data *data)
{
	data->show_mouse = 0;
	mlx_mouse_hide(data->mlx, data->win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	if (argc != 2)
		return (0);
	char	*content = ft_get_content(argv[1]);
	int line_index = ft_check_if_all_data_exists(content);
	data.world_map = ft_get_map(content, line_index);
	if (ft_check_map(data.world_map) == false || line_index == -1)
		return (0);
	ft_get_player_position(data.world_map, &data.pos_y, &data.pos_x);
	ft_get_sprite_position(data.world_map, &data.sprite.pos_y, &data.sprite.pos_x);
	printf("sprite (%f, %f)\n", data.sprite.pos_x, data.sprite.pos_y);
	data.door.door_open = false;
	data.show_mouse_enter = 0;
	data.dir_x = -1;
	data.dir_y = 0;
	data.plane_x = 0;
	data.plane_y = 0.66;
	data.render = 0;
	data.mlx = mlx_init();
	data.show_mouse = 0;
	data.show_mouse_enter = 0;
	init_key (&data.key_data);
	int	index_data;
	ft_load_xpm_image(&data, &data.image_wall_n, ft_get_data(content, "NO", &index_data));
	ft_load_xpm_image(&data, &data.image_wall_s, ft_get_data(content, "SO", &index_data));
	ft_load_xpm_image(&data, &data.image_wall_e, ft_get_data(content, "EA", &index_data));
	ft_load_xpm_image(&data, &data.image_wall_w, ft_get_data(content, "WE", &index_data));
	ft_load_xpm_image(&data, &data.sprite.image[0], "./sprites/sonic1.xpm");
	ft_load_xpm_image(&data, &data.sprite.image[1], "./sprites/sonic2.xpm");
	ft_load_xpm_image(&data, &data.sprite.image[2], "./sprites/sonic3.xpm");
	ft_load_xpm_image(&data, &data.sprite.image[3], "./sprites/sonic4.xpm");
	ft_load_xpm_image(&data, &data.sprite.image[4], "./sprites/sonic5.xpm");
	ft_load_xpm_image(&data, &data.door, "./sprites/door.xpm");
	data.win = mlx_new_window(data.mlx, SCREENWIDTH, SCREENHEIGHT,
			"Cube3D Petera");
	data.screen.img = mlx_new_image(data.mlx, SCREENWIDTH, SCREENHEIGHT);
	data.screen.pixels = (int *)mlx_get_data_addr(data.screen.img, &data.screen.bpp, &data.screen.size_line, &data.screen.endian);
	init_fps(&data.fps);

	mlx_hook(data.win, 2, 1L << 0, handle_keypress, (void *)&data);
	mlx_loop_hook(data.mlx, (int (*)(void *))perform_raycasting, (void *)&data);
	mlx_hook(data.win, 3, 1L << 1, handle_keyrelease, (void *)&data);
	mlx_hook(data.win, 10, 1L << 21, show_mouse, (void *)&data);
	mlx_hook(data.win, 9, 1L << 21, hide_mouse, (void *)&data);
	perform_raycasting(&data);
	mlx_loop(data.mlx);
	return (0);
}
