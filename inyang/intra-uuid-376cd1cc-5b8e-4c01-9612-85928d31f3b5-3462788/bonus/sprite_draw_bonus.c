/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:10:15 by inyang            #+#    #+#             */
/*   Updated: 2021/05/14 15:12:06 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	stripe_draw(t_all *a)
{
	int	stripe;
	int	tex_x;
	int	tex_y;
	int	y;
	int	d;

	stripe = a->sprite.draw_s_x;
	while (stripe < a->sprite.draw_f_x)
	{
		tex_x = (int)((256 * (stripe - (-a->sprite.spr_w / 2 +
			a->sprite.screen_x)) * TEXWIDTH / a->sprite.spr_w) / 256);
		if (a->sprite.trans_y > 0 && stripe > 0 && stripe < a->base.width
			&& a->sprite.trans_y < a->info.z_buffer[stripe])
			y = a->sprite.draw_s_y;
		while (y < a->sprite.draw_f_y)
		{
			d = (y) * 256 - a->base.height * 128 + a->sprite.spr_h * 128;
			tex_y = ((d * TEXHEIGHT) / a->sprite.spr_h) / 256;
			a->sprite.color = a->info.texture[4][TEXWIDTH * tex_y + tex_x];
			if ((a->sprite.color & 0x00FFFFFF) != 0)
				a->info.buf[y][stripe] = a->sprite.color;
			y++;
		}
		stripe++;
	}
}

void	sprite_size(t_all *a)
{
	a->sprite.screen_x = (int)((a->base.width / 2)
		* (1 + a->sprite.trans_x / a->sprite.trans_y));
	a->sprite.spr_h = abs((int)(a->base.height / a->sprite.trans_y));
	a->sprite.draw_s_y = -a->sprite.spr_h / 2 + a->base.height / 2;
	if (a->sprite.draw_s_y < 0)
		a->sprite.draw_s_y = 0;
	a->sprite.draw_f_y = a->sprite.spr_h / 2 + a->base.height / 2;
	if (a->sprite.draw_f_y >= a->base.height)
		a->sprite.draw_f_y = a->base.height - 1;
	a->sprite.spr_w = abs((int)(a->base.height / a->sprite.trans_y));
	a->sprite.draw_s_x = -a->sprite.spr_w / 2 + a->sprite.screen_x;
	if (a->sprite.draw_s_x < 0)
		a->sprite.draw_s_x = 0;
	a->sprite.draw_f_x = a->sprite.spr_w / 2 + a->sprite.screen_x;
	if (a->sprite.draw_f_x >= a->base.width)
		a->sprite.draw_f_x = a->base.width - 1;
}

void	sprite_pos(t_all *a, int i, int *sprite_order)
{
	double	spr_x;
	double	spr_y;
	double	inv_det;

	spr_x = a->map_dfs.spr_x[sprite_order[i]] - a->pl.pos_x;
	spr_y = a->map_dfs.spr_y[sprite_order[i]] - a->pl.pos_y;
	inv_det = 1.0 /
		(a->info.plane_x * a->info.dir_y - a->info.dir_x * a->info.plane_y);
	a->sprite.trans_x =
		inv_det * (a->info.dir_y * spr_x - a->info.dir_x * spr_y);
	a->sprite.trans_y =
		inv_det * (-a->info.plane_y * spr_x + a->info.plane_x * spr_y);
}

void	sprite_draw(t_all *a)
{
	int		sprite_order[a->sprite.cnt];
	double	sprite_dist[a->sprite.cnt];
	int		i;

	i = -1;
	while (++i < a->sprite.cnt)
	{
		sprite_order[i] = i;
		sprite_dist[i] = ((a->pl.pos_x - a->map_dfs.spr_x[i])
			* (a->pl.pos_x - a->map_dfs.spr_x[i])
			+ (a->pl.pos_y - a->map_dfs.spr_y[i])
			* (a->pl.pos_y - a->map_dfs.spr_y[i]));
	}
	sort_sprites(sprite_order, sprite_dist, a->sprite.cnt);
	i = -1;
	while (++i < a->sprite.cnt)
	{
		sprite_pos(a, i, sprite_order);
		sprite_size(a);
		stripe_draw(a);
	}
}
