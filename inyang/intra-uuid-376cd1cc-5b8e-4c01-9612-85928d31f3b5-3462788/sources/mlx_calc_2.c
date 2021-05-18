/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_calc_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 21:03:08 by inyang            #+#    #+#             */
/*   Updated: 2021/05/09 21:24:55 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_rl_cal_2(int i, double old_dir_x, double old_plane_x, t_all *a)
{
	if (i == 3)
	{
		a->info.dir_x = a->info.dir_x * cos(a->info.rot_speed)
			- a->info.dir_y * sin(a->info.rot_speed);
		a->info.dir_y = old_dir_x * sin(a->info.rot_speed)
			+ a->info.dir_y * cos(a->info.rot_speed);
	}
	if (i == 4)
	{
		a->info.plane_x = a->info.plane_x * cos(a->info.rot_speed)
			- a->info.plane_y * sin(a->info.rot_speed);
		a->info.plane_y = old_plane_x * sin(a->info.rot_speed)
			+ a->info.plane_y * cos(a->info.rot_speed);
	}
}

void	key_rl_cal(int i, double old_dir_x, double old_plane_x, t_all *a)
{
	if (i == 1)
	{
		a->info.dir_x = a->info.dir_x * cos(-a->info.rot_speed)
			- a->info.dir_y * sin(-a->info.rot_speed);
		a->info.dir_y = old_dir_x * sin(-a->info.rot_speed)
			+ a->info.dir_y * cos(-a->info.rot_speed);
	}
	if (i == 2)
	{
		a->info.plane_x = a->info.plane_x * cos(-a->info.rot_speed)
			- a->info.plane_y * sin(-a->info.rot_speed);
		a->info.plane_y = old_plane_x * sin(-a->info.rot_speed)
			+ a->info.plane_y * cos(-a->info.rot_speed);
	}
}

void	texture_nsew(t_all *a)
{
	if (a->calc.side == 0 && a->calc.raydir_x < 0)
		a->calc.color = a->info.texture[0]
			[TEXHEIGHT * a->calc.tex_y + a->calc.tex_x];
	else if (a->calc.side == 0 && a->calc.raydir_x > 0)
		a->calc.color = a->info.texture[1]
			[TEXHEIGHT * a->calc.tex_y + a->calc.tex_x];
	else if (a->calc.side == 1 && a->calc.raydir_y > 0)
		a->calc.color = a->info.texture[2]
			[TEXHEIGHT * a->calc.tex_y + a->calc.tex_x];
	else if (a->calc.side == 1 && a->calc.raydir_y < 0)
		a->calc.color = a->info.texture[3]
			[TEXHEIGHT * a->calc.tex_y + a->calc.tex_x];
}
