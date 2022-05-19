/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:57:01 by esmirnov          #+#    #+#             */
/*   Updated: 2022/05/12 16:02:14 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_arg(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error\nerror_arg: invalide number of arguments\n", 2);
		return (1);
	}
	if (ft_strlen(av[1]) < 5)
	{
		ft_putstr_fd("Error\nerror_arg: invalide argument\n", 2);
		return (1);
	}
	if (ft_error_arg_ext(av) == 1)
		return (1);
	return (0);
}

int	ft_error_arg_ext(char **av)
{
	int	i;

	i = ft_strlen(av[1]) - 1;
	if (av[1][i] != 'r')
	{
		ft_putstr_fd("Error\nerror_arg: invalide file extention\n", 2);
		return (1);
	}
	if (av[1][i - 1] != 'e')
	{
		ft_putstr_fd("Error\nerror_arg: invalide file extention\n", 2);
		return (1);
	}
	if (av[1][i - 2] != 'b')
	{
		ft_putstr_fd("Error\nerror_arg: invalide file extention\n", 2);
		return (1);
	}
	if (av[1][i - 3] != '.')
	{
		ft_putstr_fd("Error\nerror_arg: invalide file extention\n", 2);
		return (1);
	}
	return (0);
}
