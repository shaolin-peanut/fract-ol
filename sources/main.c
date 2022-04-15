/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:56:53 by sbars             #+#    #+#             */
/*   Updated: 2022/03/08 15:46:59 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
	{
		write(1, "Specify option:\n- mandelbrot\n- julia\n", 38);
		return (0);
	}
	vars = ft_calloc(sizeof(t_vars), 1);
	vars_init(vars);
	algo_selection(vars, argv[1]);
	mlx_loop(vars->mlx);
}
