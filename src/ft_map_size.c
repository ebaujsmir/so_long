/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:44:14 by esmirnov          #+#    #+#             */
/*   Updated: 2022/05/17 14:35:51 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_size(char **av, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0 || fd == 2 || fd > FD_MAX)
		ft_print_error("map_size: invalid fd\n", data);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (data->map_x < (int)ft_strlen(line) - 1)
			data->map_x = ft_strlen(line) - 1;
		free (line);
		data->map_y++;
	}
	close (fd);
	ft_map_size_max_min(data);
}

void	ft_map_size_max_min(t_data *data)
{
	if (data->map_x > MAP_MAX_SIZE_X || data->map_y > MAP_MAX_SIZE_Y)
		ft_print_error("map_size: invalid map size\n", data);
	if ((data->map_x < 5 && data->map_y < 3)
		|| (data->map_x < 3 && data->map_y < 5))
		ft_print_error("map_size: invalid map size\n", data);
}
