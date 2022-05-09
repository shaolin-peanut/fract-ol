/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:29 by sbars             #+#    #+#             */
/*   Updated: 2022/05/09 19:13:43 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define WW 720
#define WH 720
#define ITERATION_MAX 80

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

typedef	struct s_comp {
	double	zoom;
	double	remin;
	double	remax;
	double	imin;
	double	imax;
	double	moveX;
	double	moveY;
	double	zre;
	double	zim;
}	t_comp;

typedef struct s_meta {
	void *mlx;
	void *win;
	struct s_data *image;
	struct s_comp *comp;
	int	type;
}	t_meta;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_meta *meta);
int		mouse_hook(int code, int x, int y, t_meta	*meta);
int		plot(t_meta	*meta);
int		algo_selection(t_meta	*meta, char	*param);
void	img_init(t_meta	*meta, t_data *img, int	w, int h);
t_meta	*meta_init(int	type);
int		mandelbrot(int x, int y, t_meta	*meta);
void		set_complex_plane(t_meta	*meta);

#endif
