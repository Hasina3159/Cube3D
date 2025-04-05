/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:34:28 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/30 11:06:46 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// pour cette fonction j'ai du faire l'inverse que d'habitude
//(CAD NULL : TRUE; !NULL : FALSE) 
//pour pouvoir free data sans depasser les 25 lignes
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
	if (ft_load_xpm_image(data, &data->image_wall_e, tmp) == false)
		return (tmp);
	free(tmp);
	tmp = ft_get_data(content, "WE", &index_data);
	if (ft_load_xpm_image(data, &data->image_wall_w, tmp) == false)
		return (tmp);
	free(tmp);
	return (NULL);
}

void	ft_init_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 1L << 17, clean_up, (void *)data);
	mlx_hook(data->win, 2, 1L << 0, handle_keypress, (void *)data);
	mlx_loop_hook(data->mlx, perform_raycasting, (void *)data);
	mlx_hook(data->win, 3, 1L << 1, handle_keyrelease, (void *)data);
	perform_raycasting(data);
	mlx_loop(data->mlx);
}
