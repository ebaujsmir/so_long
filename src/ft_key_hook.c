/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:34:59 by esmirnov          #+#    #+#             */
/*   Updated: 2022/05/12 12:07:12 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_exit_hook(data);
	if (keycode == UP)
		ft_move_player(data, 0, -1);
	if (keycode == RIGHT)
		ft_move_player(data, 1, 0);
	if (keycode == LEFT)
		ft_move_player(data, -1, 0);
	if (keycode == DOWN)
		ft_move_player(data, 0, 1);
	return (1);
}

int	ft_exit_hook(t_data *data)
{
	ft_data_free(data);
	return (0);
}

int	ft_reduce_window(t_data *data)
{
	ft_map_draw(data);
	return (1);
}
