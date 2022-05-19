/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:39:23 by esmirnov          #+#    #+#             */
/*   Updated: 2022/05/12 12:11:23 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_data_init(t_data *data)
{
	data->map = NULL;
	data->map_x = 0;
	data->map_y = 0;
	data->c = 0;
	data->p = 0;
	data->e = 0;
	data->moves = 0;
	data->img_size = 32;
	data->pers_x = 0;
	data->pers_y = 0;
	data->mlx = NULL;
	data->win = NULL;
	data->img_pers_front = NULL;
	data->img_collect = NULL;
	data->img_backgr = NULL;
	data->img_wall = NULL;
	data->img_exit = NULL;
}

void	ft_data_map_i_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_y)
	{
		data->map[i] = NULL;
		i++;
	}
}
