/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:06:44 by sbars             #+#    #+#             */
/*   Updated: 2022/05/06 18:02:19 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	algo_selection(t_vars *vars, char *str)
{
	if (ft_strncmp(str, "mandelbrot", 11) == 0)
		plot_mandelbrot(vars);
	else if (ft_strncmp(str, "julia", 6) == 0)
		write(1, "julia", 6);
	return (0);
}

int	plot_mandelbrot(t_vars *vars)
{
	int		x;
	int 	y;
	t_cn	c;
	t_cn	z;
	t_cn	tmp;
	double	i;
	t_data	img;

	x = -1;
	y = -1;

	img_init(vars, &img, WW, WH);
	while (++x < WW)
	{
		y = -1;
		while (++y < WH)
		{

			c.r = 1.5 * (x - WW / 2) / (0.5 * vars->zoom * WW) + vars->moveX;
			c.i = (y - WH / 2) / (0.5 * vars->zoom * WH) + vars->moveY;
			z.r = 0;
			z.i = 0;
			i = 0;

			while (i < ITERATION_MAX)
			{
				tmp.i = z.i;
				tmp.r = z.r;
				z.r = pow(tmp.r, 2) - pow(tmp.i, 2) + c.r;
				z.i = 2 * tmp.i * tmp.r + c.i;
				if (pow(z.r, 2) + pow(z.i, 2) > 4.0)
					break;
				i++;
			}
			if (i == ITERATION_MAX)
				my_mlx_pixel_put(&img, x, y, 0x00000000);
			else
				my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
			y++;
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (0);
}

// https://lodev.org/cgtutor/juliamandelbrot.html#Mandelbrot_Set_
