/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:07:06 by sbars             #+#    #+#             */
/*   Updated: 2022/05/06 17:53:28 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int code, int x, int y, t_vars *vars)
{
	double	zm;

	zm = vars->zoom;
	vars->x = x;
	vars->y = y;
	if (code == 5)
	{
		vars->zoom += 0.2;
		plot_mandelbrot(vars);
	}
	else if (code == 4 && zm > 5.0)
	{
		vars->zoom -= 0.1;
		plot_mandelbrot(vars);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	img_init(t_vars *vars, t_data *img, int	w, int h)
{
	img->img = mlx_new_image(vars->mlx, w, h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	vars_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WW, WH, "Fract-ol");
	vars->zoom = 1.0;
	vars->moveX = -0.5;
	vars->moveY = 0;
	vars->x = 0;
	vars->y = 0;
	vars->image = NULL;
	vars->fractal = NULL;
	mlx_key_hook(vars->win, key_hook, (void *) vars);
	mlx_mouse_hook(vars->win, mouse_hook, (void *) vars);
}

/*void	colors_selection()
{
	if (n < MAX_ITERATIONS && n > 0) {
		int i = n % 16;
		QColor mapping[16];
		mapping[0].setRgb(66, 30, 15);
		mapping[1].setRgb(25, 7, 26);
		mapping[2].setRgb(9, 1, 47);
		mapping[3].setRgb(4, 4, 73);
		mapping[4].setRgb(0, 7, 100);
		mapping[5].setRgb(12, 44, 138);
		mapping[6].setRgb(24, 82, 177);
		mapping[7].setRgb(57, 125, 209);
		mapping[8].setRgb(134, 181, 229);
		mapping[9].setRgb(211, 236, 248);
		mapping[10].setRgb(241, 233, 191);
		mapping[11].setRgb(248, 201, 95);
		mapping[12].setRgb(255, 170, 0);
		mapping[13].setRgb(204, 128, 0);
		mapping[14].setRgb(153, 87, 0);
		mapping[15].setRgb(106, 52, 3);
		return mapping[i];
	}
	else return Qt::black;
}*/
