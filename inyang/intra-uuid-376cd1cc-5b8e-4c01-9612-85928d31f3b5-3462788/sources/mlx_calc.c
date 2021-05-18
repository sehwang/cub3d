/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:06:10 by inyang            #+#    #+#             */
/*   Updated: 2021/05/09 21:06:32 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_4(t_all *a, int x)
{
	int	y;

	y = a->calc.draw_start;
	a->calc.step = 1.0 * TEXHEIGHT / a->calc.line_h;
	a->calc.tex_pos = (a->calc.draw_start - a->base.height
		/ 2.0 + a->calc.line_h / 2.0) * a->calc.step;
	while (y < a->calc.draw_end)
	{
		a->calc.tex_y = (int)a->calc.tex_pos & (TEXHEIGHT - 1);
		a->calc.tex_pos += a->calc.step;
		texture_nsew(a);
		if (a->calc.side == 1)
			a->calc.color = (a->calc.color >> 1) & 8355711;
		a->info.buf[y][x] = a->calc.color;
		y++;
	}
}

void	calc_3(t_all *a)
{
	a->calc.line_h = (int)(a->base.height / a->calc.p_w_dist);
	a->calc.draw_start = -a->calc.line_h / 2 + a->base.height / 2;
	if (a->calc.draw_start < 0)
		a->calc.draw_start = 0;
	a->calc.draw_end = a->calc.line_h / 2 + a->base.height / 2;
	if (a->calc.draw_end >= a->base.height)
		a->calc.draw_end = a->base.height - 1;
	a->calc.tex_num = a->map.map[a->calc.map_x][a->calc.map_y] - 1;
	if (a->calc.side == 0)
		a->calc.wall_x = a->pl.pos_y + a->calc.p_w_dist * a->calc.raydir_y;
	else
		a->calc.wall_x = a->pl.pos_x + a->calc.p_w_dist * a->calc.raydir_x;
	a->calc.wall_x -= floor(a->calc.wall_x);
	a->calc.tex_x = (int)(a->calc.wall_x * (double)TEXWIDTH);
	if (a->calc.side == 0 && a->calc.raydir_x > 0)
		a->calc.tex_x = TEXWIDTH - a->calc.tex_x - 1;
	if (a->calc.side == 1 && a->calc.raydir_y < 0)
		a->calc.tex_x = TEXWIDTH - a->calc.tex_x - 1;
}

void	calc_2(t_all *a)
{
	a->calc.hit = 0;
	while (a->calc.hit == 0)
	{
		if (a->calc.side_dist_x < a->calc.side_dist_y)
		{
			a->calc.side_dist_x += a->calc.d_dist_x;
			a->calc.map_x += a->calc.step_x;
			a->calc.side = 0;
		}
		else
		{
			a->calc.side_dist_y += a->calc.d_dist_y;
			a->calc.map_y += a->calc.step_y;
			a->calc.side = 1;
		}
		if (a->map.map[a->calc.map_x][a->calc.map_y] == '1')
			a->calc.hit = 1;
	}
	if (a->calc.side == 0)
		a->calc.p_w_dist = (a->calc.map_x - a->pl.pos_x +
			(1 - a->calc.step_x) / 2) / a->calc.raydir_x;
	else
		a->calc.p_w_dist = (a->calc.map_y - a->pl.pos_y +
			(1 - a->calc.step_y) / 2) / a->calc.raydir_y;
}

void	calc_1_1(t_all *a)
{
	if (a->calc.raydir_x < 0)
	{
		a->calc.step_x = -1;
		a->calc.side_dist_x = (a->pl.pos_x - a->calc.map_x) * a->calc.d_dist_x;
	}
	else
	{
		a->calc.step_x = 1;
		a->calc.side_dist_x =
			(a->calc.map_x + 1.0 - a->pl.pos_x) * a->calc.d_dist_x;
	}
	if (a->calc.raydir_y < 0)
	{
		a->calc.step_y = -1;
		a->calc.side_dist_y = (a->pl.pos_y - a->calc.map_y) * a->calc.d_dist_y;
	}
	else
	{
		a->calc.step_y = 1;
		a->calc.side_dist_y =
			(a->calc.map_y + 1.0 - a->pl.pos_y) * a->calc.d_dist_y;
	}
}

void	calc_1(t_all *a, int x)
{
	a->calc.cam_x = 2.0 * x / (double)a->base.width - 1.0;
	a->calc.raydir_x = a->info.dir_x + a->info.plane_x * a->calc.cam_x;
	a->calc.raydir_y = a->info.dir_y + a->info.plane_y * a->calc.cam_x;
	a->calc.map_x = (int)a->pl.pos_x;
	a->calc.map_y = (int)a->pl.pos_y;
	a->calc.d_dist_x = fabs(1 / a->calc.raydir_x);
	a->calc.d_dist_y = fabs(1 / a->calc.raydir_y);
	calc_1_1(a);
}
