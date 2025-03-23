/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:09:36 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/23 08:46:33 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_init_hooks(t_data *data);
char	*ft_load_images(t_data *data, char *content);

int	main_pt1(char **argv, t_data *data, int *line_index)
{
	ft_init_struct(data);
	data->content = ft_get_content(argv[1]);
	if (data->content == NULL)
		return (0);
	*line_index = ft_check_if_all_data_exists(data->content);
	if (*line_index == 0)
	{
		free(data->content);
		return (0);
	}
	data->world_map = ft_get_map(data->content, *line_index);
	if (ft_check_map_char(data->world_map) == false
		|| ft_check_map(data->world_map) == false || *line_index == -1)
	{
		free(data->content);
		ft_free_split(data->world_map);
		return (0);
	}
	return (1);
}

int	main_pt2(t_data *data)
{
	char	player;

	player = ft_get_player_position(data->world_map, &(data->pos_y),
			&(data->pos_x));
	if (!player)
	{
		printf("Error\nPlayer not found\n");
		free(data->content);
		ft_free_split(data->world_map);
		return (0);
	}
	data->color_ground = ft_get_color(data->content, "F");
	data->color_sky = ft_get_color(data->content, "C");
	if (data->color_ground < 0)
	{
		printf("Error\nInvalid color value\n");
		free(data->content);
		ft_free_split(data->world_map);
		return (0);
	}
	ft_init_direction(data, player);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*imgs;
	int		line_index;

	if (!ft_check_filename(argc, argv)
		|| !main_pt1(argv, &data, &line_index) || !main_pt2(&data))
		return (0);
	data.render = 0;
	data.mlx = mlx_init();
	init_key(&data.key_data);
	data.screen.img = NULL;
	imgs = ft_load_images(&data, data.content);
	data.win = mlx_new_window(data.mlx, SCREENWIDTH, SCREENHEIGHT,
			"Cube3D Petera");
	data.screen.img = mlx_new_image(data.mlx, SCREENWIDTH, SCREENHEIGHT);
	data.screen.pixels = (int *)mlx_get_data_addr(data.screen.img,
			&data.screen.bpp, &data.screen.size_line, &data.screen.endian);
	if (imgs != NULL)
	{
		free(imgs);
		clean_up(&data);
		return (1);
	}
	ft_init_hooks(&data);
	return (0);
}
