/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:09:36 by fhajanol          #+#    #+#             */
/*   Updated: 2025/04/12 09:21:19 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_bool	ft_load_images_pt2(t_data *data, char *content);

int		main_pt2(char player, t_data *data, char **content);

int	show_mouse(t_data *data)
{
	data->show_mouse = 1;
	return (0);
}

int	hide_mouse(t_data *data)
{
	data->show_mouse = 0;
	return (0);
}

t_bool	ft_load_images(t_data *data, char *content)
{
	if (ft_load_xpm_image(data, &data->sprite.image[1],
			ft_strdup("./bonus/sprites/sonic2.xpm")) == false)
		return (false);
	if (ft_load_xpm_image(data, &data->sprite.image[2],
			ft_strdup("./bonus/sprites/sonic3.xpm")) == false)
		return (false);
	if (ft_load_xpm_image(data, &data->sprite.image[3],
			ft_strdup("./bonus/sprites/sonic4.xpm")) == false)
		return (false);
	if (ft_load_xpm_image(data, &data->sprite.image[4],
			ft_strdup("./bonus/sprites/sonic5.xpm")) == false)
		return (false);
	if (ft_load_xpm_image(data, &data->door.door_sprite,
			ft_strdup("./bonus/sprites/door.xpm")) == false)
		return (false);
	return (ft_load_images_pt2(data, content));
}

void	ft_init_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 1L << 17, clean_up, (void *)data);
	mlx_hook(data->win, 2, 1L << 0, handle_keypress, (void *)data);
	mlx_loop_hook(data->mlx, perform_raycasting, (void *)data);
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

	if (!ft_check_filename(argc, argv))
		return (0);
	ft_init_struct(&data);
	ft_init_images(&data);
	player = 0;
	content = NULL;
	content = ft_b_content(ft_get_content(argv[1]));
	if (content == NULL)
		return (0);
	line_index = ft_check_if_all_data_exists(content) - 1;
	if (line_index == -2)
	{
		free(content);
		return (0);
	}
	data.world_map = ft_get_map(content, line_index);
	if (ft_second_condition(&player, &data, content, line_index) == false)
		return (0);
	data.show_mouse = 0;
	return (main_pt2(player, &data, &content));
}
