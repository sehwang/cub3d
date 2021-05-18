/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:36:51 by inyang            #+#    #+#             */
/*   Updated: 2021/05/14 12:42:14 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close_program(void)
{
	printf("bye:)\n");
	exit(0);
	return (0);
}

void	draw(t_all *a)
{
	int x;
	int y;

	y = 0;
	while (y < a->base.height)
	{
		x = 0;
		while (x < a->base.width)
		{
			a->img.data[y * a->base.width + x] =
				a->info.buf[y][x];
			x++;
		}
		y++;
	}
	if (a->bmp.save == 0)
		mlx_put_image_to_window(a->info.mlx, a->info.win, a->img.img, 0, 0);
}

void	calc(t_all *a)
{
	int x;
	int y;

	x = -1;
	while (++x < a->base.width)
	{
		y = -1;
		while (++y < a->base.height)
		{
			a->info.buf[y][x] = ((a->base.f[0] * 256 * 256) +
				(a->base.f[1] * 256) + (a->base.f[2]));
			a->info.buf[a->base.height - y - 1][x] = ((a->base.c[0] * 256 * 256)
				+ (a->base.c[1] * 256) + (a->base.c[2]));
		}
	}
	x = -1;
	while (++x < a->base.width)
	{
		calc_1(a, x);
		calc_2(a);
		calc_3(a);
		calc_4(a, x);
		a->info.z_buffer[x] = a->calc.p_w_dist;
	}
	sprite_draw(a);
}

int		main_loop(t_all *a)
{
	calc(a);
	draw(a);
	return (0);
}

int		graphic_start(t_all *a)
{
	a->info.mlx = mlx_init();
	a->info.move_speed = 0.49;
	a->info.rot_speed = 0.49;
	texture_alloc(a);
	player_view(a);
	a->img.img = mlx_new_image(a->info.mlx, a->base.width, a->base.height);
	a->img.data = (int *)mlx_get_data_addr(a->img.img,
		&a->img.bpp, &a->img.size_l, &a->img.endian);
	if (a->bmp.save == 1)
	{
		calc(a);
		draw(a);
		bmp(a);
		return (0);
	}
	a->info.win = mlx_new_window(a->info.mlx,
		a->base.width, a->base.height, "mlx");
	mlx_loop_hook(a->info.mlx, &main_loop, a);
	mlx_hook(a->info.win, X_EVENT_KEY_PRESS, 0, &key_press, a);
	mlx_hook(a->info.win, X_EVENT_KEY_EXIT, 17, &ft_close_program, a);
	mlx_loop(a->info.mlx);
	return (0);
}
