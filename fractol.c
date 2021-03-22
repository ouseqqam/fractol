/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:12:34 by ouseqqam          #+#    #+#             */
/*   Updated: 2020/01/02 16:17:44 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	mandelbort(t_fract *fract)
{
	fract->c_r = ft_map_value(fract->x, WIDTH, fract->x1, fract->x2);
	fract->c_i = ft_map_value(fract->y, HEIGHT, fract->y1, fract->y2);
	fract->z_r = 0;
	fract->z_i = 0;
	fract->i = 0;
	fract->tmp = fract->z_r;
	fract->z_r = fract->z_r * fract->z_r - fract->z_i * fract->z_i + fract->c_r;
	fract->z_i = 2 * fract->signe * fract->z_i * fract->tmp + fract->c_i;
	while (fract->z_r * fract->z_r + fract->z_i * fract->z_i < 4 &&
			fract->i < (ITER_MAX + fract->iter))
	{
		fract->tmp = fract->z_r;
		fract->z_r = fract->z_r * fract->z_r -
			fract->z_i * fract->z_i + fract->c_r;
		fract->z_i = 2 * fract->signe * fract->z_i * fract->tmp + fract->c_i;
		fract->i++;
	}
}

void	julia(t_fract *fract)
{
	fract->z_r = ft_map_value(fract->x, WIDTH, fract->x1, fract->x2);
	fract->z_i = ft_map_value(fract->y, HEIGHT, fract->y1, fract->y2);
	fract->i = 0;
	fract->tmp = fract->z_r;
	fract->z_r = fract->z_r * fract->z_r - fract->z_i * fract->z_i + fract->c_r;
	fract->z_i = 2 * fract->z_i * fract->tmp + fract->c_i;
	while (fract->z_r * fract->z_r + fract->z_i * fract->z_i < 4 &&
			fract->i < (ITER_MAX + fract->iter))
	{
		fract->tmp = fract->z_r;
		fract->z_r = fract->z_r * fract->z_r -
			fract->z_i * fract->z_i + fract->c_r;
		fract->z_i = 2 * fract->z_i * fract->tmp + fract->c_i;
		fract->i++;
	}
}

void	tricorn(t_fract *fract)
{
	fract->signe = -1;
	mandelbort(fract);
}

void	burning_ship(t_fract *fract)
{
	fract->c_r = ft_map_value(fract->x, WIDTH, fract->x1, fract->x2);
	fract->c_i = ft_map_value(fract->y, HEIGHT, fract->y1, fract->y2);
	fract->z_r = 0;
	fract->z_i = 0;
	fract->i = 0;
	fract->tmp = fract->z_r;
	fract->z_r = fabs(fract->z_r * fract->z_r -
			fract->z_i * fract->z_i + fract->c_r);
	fract->z_i = fabs(2 * fract->z_i * fract->tmp + fract->c_i);
	while (fract->z_r * fract->z_r + fract->z_i * fract->z_i < 4 &&
			fract->i < (ITER_MAX + fract->iter))
	{
		fract->tmp = fract->z_r;
		fract->z_r = fabs(fract->z_r * fract->z_r -
				fract->z_i * fract->z_i + fract->c_r);
		fract->z_i = fabs(2 * fract->z_i * fract->tmp + fract->c_i);
		fract->i++;
	}
}

void	multibort(t_fract *fract)
{
	fract->c_r = ft_map_value(fract->x, WIDTH, fract->x1, fract->x2);
	fract->c_i = ft_map_value(fract->y, HEIGHT, fract->y1, fract->y2);
	fract->z_r = 0;
	fract->z_i = 0;
	fract->i = 0;
	fract->tmp = fract->z_r;
	fract->z_r = fract->z_r * fract->z_r * fract->z_r -
		3 * fract->z_r * fract->z_i * fract->z_i + fract->c_r;
	fract->z_i = (3 * fract->z_i * fract->tmp * fract->tmp -
		fract->z_i * fract->z_i * fract->z_i) * fract->signe + fract->c_i;
	while (fract->z_r * fract->z_r + fract->z_i * fract->z_i < 4 &&
			fract->i < (ITER_MAX + fract->iter))
	{
		fract->tmp = fract->z_r;
		fract->z_r = fract->z_r * fract->z_r * fract->z_r -
			3 * fract->z_r * fract->z_i * fract->z_i + fract->c_r;
		fract->z_i = (3 * fract->z_i * fract->tmp * fract->tmp -
			fract->z_i * fract->z_i * fract->z_i) * fract->signe + fract->c_i;
		fract->i++;
	}
}
