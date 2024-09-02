/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:25:22 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/02 13:35:00 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void	fractal_cleanup(t_fractal *fractal)
{
	if (fractal->img.img_ptr)
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	if (fractal->mlx_window)
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	if (fractal->mlx_connection)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
	}
	free(fractal);
}

void	init_connection_and_window(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, \
			HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
}

void	init_image(t_fractal *fractal)
{
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, \
			HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		fractal_cleanup(fractal);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, \
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
}
