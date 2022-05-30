/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:45:57 by sbars             #+#    #+#             */
/*   Updated: 2022/05/10 11:47:48 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_meta *meta)
{
	if (keycode == 53)
	{
		mlx_destroy_window(meta->mlx, meta->win);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int	code, int	x, int	y, t_meta *meta)
{
	double	zm;

	zm = meta->comp->zoom_w;
	(void) x;
	(void) y;
	if (code == 5)
	{
		meta->comp->zoom_w += 0.2;
	}
	else if (code == 4 && zm > 5.0)
	{
		meta->comp->zoom_w -= 0.2;
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
