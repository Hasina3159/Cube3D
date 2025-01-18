#include "../includes/defines.h"
#include "../includes/functions.h"
#include "../includes/struct.h"

int ft_load_xpm_image(t_data *data, t_img *image, char *path)
{
	image->img_path = ft_strdup(path);
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