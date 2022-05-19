/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:37:30 by esmirnov          #+#    #+#             */
/*   Updated: 2022/05/12 12:06:58 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_draw(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_y)
	{
		j = 0;
		while (j < data->map_x)
		{
			if (data->map[i][j] == '1')
				ft_put_img(i, j, data->img_wall, data);
			else if (data->map[i][j] == 'P')
				ft_put_img(i, j, data->img_pers_front, data);
			else if (data->map[i][j] == 'C')
				ft_put_img(i, j, data->img_collect, data);
			else if (data->map[i][j] == 'E')
				ft_put_img(i, j, data->img_exit, data);
			else if (data->map[i][j] == '0')
				ft_put_img(i, j, data->img_backgr, data);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_put_img(int i, int j, void *img, t_data *data)
{
	i *= data->img_size;
	j *= data->img_size;
	mlx_put_image_to_window(data->mlx, data->win, img, j, i);
}
