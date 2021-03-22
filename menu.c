/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:56:08 by ouseqqam          #+#    #+#             */
/*   Updated: 2020/01/02 16:10:35 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(t_fract *b)
{
	mlx_string_put(b->mlx_ptr, b->win, WIDTH, 50, 255, "        main menu");
	mlx_string_put(b->mlx_ptr, b->win, WIDTH, 70, 255,
			"  -----------------------------");
	mlx_string_put(b->mlx_ptr, b->win, WIDTH, 100, 255, " C = COLORATION");
	mlx_string_put(b->mlx_ptr, b->win, WIDTH, 120, 255, " ZOOM_OUT = MOVE UP");
	mlx_string_put(b->mlx_ptr, b->win, WIDTH, 160, 255, " ZOOM_IN = MOVE DOWN");
	mlx_string_put(b->mlx_ptr, b->win, WIDTH, 180, 255,
			" LEFT CLICK = STOP MOVEMENT");
	mlx_string_put(b->mlx_ptr, b->win, WIDTH, 200, 255
			, " RIGHT CLICK = RETURN MOUVEMENT");
	mlx_string_put(b->mlx_ptr, b->win, WIDTH, 220, 255, " I = ITERATION");
}
