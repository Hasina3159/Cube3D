/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:47:15 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/30 10:42:28 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "defines.h"
# include "functions.h"

typedef struct s_fps
{
	double		last_frame_time;
	double		delta_time;
	double		current_fps;
}				t_fps;

typedef struct s_dda
{
	int			x;
	int			mouse_x;
	int			mouse_y;
	int			map_x;
	int			map_y;
	int			old_map_x;
	int			old_map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			color;
	int			texture_x;
	int			texture_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		dist_ortho_wall;
	double		wall_hit_coord;
}				t_dda;

typedef struct s_img
{
	int			is_empty;
	void		*img;
	char		*img_path;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
	int			sprite_x;
	int			*pixels;
}				t_img;

typedef struct s_key
{
	int			key_w;
	int			key_a;
	int			key_s;
	int			key_d;
	int			key_left;
	int			key_right;
	int			mouse_left;
	int			mouse_right;
}				t_key;

typedef struct s_sprite
{
	t_img		image[5];
	double		pos_x;
	double		pos_y;
	double		pos_z;
	int			screen_x;
	int			draw_start;
	int			draw_end;
	int			screen_height;
	t_bool		render;
}				t_sprite;

typedef struct s_door
{
	t_bool		door_hit;
	t_bool		door_open;
	t_img		door_sprite;
}				t_door;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	double		z_dist[SCREENWIDTH];
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			render;
	int			width;
	int			color_sky;
	int			color_ground;
	char		**world_map;
	int			draw_start;
	int			draw_end;
	int			show_mouse;
	int			show_mouse_enter;
	t_door		door;
	t_fps		fps;
	t_dda		dda;
	t_img		image_wall_n;
	t_img		image_wall_s;
	t_img		image_wall_e;
	t_img		image_wall_w;
	t_img		screen;
	t_key		key_data;
	t_sprite	sprite;

}				t_data;

typedef struct s_sprite_var
{
	int			y;
	int			max;
	t_img		*sprite;
	t_img		*screen;
	t_dda		*dda;
	int			index;
	int			stripe;
	int			tex_x;
	int			new_y;
	int			color;
	int			i;
}				t_sprite_var;

typedef struct s_raycast_var
{
	t_dda		*dda;
	t_bool		show;
	int			start;
	int			end;
	double		ray_hit_x;
	double		ray_hit_y;
	int			dda_x_sprite;
	double		dist_ortho_wall_x;
	double		dist_ortho_wall_y;
	double		t1;
	double		t2;
	double		t3;
	double		t4;
	double		calc1;
	double		calc2;
}				t_raycast_var;

typedef struct s_vline_var
{
	int			y;
	int			i;
	int			max;
	t_img		*sprite;
	t_img		*screen;
	t_dda		*dda;
	int			new_y;
}				t_vline_var;

#endif // !STRUCT_H