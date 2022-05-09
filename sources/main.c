/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:56:53 by sbars             #+#    #+#             */
/*   Updated: 2022/05/09 19:13:27 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_meta	*meta;

	if (argc != 2)
	{
		write(1, "Specify option:\n- mandelbrot\n- julia\n", 38);
		return (0);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
	{
		meta = meta_init(0);
		//mandelbrot_set(fract);
		//start_hooks(fract);
	}
	else if (!ft_strncmp(argv[1], "julia", 6))
	{
		meta = meta_init(1);
		//julia_set(fract);
		//start_hooks(fract);
	}
	else
		return (1);
	set_complex_plane(meta);
	plot(meta);
	mlx_loop(meta->mlx);
}
