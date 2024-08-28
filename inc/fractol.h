/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:19:36 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/08/27 14:09:28 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Please enter \n\t./fractol mandelbrot or \n\t./fractol julia <value_1> <value_2> \n"
# define WIDTH	1200
# define HEIGHT	1200

//colors
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define ELECTRIC_BLUE	0x0066FF
# define HOT_PINK		0xff66B2
# define AQUA_DREAM		0x33CCCC
# define ORANGE			0xFF9933

// Keys
# define KEY_PLUS		65451
# define KEY_MINUS		65453
# define KEY_EQ			61
# define KEY_ESP		32

//struct definitions
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;

}	t_image;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_image	img;
	double	escape_value;
	int		iterations_definition;
	int		current_color;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;

}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

//Funtions prototype general
void		putstr_fd(char *s, int fd);
double		atoidbl(char *s);
void		fractal_init(t_fractal *fractal);
double		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		fractal_render(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);

#endif
