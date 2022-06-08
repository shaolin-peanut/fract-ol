/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:07:06 by sbars             #+#    #+#             */
/*   Updated: 2022/05/10 12:51:44 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_complex_plane(t_meta *meta, double max, double min)
{
	meta->comp->remin = min;
	meta->comp->remax = min;
	meta->comp->rerange = max - min;
	meta->comp->recenter = (meta->comp->remin + meta->comp->remax) / 2.0;
	meta->comp->imin = min;
	meta->comp->imax = max;
	meta->comp->imrange = max - min;
	meta->comp->imcenter = (meta->comp->imin + meta->comp->imax) / 2.0;
	return (1);
}

t_meta	*malloc_sts() {
	t_meta	*tmp;

	if ((tmp = (t_meta *)malloc(sizeof(t_meta))) == NULL)
		return NULL;
	if ((tmp->comp = (t_comp *)malloc(sizeof(t_comp))) == NULL)
		return NULL;
	return (tmp);
}

t_data	img_init(void *mlx, int	w, int h)
{
    t_data  img;
	//printf("w:%d, h:%d", w, h);
	img.img = mlx_new_image(mlx, w, h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (img.addr == NULL)
		exit(EXIT_FAILURE);
	else
		return (img);
}

t_comp	*comp_init(t_comp	*cp)
{
	cp->zoom_w = 0.0;
	cp->zoom_h = 0.0;
	cp->remin = 0.0;
	cp->remax = 0.0;
	cp->rerange = 0.0;
	cp->recenter = 0.0;
	cp->imin = 0.0;
	cp->imax = 0.0;
	cp->imrange = 0.0;
	cp->imcenter = 0.0;
	cp->cre = -0.8;
	cp->cim = 0.156;
	cp->itermax = ITERATION_MAX;
}

t_meta	*meta_init(int type)
{
	t_meta	*meta;

	meta = malloc_sts();
	if (!meta || !meta->comp)
		return (NULL);
	meta->mlx = mlx_init();
	meta->win = mlx_new_window(meta->mlx, WW, WH, "Fract-ol");
	meta->image = NULL;
	meta->type = type;
	meta->img = img_init(meta->mlx, (int) WW, (int) WH);
	meta->julia_static = -1;
	mlx_key_hook(meta->win, key_hook, (void *) meta);
	mlx_hook(meta->win, 6, 1L << 6, julia_pos, meta);
	mlx_mouse_hook(meta->win, mouse_hook, (void *) meta);
	return (meta);
}
