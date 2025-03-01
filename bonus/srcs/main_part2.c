/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 06:34:08 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/02 23:16:16 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

e_bool	ft_load_images(t_data *data, char *content);
void	ft_init_hooks(t_data *data);

e_bool	ft_load_images_pt2(t_data *data, char *content)
{
	if (ft_load_xpm_image(data, &data->sprite.image[1],
			"./sprites/sonic2.xpm") == false)
		return (false);
	if (ft_load_xpm_image(data, &data->sprite.image[2],
			"./sprites/sonic3.xpm") == false)
		return (false);
	if (ft_load_xpm_image(data, &data->sprite.image[3],
			"./sprites/sonic4.xpm") == false)
		return (false);
	if (ft_load_xpm_image(data, &data->sprite.image[4],
			"./sprites/sonic5.xpm") == false)
		return (false);
	if (ft_load_xpm_image(data, &data->door.door_sprite,
			"./sprites/door.xpm") == false)
		return (false);
	return (true);
}

void	init_some_data(t_data *data, char *content, char player)
{
	data->color_ground = ft_get_color(content, "F");
	data->color_sky = ft_get_color(content, "C");
	ft_get_sprite_position(data->world_map, &data->sprite.pos_y,
		&data->sprite.pos_x);
	data->door.door_open = false;
	data->show_mouse_enter = 0;
	ft_init_direction(data, player);
	data->render = 0;
	data->mlx = mlx_init();
	data->show_mouse_enter = 0;
}

int	main_pt2(char player, t_data data, char *content, int line_index)
{
	data.color_ground = ft_get_color(content, "F");
	data.color_sky = ft_get_color(content, "C");
	ft_get_sprite_position(data.world_map, &data.sprite.pos_y,
		&data.sprite.pos_x);
	data.door.door_open = false;
	data.show_mouse_enter = 0;
	ft_init_direction(&data, player);
	data.render = 0;
	data.mlx = mlx_init();
	data.show_mouse_enter = 0;
	init_key(&data.key_data);
	data.screen.img = NULL;
	if (ft_load_images(&data, content) == false)
	{
		free(content);
		printf("--> yead\n");
		clean_up(&data);
		printf("--> yead2\n");
		printf("--> yead3\n");
		return (1);
	}
	free(content);
	data.win = mlx_new_window(data.mlx, SCREENWIDTH, SCREENHEIGHT,
			"Cube3D Petera");
	data.screen.img = mlx_new_image(data.mlx, SCREENWIDTH, SCREENHEIGHT);
	data.screen.pixels = (int *)mlx_get_data_addr(data.screen.img,
			&data.screen.bpp, &data.screen.size_line, &data.screen.endian);
	init_fps(&data.fps);
	ft_init_hooks(&data);
	return (0);
}
