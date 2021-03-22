/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:07:16 by ouseqqam          #+#    #+#             */
/*   Updated: 2020/01/02 15:53:35 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1000
# define HEIGHT 1000
# define ITER_MAX 90
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef	struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef	struct	s_fract
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			image_x;
	int			image_y;
	int			x;
	int			y;
	int			i;
	int			signe;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	double		m_x;
	double		m_y;
	int			stop;
	int			num;
	int			color;
	int			iter;
}				t_fract;

int				ft_strcmp(char *s1, char *s2);
void			ft_putendl(char const *s);
int				key_press(int keycode, void *p);
void			mandelbort(t_fract *fract);
int				mouse_move(int x, int y, void *param);
void			julia(t_fract *fract);
void			tricorn(t_fract *fract);
void			multibort(t_fract *fract);
void			burning_ship(t_fract *fract);
void			exec_fract(t_fract *fract);
double			ft_map_value(double value, double max,
				double start, double end);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
void			zoom(t_fract *e, double zoomfactor);
int				color(t_fract *fract);
void			menu(t_fract *b);

#endif
