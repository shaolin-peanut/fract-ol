/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:06:44 by sbars             #+#    #+#             */
/*   Updated: 2022/05/09 19:13:40 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int	algo_selection(t_meta	*meta, char *str)
{
	if (ft_strncmp(str, "mandelbrot", 11) == 0)
		plot(meta);
	else if (ft_strncmp(str, "julia", 6) == 0)
		write(1, "julia", 6);
	else
		write(1, "Wrong input. Usage:\n- mandelbrot\n- julia", 30);
	return (0);
}*/

void	set_complex_plane(t_meta	*meta)
{
	if (meta->type == 0)
	{
		meta->comp->remin = -2;
		meta->comp->remax = 2;
		meta->comp->imin = -2;
		meta->comp->imax = 2;
		meta->comp->zre = meta->comp->remin + meta->comp->remax; // create range, not final z_re
		meta->comp->zim = meta->comp->imin + meta->comp->imax;
	}
	else
		exit(EXIT_FAILURE);
}

int	plot(t_meta	*meta)
{
	int	x;
	int	y;

	x = -1;
	y = -1;

	while (++x < WW)
	{
		y = -1;
		while (++y < WH)
		{
			meta->comp->zre *= x / WW;
			meta->comp->zim *= y / WH;
			if (meta->type == 0)
				mandelbrot(x, y, meta);
		}
	}
	// PREP
	// Important elements:
	// formula: Zt+1 = sqrt(Zt) + Z0
	// STEP 1:
	// Take a number of your window (cartesian plane), project it to the complex plane. Complex has two dimensions, and is small for fractals (-2, 2), etc.
	// How to project it?
	// z->re = x / width * (x_max + x_min)
	// z->im = y / height * (y_max - y_min)
	// STEP 2
	// Apply equation
	// identite remarquable (sqrt(x + y) = sqrt(a) + 2xy + sqrt(y))
	// Z-REAL = sqrt(x) - sqrt(y) + x
	// Z-IMAG = 2(x * y) + y
	return (1);	
}

double c_abs(t_cn z)
{
    return (z.r * z.r + z.i * z.i);
}

int	mandelbrot(int	x, int	y, t_meta	*meta)
{
	t_cn	old;
	t_cn	current;
	int		i;
	t_data	img;

	img_init(meta, &img, WW, WH);
	i		= 0;
	current.r	= meta->comp->zre;
	current.i	= meta->comp->zim;
	while (i < ITERATION_MAX)
	{
		old.r = current.r;
		old.i = current.i;
		current.r = pow(old.r, 2) - pow(old.i, 2) + meta->comp->zre;
		current.i = 2 * (old.r * old.i) + meta->comp->zim;
		if (/*(pow(current.r, 2) * pow(current.i, 2) < 4 || */c_abs(current) > 4.0)
			break;
		i++;
	}
	if (i == ITERATION_MAX)
		my_mlx_pixel_put(&img, x, y, 0x00000000);
	else
		my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
	mlx_put_image_to_window(meta->mlx, meta->win, img.img, 0, 0);
	return (0);
}

// https://lodev.org/cgtutor/juliamandelbrot.html#Mandelbrot_Set_
