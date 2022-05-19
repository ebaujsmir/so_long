/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:44:27 by esmirnov          #+#    #+#             */
/*   Updated: 2022/05/12 12:05:41 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_error(char *text, t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(text, 2);
	ft_data_free(data);
	exit(EXIT_FAILURE);
}
