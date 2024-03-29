/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:06:44 by sbars             #+#    #+#             */
/*   Updated: 2022/07/29 11:48:22 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate(int x, int y, t_meta	*meta, t_cn vroom[2]);

void	init_complex(t_cn *complex)
{
	complex->r = 0.0;
	complex->i = 0.0;
}

t_cn	prep_vars(int x, int y, t_meta *meta)
{
	t_cn	zt;
	t_cn	tmp;
	t_comp	*cp;

	cp = meta->comp;
	init_complex(&zt);
	init_complex(&tmp);
	tmp.r = x / cp->zoom_w + cp->remin;
	tmp.i = y / cp->zoom_h + cp->imin;
	if (meta->type == 0 || meta->type == 2)
	{
		cp->cre = tmp.r;
		cp->cim = tmp.i;
	}
	else if (meta->type == 1)
	{
		zt.r = tmp.r;
		zt.i = tmp.i;
	}
	cp = NULL;
	return (zt);
}

int	plot(t_meta	*meta)
{
	double	x;
	double	y;
	t_cn	coordinates[2];
	t_comp	*cp;

	x = -1.0;
	y = -1.0;
	init_complex(&coordinates[1]);
	cp = meta->comp;
	cp->zoom_w = WW / cp->rerange;
	cp->zoom_h = WH / cp->imrange;
	while (++x < WW)
	{
		y = -1.0;
		while (++y < WH)
		{
			coordinates[0] = prep_vars(x, y, meta);
			calculate(x, y, meta, coordinates);
		}
	}
	mlx_put_image_to_window(meta->mlx, meta->win, meta->img.img, 0, 0);
	return (1);
}

int	color_picker(int i)
{
	return (((i << RED) + (i << GREEN) + (i << BLUE)) & 0xFFFFFF);
}

int	calculate(int x, int y, t_meta *meta, t_cn coordinates[2])
{
	int		i;
	t_cn	z_t;
	t_cn	z_t1;

	i = 0;
	z_t = coordinates[0];
	z_t1 = coordinates[1];
	while (i < ITERATION_MAX && ((z_t1.r * z_t1.r) + (z_t1.i * z_t1.i) < 4))
	{
		z_t1.r = pow(z_t.r, 2) - pow(z_t.i, 2) + meta->comp->cre;
		z_t1.i = 2 * (z_t.r * z_t.i) + meta->comp->cim;
		z_t = z_t1;
		i++;
	}
	if (i == ITERATION_MAX)
		my_mlx_pixel_put(&meta->img, x, y, 0);
	else
		my_mlx_pixel_put(&meta->img, x, y, color_picker(i));
	return (0);
}
// https://lodev.org/cgtutor/juliamandelbrot.html#Mandelbrot_Set_
