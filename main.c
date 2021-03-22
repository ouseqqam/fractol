/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:28:21 by ouseqqam          #+#    #+#             */
/*   Updated: 2020/01/02 15:54:04 by ouseqqam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_map_value(double value, double max, double start, double end)
{
	double ratio;

	ratio = (end - start) / max;
	return (start + value * ratio);
}

void	mlx_func(t_fract *fract)
{
	fract->mlx_ptr = mlx_init();
	fract->win = mlx_new_window(fract->mlx_ptr, WIDTH + 500, HEIGHT, "fractol");
	fract->img.img_ptr = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);
	fract->img.data = (int*)mlx_get_data_addr(fract->img.img_ptr,
			&fract->img.bpp, &fract->img.size_l, &fract->img.endian);
	exec_fract(fract);
	mlx_put_image_to_window(fract->mlx_ptr,
			fract->win, fract->img.img_ptr, 0, 0);
	mlx_hook(fract->win, 2, 0, key_press, (void*)fract);
	mlx_hook(fract->win, 4, 0, mouse_press, (void*)fract);
	if (fract->num == 2)
		mlx_hook(fract->win, 6, 0, mouse_move, (void*)fract);
	mlx_loop(fract->mlx_ptr);
}

void	initialisation(t_fract *fract)
{
	fract->x1 = -2;
	fract->x2 = 2;
	fract->y1 = -2;
	fract->y2 = 2;
	fract->m_x = 0;
	fract->m_y = 0;
	fract->stop = 0;
	fract->num = 0;
	fract->color = 1;
	fract->signe = 1;
	fract->iter = 0;
}

int		main(int ac, char **av)
{
	t_fract fract;

	initialisation(&fract);
	if (ac <= 1)
	{
		ft_putendl("./fractol mandelbort julia tricorn");
		ft_putendl(" Burning_Ship multibort multicorn");
		return (0);
	}
	if (ft_strcmp(av[1], "mandelbort"))
		fract.num = 1;
	else if (ft_strcmp(av[1], "julia"))
		fract.num = 2;
	else if (ft_strcmp(av[1], "tricorn"))
		fract.num = 3;
	else if (ft_strcmp(av[1], "Burning_Ship"))
		fract.num = 4;
	else if (ft_strcmp(av[1], "multibort"))
		fract.num = 5;
	else if (ft_strcmp(av[1], "multicorn"))
		fract.num = 6;
	else
		return (0);
	mlx_func(&fract);
}
