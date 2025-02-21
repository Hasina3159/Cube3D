/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:09:36 by fhajanol          #+#    #+#             */
/*   Updated: 2025/02/21 19:33:41 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//pour cette fonction j'ai du faire l'inverse que d'habitude (CAD NULL : TRUE; !NULL : FALSE) pour pouvoir free data sans depasser les 25 lignes
char	*ft_load_images(t_data *data, char *content)
{
	int		index_data;
	char	*tmp;
	
	tmp = ft_get_data(content, "NO", &index_data);
	if (ft_load_xpm_image(data, &data->image_wall_n, tmp) == false)
		return (tmp);
	free(tmp);
	tmp = ft_get_data(content, "SO", &index_data);
	if (ft_load_xpm_image(data, &data->image_wall_s, tmp) == false)
		return (tmp);
	free(tmp);
	tmp = ft_get_data(content, "EA", &index_data);
	printf("\nPATH : %s\n", tmp);
	if (ft_load_xpm_image(data, &data->image_wall_e, tmp) == false)
		return (tmp);
	free(tmp);
	tmp = ft_get_data(content, "WE", &index_data);
	if (ft_load_xpm_image(data, &data->image_wall_w, tmp) == false)
		return (tmp);
	free(tmp);
	return (NULL);
}

void ft_init_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, handle_keypress, (void *)data);
	mlx_loop_hook(data->mlx, (int (*)(void *))perform_raycasting, (void *)data);
	mlx_hook(data->win, 3, 1L << 1, handle_keyrelease, (void *)data);
	perform_raycasting(data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	char	player;
	t_data	data;
	char	*imgs;
	int line_index;

	if (argc != 2)
	{
		printf("Error\nArg number must be two!");
		return (0);
	}
	ft_init_struct(&data);
	data.content = ft_get_content(argv[1]);
	if (data.content == NULL)
		return (0);
	line_index = ft_check_if_all_data_exists(data.content);
	if (line_index == 0)
	{
		free(data.content);
		return (0);
	}
	data.world_map = ft_get_map(data.content, line_index);
	if (ft_check_map_char(data.world_map) == false || ft_check_map(data.world_map) == false || line_index == -1)
	{
		free(data.content);
		ft_free_split(data.world_map);
		return (0);
	}
	player = ft_get_player_position(data.world_map, &data.pos_y, &data.pos_x);
	if (!player)
	{
		printf("Error\nPlayer not found\n");
		free(data.content);
		ft_free_split(data.world_map);
		return (0);
	}
	data.color_ground = ft_get_color(data.content, "F");
	data.color_sky = ft_get_color(data.content, "C");
	ft_init_direction(&data, player);
	data.render = 0;
	data.mlx = mlx_init();
	init_key (&data.key_data);
	data.screen.img = NULL;
	imgs = ft_load_images(&data, data.content);
	if (imgs != NULL)
	{
		free(imgs);
		clean_up(&data);
		return (1);
	}
	data.win = mlx_new_window(data.mlx, SCREENWIDTH, SCREENHEIGHT,
			"Cube3D Petera");
	data.screen.img = mlx_new_image(data.mlx, SCREENWIDTH, SCREENHEIGHT);
	data.screen.pixels = (int *)mlx_get_data_addr(data.screen.img, &data.screen.bpp, &data.screen.size_line, &data.screen.endian);
	ft_init_hooks(&data);
	return (0);
}
