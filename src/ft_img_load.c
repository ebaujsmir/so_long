/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:37:19 by esmirnov          #+#    #+#             */
/*   Updated: 2022/05/12 12:10:16 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_img_load(t_data *data)
{
	int	img_width;
	int	img_height;

	img_width = 32;
	img_height = 32;
	data->img_backgr = mlx_xpm_file_to_image(data->mlx,
			"./img/backgr.xpm", &img_width, &img_height);
	ft_img_load_ctrl(img_width, img_height, data);
	data->img_wall = mlx_xpm_file_to_image(data->mlx,
			"./img/wall.xpm", &img_width, &img_height);
	ft_img_load_ctrl(img_width, img_height, data);
	data->img_exit = mlx_xpm_file_to_image(data->mlx,
			"./img/exit.xpm", &img_width, &img_height);
	ft_img_load_ctrl(img_width, img_height, data);
	data->img_pers_front = mlx_xpm_file_to_image(data->mlx,
			"./img/pers_front.xpm", &img_width, &img_height);
	ft_img_load_ctrl(img_width, img_height, data);
	data->img_collect = mlx_xpm_file_to_image(data->mlx,
			"./img/collect.xpm", &img_width, &img_height);
	ft_img_load_ctrl(img_width, img_height, data);
	ft_img_load_check_data(data);
}

void	ft_img_load_ctrl(int img_width, int img_height, t_data *data)
{
	if (img_width != data->img_size || img_height != data->img_size)
		ft_print_error("image_load: wrong image size\n", data);
}

void	ft_img_load_check_data(t_data *data)
{
	if (!data->img_backgr)
		ft_print_error("image_load: image load failed -backgr\n", data);
	if (!data->img_wall)
		ft_print_error("image_load: image load failed -wall\n", data);
	if (!data->img_exit)
		ft_print_error("image_load: image load failed - exit\n", data);
	if (!data->img_pers_front)
		ft_print_error("image_load: image load failed - pers front\n", data);
	if (!data->img_collect)
		ft_print_error("image_load: image load failed - collect\n", data);
}
