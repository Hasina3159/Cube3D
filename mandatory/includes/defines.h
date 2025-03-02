/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:45:14 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/01 11:04:29 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define KEY_ENTER 65293
# define KEY_SPACE 32
# define SCREENWIDTH 1920
# define SCREENHEIGHT 1080
# define MAPWIDTH 23
# define MAPHEIGHT 24
# define MOVE_SPEED 0.00003
# define MOVE_SPEED_FACTOR 5000
# define ROTATION_SPEED 0.00001
# define IMG_WIDTH 128
# define IMG_HEIGHT 128
# define NORTH 0
# define SOUTH 2
# define WEST 1
# define EAST 3
# define SQUARE_SIZE 10

typedef enum enum_bool
{
	false,
	true
}	e_bool;

#endif // ! DEFINES_H
