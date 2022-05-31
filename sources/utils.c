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
	meta->comp->cre = 0.0;
	meta->comp->cim = 0.0;
    meta->comp->itermax = ITERATION_MAX;
	meta->type = type;
    meta->img = img_init(meta->mlx, (int) WW, (int) WH);
	mlx_key_hook(meta->win, key_hook, (void *) meta);
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
