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
	//tmp->colors = (t_colors *)malloc(sizeof(t_colors));
	return (tmp);
}

t_data	img_init(void *mlx, int	w, int h)
{
    t_data  img;
	//printf("w:%d, h:%d", w, h);
	img.img = mlx_new_image(mlx, w, h);
	if ((img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian)) == NULL)
		exit(EXIT_FAILURE);
    else
        return (img);
}

t_meta	*meta_init(int	type)
{
	t_meta	*meta;

	meta	= malloc_sts();	
	if (!meta || !meta->comp)
		return (NULL);
	meta->mlx = mlx_init();
	meta->win = mlx_new_window(meta->mlx, WW, WH, "Fract-ol");
	meta->image = NULL;
	meta->comp->zoom_w = 0.0;
	meta->comp->zoom_h = 0.0;
	meta->comp->remin = 0.0;
	meta->comp->remax = 0.0;
    meta->comp->rerange = 0.0;
    meta->comp->recenter = 0.0;
	meta->comp->imin = 0.0;
	meta->comp->imax = 0.0;
    meta->comp->imrange = 0.0;
	meta->comp->imcenter = 0.0;
    meta->comp->cre = -0.8;
    meta->comp->cim = 0.156;
    meta->julia_static = -1;
    meta->comp->itermax = ITERATION_MAX;
	meta->type = type;
    meta->img = img_init(meta->mlx, (int) WW, (int) WH);
	mlx_key_hook(meta->win, key_hook, (void *) meta);
    mlx_hook(meta->win, 6, 1L << 6, julia_pos, meta);
	mlx_mouse_hook(meta->win, mouse_hook, (void *) meta);
	return (meta);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	int				i;

	i = -1;
	string1 = (unsigned char *) s1;
	string2 = (unsigned char *) s2;
	while (++i < (int) n && (string1[i] || string2[i]))
	{
		if (string1[i] > string2[i])
			return (1);
		else if (string1[i] < string2[i])
			return (-1);
	}
	return (0);
}
