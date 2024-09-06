/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:12:05 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/06 10:57:56 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	is_numeric(const char *str)
{
	int	has_decimal;

	has_decimal = 0;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str == '.')
		{
			if (has_decimal)
				return (0);
			has_decimal = 1;
		}
		else if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10))) \
			|| (ac == 4 && (!ft_strncmp(av[1], "julia", 5))))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			if (!is_numeric(av[2]) || !is_numeric(av[3]))
			{
				putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
			fractal.julia_x = atoidbl(av[2]);
			fractal.julia_y = atoidbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
