/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:47:15 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/13 22:29:04 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data {
	void    *mlx;
	void    *win;
	double  posX, posY;    // Position du joueur
	double  dirX, dirY;    // Direction du joueur
	double  planeX, planeY;// Plan de la caméra
	int 	render;
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		worldMap[mapWidth][mapHeight];
}			t_data;

#endif // !STRUCT_H