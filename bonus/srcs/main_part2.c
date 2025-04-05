/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 06:34:08 by fhajanol          #+#    #+#             */
/*   Updated: 2025/04/04 14:25:30 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_bool	ft_load_images(t_data *data, char *content);
void	ft_init_hooks(t_data *data);

t_bool	ft_load_images_pt2(t_data *data, char *content)
{
	int	index_data;

	index_data = 0;
	if (ft_load_xpm_image(data, &data->image_wall_n, \
	ft_get_data(content, "NO", &index_data)) == false)
		return (false);
	free(data->image_wall_n.img_path);
	if (ft_load_xpm_image(data, &data->image_wall_s, \
	ft_get_data(content, "SO", &index_data)) == false)
		return (false);
	free(data->image_wall_s.img_path);
	if (ft_load_xpm_image(data, &data->image_wall_e, \
	ft_get_data(content, "EA", &index_data)) == false)
		return (false);
	free(data->image_wall_e.img_path);
	if (ft_load_xpm_image(data, &data->image_wall_w, \
	ft_get_data(content, "WE", &index_data)) == false)
		return (false);
	free(data->image_wall_w.img_path);
	if (ft_load_xpm_image(data, &data->sprite.image[0], \
	ft_strdup("./bonus/sprites/sonic1.xpm")) == false)
		return (false);
	return (true);
}

int	init_some_data(t_data *data, char *content, char player)
{
	data->sprite.pos_x = 0;
	data->sprite.pos_y = 0;
	data->color_ground = ft_get_color(content, "F");
	if (data->color_ground == -1)
	{
		printf("Error\nInvalid color value\n");
		return (0);
	}
	data->color_sky = ft_get_color(content, "C");
	if (data->color_sky == -1)
	{
		printf("Error\nInvalid color value\n");
		return (0);
	}
	ft_get_sprite_position(data->world_map, &data->sprite.pos_y,
		&data->sprite.pos_x);
	data->door.door_open = false;
	data->show_mouse_enter = 0;
	ft_init_direction(data, player);
	data->render = 0;
	data->mlx = mlx_init();
	data->show_mouse_enter = 0;
	data->screen.bpp = 0;
	data->screen.size_line = 0;
	return (1);
}

int	main_pt2(char player, t_data *data, char **content)
{
	data->screen.endian = 0;
	data->show_mouse_enter = 0;
	init_key(&data->key_data);
	data->screen.img = NULL;
	data->win = NULL;
	if (init_some_data(data, *content, player) == 0 \
		|| ft_load_images(data, *content) == false)
	{
		free(*content);
		clean_up(data);
		return (1);
	}
	free(*content);
	data->win = mlx_new_window(data->mlx, SCREENWIDTH, SCREENHEIGHT,
			"Cube3D Petera");
	data->screen.img = mlx_new_image(data->mlx, SCREENWIDTH, SCREENHEIGHT);
	data->screen.pixels = (int *)mlx_get_data_addr(data->screen.img,
			&data->screen.bpp, &data->screen.size_line, &data->screen.endian);
	init_fps(&data->fps);
	ft_init_hooks(data);
	return (0);
}
