/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:43:54 by esmirnov          #+#    #+#             */
/*   Updated: 2022/05/17 14:36:11 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

# define MAP_MAX_SIZE_X 80
# define MAP_MAX_SIZE_Y 42

typedef struct s_data
{
	char	**map;
	int		map_x;
	int		map_y;
	int		c;
	int		p;
	int		e;
	int		moves;
	int		img_size;
	int		pers_x;
	int		pers_y;
	void	*mlx;
	void	*win;
	void	*img_pers_front;
	void	*img_collect;
	void	*img_backgr;
	void	*img_wall;
	void	*img_exit;
}			t_data;

int		ft_error_arg(int ac, char **av);
void	ft_print_error(char *text, t_data *data);
int		ft_error_arg_ext(char **av);
void	ft_data_init(t_data *data);
void	ft_data_free(t_data *data);
void	ft_map_init(char **av, t_data *data);
void	ft_data_map_i_init(t_data *data);
void	ft_map_read(char **av, t_data *data);
void	ft_map_size(char **av, t_data *data);
void	ft_map_size_max_min(t_data *data);
void	ft_map_read_check(t_data *data);
void	ft_map_check(t_data *data);
void	ft_mlx_destroy(t_data *data);
void	ft_map_x_y(int fd, t_data *data);
void	ft_check_x_y(t_data *data);
void	ft_map_not_rect(char *line, t_data *data);
void	ft_map_check_rect(t_data *data);
void	ft_map_check_walls(t_data *data);
void	ft_map_check_char(t_data *data);
void	ft_map_check_items(t_data *data);
void	ft_map_pers_position(t_data *data);
int		ft_map_draw(t_data *data);
void	ft_put_img(int i, int j, void *img, t_data *data);
void	ft_img_load(t_data *data);
void	ft_img_load_ctrl(int img_width, int img_height, t_data *data);
void	ft_img_load_check_data(t_data *data);
int		ft_key_hook(int keycode, t_data *data);
int		ft_exit_hook(t_data *data);
int		ft_reduce_window(t_data *data);
void	ft_move_player(t_data *data, int x, int y);

#endif