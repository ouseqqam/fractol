/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:42:46 by ouseqqam          #+#    #+#             */
/*   Updated: 2020/01/01 16:22:07 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	zoom(t_fract *fract, double zoomfactor)
{
	double interpolation;

	interpolation = 1.0 / zoomfactor;
	fract->x1 = interpolate(fract->m_x, fract->x1, interpolation);
	fract->y1 = interpolate(fract->m_y, fract->y1, interpolation);
	fract->x2 = interpolate(fract->m_x, fract->x2, interpolation);
	fract->y2 = interpolate(fract->m_y, fract->y2, interpolation);
}
