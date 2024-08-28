/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 09:58:10 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/08/28 20:19:57 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	ft_printf("%d\n", keysym);
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	if ((keysym == XK_plus) || (keysym == KEY_PLUS) || (keysym == KEY_EQ))
		fractal->iterations_definition += 8;
	if ((keysym == XK_minus) || (keysym == KEY_MINUS))
		fractal->iterations_definition -= 8;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
		fractal->zoom *= 0.95;
	if (button == Button4)
		fractal->zoom *= 1.05;
	if (button == Button1)
		fractal->shift_x += (0.5 * fractal->zoom);
	if (button == Button3)
		fractal->shift_x -= (0.5 * fractal->zoom);
	(void)x;
	(void)y;
	(void)fractal;
	ft_printf("%d\n", button);
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, WIDTH * fractal->zoom)
				+ fractal->shift_x);
		fractal->julia_y = (map(y, +2, -2, HEIGHT * fractal->zoom)
				+ fractal->shift_x);
		fractal_render(fractal);
	}
	return (0);
}
