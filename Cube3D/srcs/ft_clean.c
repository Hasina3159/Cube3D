/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:49:27 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/01 16:11:21 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void	clean_up(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, NULL, NULL);
	mlx_hook(data->win, 17, 0L, NULL, NULL);
	mlx_loop_hook(data->mlx, NULL, NULL);
	if (data->screen.img != NULL)
	{
		mlx_destroy_image(data->mlx, data->screen.img);
	}
	if (data->win != NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
	}
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}
