/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:50:41 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/18 13:34:31 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "struct.h"

void	perform_raycasting(t_data *data);
void	move_forward(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_backward(t_data *data);
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);
void	clean_up(t_data *data);
int		handle_keypress(int keycode, t_data *data);
int		handle_keyrelease(int keycode, t_data *data);
void	draw_vertical_line(t_data *data);
void	perform_raycasting(t_data *data);
void    move_mouse_to_center(t_data *data);
void    init_key (t_key *key_data);
void    key_render (t_data *data);
int     ft_load_xpm_image(t_data *data, t_img *image, char *path);

#endif // !FUNCTIONS_H