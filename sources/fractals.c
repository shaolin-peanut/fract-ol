/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:06:44 by sbars             #+#    #+#             */
/*   Updated: 2022/05/10 12:51:45 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_complex_plane(t_meta *meta, double max, double min)
{
	meta->comp->remin = min; //-2.1;
	meta->comp->remax = min; // 0.6;
    meta->comp->rerange = max - min;
    meta->comp->recenter = (meta->comp->remin + meta->comp->remax) / 2.0;
	meta->comp->imin = min;
	meta->comp->imax = max;
    meta->comp->imrange = max - min;
    meta->comp->imcenter = (meta->comp->imin + meta->comp->imax) / 2.0;
	return (1);
}

t_cn	init_complex()
{
	t_cn	*complex;

	complex = (t_cn *)malloc(sizeof(t_cn));
	if (!complex)
		exit(EXIT_FAILURE);
	complex->r = 0.0;
	complex->i = 0.0;
	return (*complex);
}

int	plot(t_meta	*meta)
{
	double	x;
	double	y;
    t_cn    z_t;
	t_cn    z_t1;
    t_comp  *cp;
	//t_cn	tmp;

	x = -1.0;
    y = -1.0;
    cp = meta->comp;
    cp->zoom_w = WW / cp->rerange;
    cp->zoom_h = WH / cp->imrange;
    z_t = init_complex();
    z_t1 = init_complex();
    z_t.r = meta->comp->cre;
    z_t.i = meta->comp->cre;
    z_t1.r = z_t.r;
    z_t1.i = z_t.i;

	// TEST PLOTTING SOMETHING, ANYTHING, FROM HERE, TO CHECK IF MLX WORKS
	while (++x < WW)
	{
		y = -1.0;
		while (++y < WH)
		{
			meta->comp->cre = x / cp->zoom_w + cp->remin;
			meta->comp->cim = y / cp->zoom_h + cp->imin;
			if (meta->type == 0)
				mandelbrot(x, y, meta, z_t, z_t1);
		}
	}
	mlx_put_image_to_window(meta->mlx, meta->win, meta->img.img, 0, 0);
	return (1);	
}

int	mandelbrot(int	x, int	y, t_meta	*meta, t_cn z_t, t_cn z_t1)
{
	int		i;

	i		= 0;
	while (i < ITERATION_MAX && ((z_t1.r * z_t1.r) + (z_t1.i * z_t1.i) < 4))
	{
		z_t1.r = pow(z_t.r, 2) - pow(z_t.i, 2) + meta->comp->cre;
		z_t1.i = 2 * (z_t.r * z_t.i) + meta->comp->cim;
        z_t = z_t1;
		i++;
	}
	if (i == ITERATION_MAX)
    {
        //printf("I am in the set!\n");
		my_mlx_pixel_put(&meta->img, x, y, 0);
    }
	else
    {
        my_mlx_pixel_put(&meta->img, x, y, (((i << RED) + (i << GREEN) + (i << BLUE)) & 0xFFFFFF));
    }
	return (0);
}

// https://lodev.org/cgtutor/juliamandelbrot.html#Mandelbrot_Set_
