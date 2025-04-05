/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:49:27 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/30 10:41:58 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void	ft_clean_sprite_images(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (data->sprite.image[i].img_path)
		{
			free(data->sprite.image[i].img_path);
			mlx_destroy_image(data->mlx, data->sprite.image[i].img);
		}
		i++;
	}
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
}

int	clean_up(t_data *data)
{
	if (data->screen.img)
		mlx_destroy_image(data->mlx, data->screen.img);
	if (data->image_wall_n.img_path)
		mlx_destroy_image(data->mlx, data->image_wall_n.img);
	if (data->image_wall_s.img_path)
		mlx_destroy_image(data->mlx, data->image_wall_s.img);
	if (data->image_wall_e.img_path)
		mlx_destroy_image(data->mlx, data->image_wall_e.img);
	if (data->image_wall_w.img_path)
		mlx_destroy_image(data->mlx, data->image_wall_w.img);
	if (data->door.door_sprite.img_path)
	{
		free(data->door.door_sprite.img_path);
		mlx_destroy_image(data->mlx, data->door.door_sprite.img);
	}
	ft_clean_sprite_images(data);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_free_split(data->world_map);
	exit(0);
	return (0);
}
