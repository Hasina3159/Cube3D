/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:10:19 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/20 17:42:03 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

e_bool ft_check_file_validity(char *path)
{
    int fd;
    
    if (path == NULL)
        printf("Error\nNULL path!");
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        printf("Error\n");
        perror(path);
        return (false);
    }
    close(fd);
    return (true);
}

int ft_load_xpm_image(t_data *data, t_img *image, char *path)
{
    if (ft_check_file_validity(path) == false)
    {
        image->img = NULL;
        image->pixels = NULL;
        return (0);
    }
	image->img_path = path;
	image->img = mlx_xpm_file_to_image(data->mlx, image->img_path, &image->height, &image->width);
    if (image->img == NULL)
    {
        free(image->img_path);
        image->img_path = NULL;
        return (0);
    }
    image->pixels = (int *)mlx_get_data_addr(image->img, &image->bpp, &image->size_line, &image->endian);
    return (1);
}

void ft_create_screen_image(t_img *image)
{
	image->pixels = (int *)mlx_get_data_addr(image->img, &image->bpp, &image->size_line, &image->endian);
}