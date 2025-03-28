/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:49:27 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/23 11:02:00 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

int	clean_up(t_data *data)
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
	if (data->win != NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
	}
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data->content);
	ft_free_split(data->world_map);
	exit(0);
	return (0);
}

char	**ft_clone_map(char **map)
{
	int		i;
	int		j;
	char	**new_map;

	new_map = (char **)malloc(sizeof(char *) * (ft_get_split_size(map) + 1));
	if (!new_map)
		return (NULL);
	i = -1;
	while (map[++i])
		new_map[i] = ft_strdup(map[i]);
	new_map[i] = NULL;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (new_map[i][j])
		{
			if (new_map[i][j] != '1' && new_map[i][j] != ' ')
				new_map[i][j] = '0';
			j++;
		}
	}
	return (new_map);
}
