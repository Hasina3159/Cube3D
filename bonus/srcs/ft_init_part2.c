/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 07:55:50 by fhajanol          #+#    #+#             */
/*   Updated: 2025/03/01 11:28:09 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void	ft_init_direction_pt2(t_data *data, char dir)
{
	if (dir == 'E')
	{
		data->dir_x = 0;
		data->dir_y = -1;
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
	else
	{
		data->dir_x = 0;
		data->dir_y = 1;
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
}

int	ft_get_color_pt2(char **splitted, char *data_name)
{
	int	color;

	color = 0;
	color = (ft_atoi(splitted[0]) << 16) | \
	(ft_atoi(splitted[1]) << 8) | ft_atoi(splitted[2]);
	printf("type : %s, (%d,%d,%d), color : %d\n", data_name,
		ft_atoi(splitted[0]), ft_atoi(splitted[1]), ft_atoi(splitted[2]),
		color);
	ft_free_split(splitted);
	return (color);
}
