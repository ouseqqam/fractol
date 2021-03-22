/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:33:45 by ouseqqam          #+#    #+#             */
/*   Updated: 2020/01/02 15:59:50 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	multicorn(t_fract *fract)
{
	fract->signe = -1;
	multibort(fract);
}

void	exec_fract_suite(t_fract *fract)
{
	if (fract->num == 1)
		mandelbort(fract);
	else if (fract->num == 2)
		julia(fract);
	else if (fract->num == 3)
		tricorn(fract);
	else if (fract->num == 4)
		burning_ship(fract);
	else if (fract->num == 5)
		multibort(fract);
	else if (fract->num == 6)
		multicorn(fract);
	if (fract->i == (ITER_MAX + fract->iter))
		fract->img.data[fract->y * WIDTH + fract->x] = 0;
	else
		fract->img.data[fract->y * WIDTH + fract->x] = color(fract);
}

void	exec_fract(t_fract *fract)
{
	fract->x = 0;
	while (fract->x < WIDTH)
	{
		fract->y = 0;
		while (fract->y < HEIGHT)
		{
			exec_fract_suite(fract);
			fract->y++;
		}
		fract->x++;
	}
	menu(fract);
}

int		color(t_fract *fract)
{
	return ((fract->i + 1) * 185534 * fract->color);
}
