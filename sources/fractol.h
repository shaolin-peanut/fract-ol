/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:29 by sbars             #+#    #+#             */
/*   Updated: 2022/05/10 12:49:51 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WW 500.0
# define WH 500.0
# define RED 12
# define GREEN 8
# define BLUE 6
# define ITERATION_MAX 70
// ALLOWED
# include "../mlx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_cn
{
	double	r;
	double	i;
}	t_cn;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_comp {
	double	zoom_w;
	double	zoom_h;
	double	remin;
	double	remax;
	double	rerange;
	double	recenter;
	double	imin;
	double	imax;
	double	imrange;
	double	imcenter;
	double	cre;
	double	cim;
	double	itermax;
}	t_comp;

typedef struct s_meta {
	void			*mlx;
	void			*win;
	struct s_data	*image;
	struct s_comp	*comp;
	t_data			img;
	int				type;
	int				julia_static;
}	t_meta;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_meta *meta);
int		mouse_hook(int code, int x, int y, t_meta	*meta);
int		julia_pos(int x, int y, t_meta *meta);
int		plot(t_meta	*meta);
int		algo_selection(t_meta	*meta, char	*param);
t_data	img_init(void *mlx, int w, int h);
t_meta	*meta_init(int type);
int		set_complex_plane(t_meta	*meta, double max, double min);
t_cn	init_complex(t_cn complex);
void	zoom(t_meta *meta, int x, int y, int sign);

#endif
