/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:47:15 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/18 15:52:24 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_dda
{
	int		x;
	int		mouse_x;
	int		mouse_y;
	int		map_x;
	int		map_y;
	int		old_map_x;
	int		old_map_y;
	int 	step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		color;
	int		texture_x;
	int		texture_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	dist_ortho_wall;
	double	wall_hit_coord;
}			t_dda;

typedef struct s_img
{
	int		is_empty;
	void	*img;
	char	*img_path;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	int		sprite_x;
	int		*pixels;
}			t_img;

typedef struct s_key
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	key_left;
	int	key_right;
	int	mouse_left;
	int	mouse_right;
}		t_key;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		render;
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		world_map[MAPWIDTH][MAPHEIGHT];
	int		draw_start;
	int		draw_end;
	t_dda	dda;
	t_img	image_wall_n;
	t_img	image_wall_s;
	t_img	image_wall_e;
	t_img	image_wall_w;
	t_key	key_data;
}			t_data;


#endif // !STRUCT_H