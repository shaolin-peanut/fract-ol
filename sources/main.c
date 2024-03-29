/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:56:53 by sbars             #+#    #+#             */
/*   Updated: 2022/05/10 12:21:19 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	t_meta	*parse_args(int argc, char	**argv, t_meta	*meta)
{
	if (argc != 2)
	{
		write(1, "Options:\n- mandelbrot\n- julia\n", 31);
		exit (EXIT_FAILURE);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
	{
		meta = meta_init(0);
	}
	else if (!ft_strncmp(argv[1], "julia", 6))
	{
		meta = meta_init(1);
	}
	else
	{
		write(1, "Options:\n- mandelbrot\n- julia\n", 31);
		exit(EXIT_SUCCESS);
	}
	return (meta);
}

int	main(int argc, char **argv)
{
	t_meta	*meta;

	meta = NULL;
	meta = parse_args(argc, argv, meta);
	if ((set_complex_plane(meta, 2.0, -2.0) == 1))
	{
		plot(meta);
		mlx_loop(meta->mlx);
	}
}
