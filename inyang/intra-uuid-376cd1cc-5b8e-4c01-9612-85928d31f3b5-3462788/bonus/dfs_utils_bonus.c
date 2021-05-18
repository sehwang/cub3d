/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 00:27:12 by inyang            #+#    #+#             */
/*   Updated: 2021/05/14 15:11:31 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	dfs_map_make(t_all *a, int i, int j)
{
	if (ft_isspace(&a->map.map[i][j]) == 3)
		a->map_dfs.map_dfs[i][j] = '9';
	else if (a->map.map[i][j] == 'N' || a->map.map[i][j] == 'S' ||
		a->map.map[i][j] == 'E' || a->map.map[i][j] == 'W')
	{
		a->pl.cnt += 1;
		a->pl.pos_x = (double)i + 0.5;
		a->pl.pos_y = (double)j + 0.5;
		a->map_dfs.map_dfs[i][j] = '0';
	}
	else if (a->map.map[i][j] == '2')
	{
		a->map_dfs.spr_x[a->sprite.xy_cnt] = (double)i + 0.5;
		a->map_dfs.spr_y[a->sprite.xy_cnt] = (double)j + 0.5;
		a->map_dfs.map_dfs[i][j] = '0';
		a->sprite.xy_cnt++;
	}
	else
		a->map_dfs.map_dfs[i][j] = a->map.map[i][j];
}

int		map_yoso_check(char *a)
{
	if (*a != '0' && *a != '1' && *a != '2' && *a != 'N' && *a != 'S'
		&& *a != 'E' && *a != 'W' && *a != ' ')
		print_error(10);
	return (5);
}
