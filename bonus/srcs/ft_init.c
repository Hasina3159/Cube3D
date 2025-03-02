/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:24:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/02 22:44:58 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

void	ft_init_direction_pt2(t_data *data, char dir);
int		ft_get_color_pt2(char **splitted, char *data_name);

e_bool	ft_is_str_num(char *str)
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

void	ft_init_direction(t_data *data, char dir)
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
	else
		ft_init_direction_pt2(data, dir);
}

int	ft_get_color(char *content, char *data_name)
{
	char	*color_str;
	int		line_index;
	char	**splitted;

	color_str = ft_get_data(content, data_name, &line_index);
	splitted = ft_split(color_str, ',');
	if (ft_get_split_size(splitted) != 3)
	{
		free(color_str);
		ft_free_split(splitted);
		return (-1);
	}
	if (!ft_is_str_num(splitted[0]) || !ft_is_str_num(splitted[1])
		|| !ft_is_str_num(splitted[2]))
	{
		free(color_str);
		ft_free_split(splitted);
		return (-1);
	}
	free(color_str);
	return (ft_get_color_pt2(splitted, data_name));
}

void ft_init_images(t_data *data)
{
	int	i;

	data->image_wall_n.img_path = NULL;
	data->screen.img_path = NULL;
	data->image_wall_s.img_path = NULL;
	data->image_wall_e.img_path = NULL;
	data->image_wall_w.img_path = NULL;
	data->screen.img_path = NULL;
	data->door.door_sprite.img_path = NULL;
	i = 0;
	while (i < 5)
	{
		data->sprite.image[i].img_path = NULL;
		i++;
	}
}