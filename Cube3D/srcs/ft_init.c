/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:24:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/08 12:44:43 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void ft_init_direction(t_data *data, char dir)
{
    ft_printf("DIRECTION : %c\n", dir);
    if (dir == 'N')
    {
        data->dir_x = -1;
        data->dir_y = 0;
        data->plane_x = 0;
        data->plane_y = 0.66;
    }
    else if (dir == 'S')
    {
        data->dir_x = 1;
        data->dir_y = 0;
        data->plane_x = 0;
        data->plane_y = -0.66;
    }
    else if (dir == 'W')
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
