/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:47:15 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/16 21:42:08 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_dda
{
	int		x;
	int		p_x;
	int		p_y;
	int		map_x;
	int		map_y;
	int 	step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		color;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	dist_ortho_wall;
}				t_dda;

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
}			t_data;



#endif // !STRUCT_H