/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:24:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/04/12 08:22:33 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void	ft_init_struct(t_data *data)
{
	data->image_wall_n.img = NULL;
	data->image_wall_s.img = NULL;
	data->image_wall_e.img = NULL;
	data->image_wall_w.img = NULL;
	data->image_wall_n.img_path = NULL;
	data->image_wall_s.img_path = NULL;
	data->image_wall_e.img_path = NULL;
	data->image_wall_w.img_path = NULL;
	data->screen.img = NULL;
}

t_bool	ft_is_str_num(char *str)
{
	int	i;

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

t_bool	ft_init_direction_0(t_data *data, char dir)
{
	if (dir == 'N')
	{
		data->dir_x = -1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
		return (true);
	}
	else if (dir == 'S')
	{
		data->dir_x = 1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
		return (true);
	}
	return (false);
}

void	ft_init_direction(t_data *data, char dir)
{
	if (ft_init_direction_0(data, dir))
		return ;
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

int	ft_get_color(char *content, char *data_name)
{
	char	*color_str;
	int		line_index;
	char	**splitted;
	int		color;

	color_str = ft_get_data(content, data_name, &line_index);
	if (!*color_str || color_str[0] == ',' || \
	color_str[ft_strlen(color_str) - 1] == ',')
		return (free(color_str), -1);
	splitted = ft_split(color_str, ',');
	if (ft_check_color_lst(splitted) == false)
		return (ft_free_split(splitted), free(color_str), -1);
	if (!ft_is_str_num(splitted[0]) || !ft_is_str_num(splitted[1])
		|| !ft_is_str_num(splitted[2]) || ft_atoi(splitted[0]) > 255
		|| ft_atoi(splitted[1]) > 255 || ft_atoi(splitted[2]) > 255)
		return (ft_free_split(splitted), free(color_str), -1);
	color = 0;
	color = (ft_atoi(splitted[0]) << 16) | (ft_atoi(splitted[1]) << 8)
		| ft_atoi(splitted[2]);
	ft_free_string_and_splitted(color_str, splitted);
	return (color);
}
