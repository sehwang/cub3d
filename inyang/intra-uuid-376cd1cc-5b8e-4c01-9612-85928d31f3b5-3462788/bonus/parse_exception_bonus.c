/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exception_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 03:24:20 by inyang            #+#    #+#             */
/*   Updated: 2021/05/14 15:11:49 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	after_map(t_all *a)
{
	dfs_map(a);
	ft_map_to_int(a);
	parse_check(a);
	graphic_start(a);
}

void	resolution_size(t_all *a)
{
	int		sizex;
	int		sizey;

	mlx_get_screen_size(a->info.mlx, &sizex, &sizey);
	if (a->base.width > sizex)
		a->base.width = sizex;
	if (a->base.height > sizey)
		a->base.height = sizey;
	if (a->base.width < 200)
		a->base.width = 200;
	if (a->base.height < 200)
		a->base.height = 200;
}
