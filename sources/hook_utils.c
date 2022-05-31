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
	if (keycode == 53 || keycode == 65307)
	{
        mlx_destroy_image(meta->mlx, meta->img.img);
		mlx_destroy_window(meta->mlx, meta->win);
        exit(0);
	}
	return (0);
}

int	mouse_hook(int	code, int	x, int	y, t_meta *meta)
{
	if (code == 4)
	{
        zoom(meta, x, y, 1);
        plot(meta);
	}
	else if (code == 5)
	{
        zoom(meta, x, y, -1);
        plot(meta);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
