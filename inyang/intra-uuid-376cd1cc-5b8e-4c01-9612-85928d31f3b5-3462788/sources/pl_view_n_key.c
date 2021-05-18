/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_view_n_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:36:51 by inyang            #+#    #+#             */
/*   Updated: 2021/05/09 21:27:11 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_press_rl(int key, t_all *a)
{
	double	old_dir_x;
	double	old_plane_x;

	if (key == K_AR_R)
	{
		old_dir_x = a->info.dir_x;
		old_plane_x = a->info.plane_x;
		key_rl_cal(1, old_dir_x, old_plane_x, a);
		key_rl_cal(2, old_dir_x, old_plane_x, a);
	}
	if (key == K_AR_L)
	{
		old_dir_x = a->info.dir_x;
		old_plane_x = a->info.plane_x;
		key_rl_cal_2(3, old_dir_x, old_plane_x, a);
		key_rl_cal_2(4, old_dir_x, old_plane_x, a);
	}
}

void	key_press_ad(int key, t_all *a)
{
	if (key == K_A)
	{
		if (a->map.map_int[(int)(a->pl.pos_x - a->info.vec_y)]
			[(int)(a->pl.pos_y)] == 0)
			a->pl.pos_x -= a->info.vec_y;
		if (a->map.map_int[(int)(a->pl.pos_x)]
			[(int)(a->pl.pos_y + a->info.vec_x)] == 0)
			a->pl.pos_y += a->info.vec_x;
	}
	if (key == K_D)
	{
		if (a->map.map_int[(int)(a->pl.pos_x + a->info.vec_y)]
			[(int)(a->pl.pos_y)] == 0)
			a->pl.pos_x += a->info.vec_y;
		if (a->map.map_int[(int)(a->pl.pos_x)]
			[(int)(a->pl.pos_y - a->info.vec_x)] == 0)
			a->pl.pos_y -= a->info.vec_x;
	}
}

int		key_press(int key, t_all *a)
{
	a->info.vec_x = a->info.dir_x * a->info.move_speed;
	a->info.vec_y = a->info.dir_y * a->info.move_speed;
	if (key == K_W)
	{
		if (a->map.map_int[(int)(a->pl.pos_x + a->info.vec_x)]
			[(int)(a->pl.pos_y)] == 0)
			a->pl.pos_x += a->info.vec_x;
		if (a->map.map_int[(int)(a->pl.pos_x)]
			[(int)(a->pl.pos_y + a->info.vec_y)] == 0)
			a->pl.pos_y += a->info.vec_y;
	}
	if (key == K_S)
	{
		if (a->map.map_int[(int)(a->pl.pos_x - a->info.vec_x)]
			[(int)(a->pl.pos_y)] == 0)
			a->pl.pos_x -= a->info.vec_x;
		if (a->map.map_int[(int)(a->pl.pos_x)]
			[(int)(a->pl.pos_y - a->info.vec_y)] == 0)
			a->pl.pos_y -= a->info.vec_y;
	}
	key_press_ad(key, a);
	key_press_rl(key, a);
	if (key == K_ESC)
		ft_close_program();
	return (0);
}

void	player_view_ew(t_all *a)
{
	if (a->pl.view == 'E')
	{
		a->info.dir_x = 0.0;
		a->info.dir_y = 1.0;
		a->info.plane_x = 0.66;
		a->info.plane_y = 0.0;
	}
	else if (a->pl.view == 'W')
	{
		a->info.dir_x = 0.0;
		a->info.dir_y = -1.0;
		a->info.plane_x = -0.66;
		a->info.plane_y = 0.0;
	}
}

void	player_view(t_all *a)
{
	if (a->pl.view == 'E' || a->pl.view == 'W')
		player_view_ew(a);
	else if (a->pl.view == 'N' || a->pl.view == 'S')
	{
		if (a->pl.view == 'N')
		{
			a->info.dir_x = -1.0;
			a->info.dir_y = 0.0;
			a->info.plane_x = 0.0;
			a->info.plane_y = 0.66;
		}
		else if (a->pl.view == 'S')
		{
			a->info.dir_x = 1.0;
			a->info.dir_y = 0.0;
			a->info.plane_x = 0.0;
			a->info.plane_y = -0.66;
		}
	}
}
