/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:44:21 by esmirnov          #+#    #+#             */
/*   Updated: 2022/05/12 12:05:01 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = data->pers_x;
	j = data->pers_y;
	if (data->map[j + y][i + x] == 'E' && data->c == 0)
	{
		data->moves++;
		ft_putnbr_fd(data->moves, 1);
		ft_putchar_fd('\n', 1);
		ft_data_free(data);
	}	
	if (data->map[j + y][i + x] == '0' || data->map[j + y][i + x] == 'C')
	{
		if (data->map[j + y][i + x] == 'C')
			data->c--;
		data->map[j][i] = '0';
		data->map[j + y][i + x] = 'P';
		data->pers_x += x;
		data->pers_y += y;
		data->moves++;
		ft_putnbr_fd(data->moves, 1);
		ft_putchar_fd('\n', 1);
	}
}
