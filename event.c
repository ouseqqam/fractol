/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:22:59 by ouseqqam          #+#    #+#             */
/*   Updated: 2020/01/02 15:59:11 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	maps(t_fract *fract, int x, int y)
{
	fract->m_x = ft_map_value(x, WIDTH, fract->x1, fract->x2);
	fract->m_y = ft_map_value(y, WIDTH, fract->y1, fract->y2);
}

void	image(t_fract *fract)
{
	mlx_clear_window(fract->mlx_ptr, fract->win);
	exec_fract(fract);
	mlx_put_image_to_window(fract->mlx_ptr,
			fract->win, fract->img.img_ptr, 0, 0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_fract *fract;

	fract = (t_fract *)param;
	if (button == 1 && fract->num == 2)
		fract->stop = 1;
	else if (button == 2 && fract->num == 2)
		fract->stop = 0;
	else if (button == 4)
	{
		maps(fract, x, y);
		zoom(fract, 1.1);
		image(fract);
	}
	else if (button == 5)
	{
		maps(fract, x, y);
		zoom(fract, 1 / 1.1);
		image(fract);
	}
	return (0);
}

int		key_press(int keycode, void *p)
{
	t_fract *fract;

	fract = (t_fract *)p;
	if (keycode == 53)
		exit(0);
	if (keycode == 8)
	{
		fract->color += 15;
		image(fract);
	}
	if (keycode == 1)
	{
		fract->signe = -1;
		image(fract);
	}
	if (keycode == 34)
	{
		fract->iter += 10;
		image(fract);
	}
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_fract *fract;

	fract = (t_fract *)param;
	if (fract->stop == 0)
	{
		fract->c_r = ft_map_value(x, WIDTH, fract->x1, fract->x2);
		fract->c_i = ft_map_value(y, HEIGHT, fract->y1, fract->y2);
		image(fract);
	}
	return (0);
}
