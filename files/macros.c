/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:33:15 by sehwang           #+#    #+#             */
/*   Updated: 2021/05/18 10:52:41 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	rad2deg(double th)
{
	return (th * 180 / PI);
}

double	deg2rad(double th)
{
	return (th / 180 * PI);
}

int 	is_zero(double d)
{
	return (fabs(d) < 1e-06 ? 1 : 0);
}

int		sgn(double d)
{
	return is_zero(d) ? 0 : ((d > 0) ? 1 : -1);
}

char		map_get_cell(int x, int y, t_game *game)
{
	return (x >= 0 && x < game->map.r && y >= 0 && y < game->map.c) ? game->map.tap[x][y] : -1;
}

double		l2dist(double x1, double y1, double x2, double y2)
{
	double	dx;
	double	dy;

	dx = x1 - x2;
	dy = y1 - y2;
	return (sqrt((dx * dx) + (dy * dy)));
}
