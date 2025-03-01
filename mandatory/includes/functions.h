/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhajanol <fhajanol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:50:41 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/03/01 11:04:31 by fhajanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "defines.h"
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
void	init_key(t_key *key_data);
void	key_render(t_data *data);
int		ft_load_xpm_image(t_data *data, t_img *image, char *path);
char	*ft_get_content(char *path);
size_t	ft_get_split_size(char **splitted);
void	ft_free_split(char **splitted);
char	*ft_get_data(char *content, char *data_name, int *line_index);
int		ft_check_if_all_data_exists(char *content);
char	**ft_get_map(char *content, int line_index);
void	ft_print_map(char **map);
e_bool	ft_check_map(char **map);
char	ft_get_player_position(char **map, double *px, double *py);
double	ft_dist_calculator(double x1, double y1, double x2, double y2);
void	ft_draw_mini_map(t_data *data);
void	ft_init_direction(t_data *data, char dir);
e_bool	ft_check_file_validity(char *path);
int		ft_get_color(char *content, char *data_name);
void	ft_init_struct(t_data *data);
e_bool	ft_check_map_char(char **map);
void	ft_free_string_and_splitted(char *str, char **splitted);
void	ft_get_player_position_assign(double *px, double *py, int x, int y);
e_bool	ft_is_valid_char(char c, char *s);

#endif // !FUNCTIONS_H