/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:49:27 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/01 07:30:44 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

/*mlx_hook(data->win, 2, 1L << 0, NULL, NULL);
	mlx_hook(data->win, 17, 0L, NULL, NULL);
	mlx_loop_hook(data->mlx, NULL, NULL);
	*/
void	clean_up(t_data *data)
{
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
