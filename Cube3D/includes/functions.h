/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:50:41 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/01/16 21:51:25 by ntodisoa         ###   ########.fr       */
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

#endif // !FUNCTIONS_H