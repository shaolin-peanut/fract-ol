/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:29 by sbars             #+#    #+#             */
/*   Updated: 2022/04/26 16:31:17 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define WW 1152
#define WH 648
#define ITERATION_MAX 70

// TEMPORARY          <------ REMOVE THIS | REMOVE THIS | REMOVE THIS
#include <stdio.h>
#include <stdlib.h>
// ALLOWED
#include "../libraries/mlx/mlx.h"
#include "../libraries/libft/libft.h"
#include <unistd.h>
#include <math.h>

typedef struct		s_cn
{
	double			r;
	double			i;
}					t_cn;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void *mlx;
	void *win;
	double	zoom;
	double	moveX;
	double	moveY;
	int		x;
	int		y;
	struct s_data *image;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int code, int x, int y, t_vars *vars);
int		plot_mandelbrot(t_vars *vars);
int		algo_selection(t_vars *vars, char	*param);
void	img_init(t_vars *vars, t_data *img, int	w, int h);
void	vars_init(t_vars *vars);

#endif
