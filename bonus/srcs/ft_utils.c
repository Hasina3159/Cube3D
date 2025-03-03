/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:38:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/03 20:55:43 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include <fcntl.h>
#include <math.h>
#include <unistd.h>

e_bool	ft_second_condition(char *pl, t_data *dt, char *cntnt, int ln_idx)
{
	if (ft_check_map_char(dt->world_map) == false
		|| ft_check_map(dt->world_map) == false || ln_idx == -1)
	{
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
	int	i;

	if (splitted == NULL)
		return (0);
	i = 0;
	while (splitted[i])
		i++;
	return (i);
}

void	ft_free_split(char **splitted)
{
	int	i;

	if (splitted == NULL)
		return ;
	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return ;
}

double	ft_dist_calculator(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
