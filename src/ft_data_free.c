/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:37:07 by esmirnov          #+#    #+#             */
/*   Updated: 2022/05/12 12:04:23 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_data_free(t_data *data)
{
	int	i;

	if (data->map)
	{
		i = 0;
		while (i < data->map_y)
		{
			if (data->map[i] != NULL)
				free (data->map[i]);
			i++;
		}
		free (data->map);
	}
	ft_mlx_destroy(data);
	free(data->mlx);
	exit (0);
}

void	ft_mlx_destroy(t_data *data)
{
	if (data->img_pers_front)
		mlx_destroy_image(data->mlx, data->img_pers_front);
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_collect)
		mlx_destroy_image(data->mlx, data->img_collect);
	if (data->img_backgr)
		mlx_destroy_image(data->mlx, data->img_backgr);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
}
