/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:44:04 by esmirnov          #+#    #+#             */
/*   Updated: 2022/05/12 12:01:09 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_read(char **av, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0 || fd == 2 || fd > FD_MAX)
		ft_print_error("map_read: invalid fd\n", data);
	data->map = (char **)malloc(sizeof(char *) * (data->map_y));
	if (!data->map)
		ft_print_error("map_read: data->map malloc failed\n", data);
	ft_data_map_i_init(data);
	i = 0;
	while (i <= data->map_y)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->map[i] = line;
		i++;
	}
	close (fd);
	ft_map_read_check(data);
}

void	ft_map_read_check(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_y)
	{
		if (data->map[i] == NULL)
			ft_print_error("map_read_check: failed\n", data);
		i++;
	}
}
