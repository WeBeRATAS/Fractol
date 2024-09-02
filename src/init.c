/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:27:50 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/02 18:19:41 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	data_init(t_fractal	*fractal)
{
	fractal->escape_value = 6;
	fractal->iterations_definition = 80;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, \
	fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, \
	mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, \
	close_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	init_connection_and_window(fractal);
	init_image(fractal);
	data_init(fractal);
	events_init(fractal);
}
