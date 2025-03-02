/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:49:27 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/02 23:26:07 by ntodisoa         ###   ########.fr       */
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
			mlx_destroy_image(data->mlx, data->sprite.image[i].img);
		i++;
	}
}

void	clean_up(t_data *data)
{
	printf("1\n");
	if (data->screen.img_path)
		mlx_destroy_image(data->mlx, data->screen.img);
	printf("2\n");
	if (data->image_wall_n.img_path)
		mlx_destroy_image(data->mlx, data->image_wall_n.img);
	printf("3\n");
	if (data->image_wall_s.img_path)
		mlx_destroy_image(data->mlx, data->image_wall_s.img);
	printf("4\n");
	if (data->image_wall_e.img_path)
	{
		if (data->image_wall_e.img_path == 0x1L)
		{
			printf("ING\n");
			free(data->image_wall_e.img_path);
		}
		else
			mlx_destroy_image(data->mlx, data->image_wall_e.img);
	}
	printf("5\n");
	if (data->image_wall_w.img_path)
		mlx_destroy_image(data->mlx, data->image_wall_w.img);
	printf("6\n");
	if (data->door.door_sprite.img_path)
	{
		mlx_destroy_image(data->mlx, data->door.door_sprite.img);
	}
	printf("7\n");
	ft_clean_sprite_images(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_free_split(data->world_map);
	exit(0);
}
