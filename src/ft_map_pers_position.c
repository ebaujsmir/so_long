/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_pers_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:43:56 by esmirnov          #+#    #+#             */
/*   Updated: 2022/05/12 12:06:00 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_pers_position(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	while (j < data->map_y - 1)
	{
		i = 1;
		while (i < data->map_x - 1)
		{
			if (data->map[j][i] == 'P')
			{
				data->pers_x = i;
				data->pers_y = j;
			}
			i++;
		}
		j++;
	}
}
