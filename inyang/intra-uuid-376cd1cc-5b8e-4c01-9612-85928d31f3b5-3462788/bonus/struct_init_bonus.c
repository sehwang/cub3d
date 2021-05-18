/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:32:48 by inyang            #+#    #+#             */
/*   Updated: 2021/05/14 15:12:12 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	base_reset(char *src, t_all *a)
{
	a->i = 0;
	a->map.x = -1;
	a->map.y = 0;
	a->base.cnt = 0;
	a->base.width = 0;
	a->base.height = 0;
	a->base.no = NULL;
	a->base.so = NULL;
	a->base.we = NULL;
	a->base.ea = NULL;
	a->base.s = NULL;
	a->pl.cnt = 0;
	a->pl.pos_x = 0;
	a->pl.pos_y = 0;
	a->calc.hit = 0;
	a->calc.raydir_x = 0;
	a->calc.raydir_y = 0;
	a->calc.side = 0;
	a->txtr.par_cnt = 0;
	a->sprite.xy_cnt = 0;
	a->sprite.cnt = 0;
	a->map.map = NULL;
	read_cub_src(a, src);
}
