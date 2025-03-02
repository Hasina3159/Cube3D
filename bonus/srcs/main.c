/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:09:36 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/01 08:43:53 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

e_bool	ft_load_images_pt2(t_data *data, char *content);

int		main_pt2(char player, t_data data, char *content, int line_index);

int	show_mouse(t_data *data)
{
	data->show_mouse = 1;
	mlx_mouse_show(data->mlx, data->win);
	return (0);
}

int	hide_mouse(t_data *data)
{
	data->show_mouse = 0;
	mlx_mouse_hide(data->mlx, data->win);
	return (0);
}

e_bool	ft_load_images(t_data *data, char *content)
{
	int	index_data;

	if (ft_load_xpm_image(data, &data->image_wall_n, \
	ft_get_data(content, "NO", &index_data)) == false)
		return (false);
	if (ft_load_xpm_image(data, &data->image_wall_s, \
	ft_get_data(content, "SO", &index_data)) == false)
		return (false);
	if (ft_load_xpm_image(data, &data->image_wall_e, \
	ft_get_data(content, "EA", &index_data)) == false)
		return (false);
	if (ft_load_xpm_image(data, &data->image_wall_w, \
	ft_get_data(content, "WE", &index_data)) == false)
		return (false);
	if (ft_load_xpm_image(data, &data->sprite.image[0], \
	"./sprites/sonic1.xpm") == false)
		return (false);
	return (ft_load_images_pt2(data, content));
}

void	ft_init_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, handle_keypress, (void *)data);
	mlx_loop_hook(data->mlx, (int (*)(void *))perform_raycasting, (void *)data);
	mlx_hook(data->win, 3, 1L << 1, handle_keyrelease, (void *)data);
	mlx_hook(data->win, 10, 1L << 21, show_mouse, (void *)data);
	mlx_hook(data->win, 9, 1L << 21, hide_mouse, (void *)data);
	perform_raycasting(data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	char	player;
	t_data	data;
	char	*content;
	int		line_index;

	if (argc != 2)
	{
		printf("Error\nArg number must be two!");
		return (0);
	}
	content = ft_get_content(argv[1]);
	if (content == NULL)
		return (0);
	line_index = ft_check_if_all_data_exists(content);
	data.world_map = ft_get_map(content, line_index);
	if (ft_check_map(data.world_map) == false || line_index == -1)
		return (0);
	player = ft_get_player_position(data.world_map, &data.pos_y, &data.pos_x);
	if (!player)
	{
		printf("Error\nPlayer not found\n");
		return (0);
	}
	data.show_mouse = 0;
	return (main_pt2(player, data, content, line_index));
}
