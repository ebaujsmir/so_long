/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:43:06 by esmirnov          #+#    #+#             */
/*   Updated: 2022/05/12 11:57:45 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ft_error_arg(ac, av) == 1)
		exit(EXIT_FAILURE);
	ft_data_init(&data);
	ft_map_init(av, &data);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		ft_print_error("main: mlx_init failed\n", &data);
	ft_img_load(&data);
	data.win = mlx_new_window(data.mlx, data.map_x * data.img_size,
			data.map_y * data.img_size, "so_long");
	if (data.win == NULL)
		ft_print_error("main: mlx_win failed\n", &data);
	mlx_loop_hook(data.mlx, ft_map_draw, &data);
	mlx_key_hook(data.win, ft_key_hook, &data);
	mlx_hook(data.win, 33, 1L << 5, ft_exit_hook, &data);
	mlx_hook(data.win, 15, 1L << 16, ft_reduce_window, &data);
	mlx_loop(data.mlx);
	ft_data_free(&data);
	return (0);
}
