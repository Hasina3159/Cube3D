/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:24:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/14 13:07:13 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

e_bool  ft_is_str_num(char *str)
{
    int i;

    if (str == NULL)
        return (false);
    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

void ft_init_direction(t_data *data, char dir)
{
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
    else if (dir == 'E')
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

int  ft_get_color(char *content, char *data_name)
{
    char    *color_str;
    int     line_index;
    char    **splitted;
    int     color;
    color_str = ft_get_data(content, data_name, &line_index);
    splitted = ft_split(color_str, ',');
    if (ft_get_split_size(splitted) != 3)
    {
        free(color_str);
        ft_free_split(splitted);
        return (-1);        
    }
    if (!ft_is_str_num(splitted[0]) || !ft_is_str_num(splitted[1]) || !ft_is_str_num(splitted[2]))
    {
        free(color_str);
        ft_free_split(splitted);
        return (-1);        
    }
    color = 0;
    color = (ft_atoi(splitted[0]) << 16) | (ft_atoi(splitted[1]) << 8) | ft_atoi(splitted[2]);
    ft_free_split(splitted);
    free(color_str);
    return (color);
}
