/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:50:41 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/02/08 12:30:10 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "struct.h"
# include "defines.h"

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
void    init_fps(t_fps *fps);
void    update_fps(t_fps *fps);
char	*ft_get_content(char *path);
size_t	ft_get_split_size(char **splitted);
void	ft_free_split(char **splitted);
char	*ft_get_data(char *content, char *data_name, int *line_index);
int		ft_check_if_all_data_exists (char *content);
char	**ft_get_map(char *content, int line_index);
void	ft_print_map(char **map);
e_bool	ft_check_map(char **map);
char	ft_get_player_position(char **map, double *px, double *py);
e_bool	ft_get_sprite_position(char **map, double *px, double *py);
double	ft_dist_calculator(double x1, double y1, double x2, double y2);
void	draw_sprite(t_data *data);
int     ft_gettime(void);
void    ft_draw_mini_map(t_data *data);
void    ft_init_direction(t_data *data, char dir);

#endif // !FUNCTIONS_H