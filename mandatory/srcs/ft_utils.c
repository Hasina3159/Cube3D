/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:38:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/30 10:40:23 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

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

void	ft_free_string_and_splitted(char *str, char **splitted)
{
	free(str);
	ft_free_split(splitted);
}

void	ft_get_player_position_assign(double *px, double *py, int x, int y)
{
	*px = (double)x + 0.5;
	*py = (double)y + 0.5;
}
