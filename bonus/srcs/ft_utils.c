/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:38:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/23 11:24:27 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include <fcntl.h>
#include <math.h>
#include <unistd.h>

t_bool	ft_second_condition(char *pl, t_data *dt, char *cntnt, int ln_idx)
{
	if (ft_check_map_char(dt->world_map) == false
		|| ft_check_map(dt->world_map) == false || ln_idx == -1)
	{
		printf("Error\nInvalid map\n");
		free(cntnt);
		ft_free_split(dt->world_map);
		return (false);
	}
	*pl = ft_get_player_position(dt->world_map, &dt->pos_y, &dt->pos_x);
	if (!pl)
	{
		free(cntnt);
		ft_free_split(dt->world_map);
		printf("Error\nPlayer not found\n");
		return (false);
	}
	return (true);
}

size_t	ft_get_split_size(char **splitted)
{
	size_t	i;

	if (splitted == NULL)
		return (0);
	i = 0;
	while (splitted[i])
		i++;
	return (i);
}

int	ft_free_split(char **splitted)
{
	int	i;

	if (splitted == NULL)
		return (1);
	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (1);
}

double	ft_dist_calculator(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
