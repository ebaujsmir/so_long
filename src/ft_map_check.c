/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:37:26 by esmirnov          #+#    #+#             */
/*   Updated: 2022/05/12 11:59:12 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_check(t_data *data)
{
	ft_map_check_rect(data);
	ft_map_check_walls(data);
	ft_map_check_char(data);
	ft_map_check_items(data);
	ft_map_pers_position(data);
}

void	ft_map_check_rect(t_data *data)
{
	int	i;
	int	a;

	i = 0;
	while (i < data->map_y - 1)
	{
		a = ((int)ft_strlen(data->map[i])) - 1;
		if (a != data->map_x)
			ft_print_error("map_check_rect: invalid map 1\n", data);
		i++;
	}
	a = ((int)ft_strlen(data->map[i]));
	if (a - 1 != data->map_x)
	{
		if (a != data->map_x)
			ft_print_error("map_check_rect: invalid map 2\n", data);
		else if (data->map[i][data->map_x] != '\0')
			ft_print_error("map_check_rect: invalid map 3\n", data);
	}
}

void	ft_map_check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = data->map_y - 1;
	while (i < data->map_x - 1)
	{
		if ((data->map[0][i] != '1') || (data->map[j][i] != '1'))
			ft_print_error("map_check_walls: invalid map 1\n", data);
		i++;
	}
	i = data->map_x - 1;
	j = 1;
	while (j < data->map_y - 1)
	{
		if ((data->map[j][0] != '1') || data->map[j][i] != '1')
			ft_print_error("map_check_walls: invalid map 2\n", data);
		j++;
	}
}

void	ft_map_check_char(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	while (j < data->map_y - 1)
	{
		i = 1;
		while (i < data->map_x - 1)
		{
			if (data->map[j][i] == 'C' || data->map[j][i] == 'P' ||
				data->map[j][i] == 'E' || data->map[j][i] == '1' ||
				data->map[j][i] == '0')
				i++;
			else
				ft_print_error("map_check_char: forbidden element(s)\n", data);
		}
		j++;
	}
}

void	ft_map_check_items(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	while (j < data->map_y - 1)
	{
		i = 1;
		while (i < data->map_x - 1)
		{
			if (data->map[j][i] == 'C')
				data->c++;
			if (data->map[j][i] == 'P')
				data->p++;
			if (data->map[j][i] == 'E')
				data->e++;
			i++;
		}
		j++;
	}
	if (data->p != 1)
		ft_print_error("map_check_item: one player should be on map\n", data);
	if (data->c == 0)
		ft_print_error("map_check_item: collectible is missing\n", data);
	if (data->e == 0)
		ft_print_error("map_check_item: exit is missing\n", data);
}
