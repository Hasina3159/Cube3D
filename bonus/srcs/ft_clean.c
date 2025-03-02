/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:49:27 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/01 12:02:46 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void	clean_up(t_data *data)
{
	if (data->screen.img)
		mlx_destroy_image(data->mlx, data->screen.img);
	if (data->image_wall_n.img)
		mlx_destroy_image(data->mlx, data->image_wall_n.img);
	if (data->image_wall_s.img)
		mlx_destroy_image(data->mlx, data->image_wall_s.img);
	if (data->image_wall_e.img)
		mlx_destroy_image(data->mlx, data->image_wall_e.img);
	if (data->image_wall_w.img)
		mlx_destroy_image(data->mlx, data->image_wall_w.img);
	if (data->door.door_sprite.img)
		mlx_destroy_image(data->mlx, data->door.door_sprite.img);

	if (data->win != NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
	}
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_free_split(data->world_map);
	exit(0);
}