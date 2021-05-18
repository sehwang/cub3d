/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:56:07 by inyang            #+#    #+#             */
/*   Updated: 2021/05/14 15:11:28 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	change_to_nine(t_all *a, int x, int y)
{
	a->map_dfs.map_dfs[x][y] = '9';
	if (((x - 1) >= 0) && a->map_dfs.map_dfs[x - 1][y] == '0')
		change_to_nine(a, x - 1, y);
	if (((x + 1) < a->map.x) && a->map_dfs.map_dfs[x + 1][y] == '0')
		change_to_nine(a, x + 1, y);
	if (((y - 1) >= 0) && a->map_dfs.map_dfs[x][y - 1] == '0')
		change_to_nine(a, x, y - 1);
	if (((y + 1) < a->map.y) && a->map_dfs.map_dfs[x][y + 1] == '0')
		change_to_nine(a, x, y + 1);
	return ;
}

void	dfs_in(t_all *a)
{
	int	x;
	int	y;

	x = -1;
	while (++x < a->map.x)
	{
		y = -1;
		while (++y < a->map.y)
		{
			if (a->map_dfs.map_dfs[x][y] == '9')
				change_to_nine(a, x, y);
		}
	}
	if ((a->pl.pos_x == 0 && a->pl.pos_y == 0) || a->pl.cnt == 0)
		print_error(11);
	if (a->map_dfs.map_dfs[(int)a->pl.pos_x][(int)a->pl.pos_y] == '9')
		print_error(7);
}

void	dfs_out_2(t_all *a)
{
	int	y;

	y = -1;
	while (++y < a->map.y)
	{
		if (a->map_dfs.map_dfs[0][y] != '1' && a->map_dfs.map_dfs[0][y] != '9')
			a->map_dfs.map_dfs[0][y] = '9';
	}
	y = -1;
	while (++y < a->map.y)
	{
		if (a->map_dfs.map_dfs[a->map.x - 1][y] != '1'
			&& a->map_dfs.map_dfs[a->map.x - 1][y] != '9')
			a->map_dfs.map_dfs[a->map.x - 1][y] = '9';
	}
}

void	dfs_out(t_all *a)
{
	int	x;

	x = -1;
	while (++x < a->map.x)
	{
		if (a->map_dfs.map_dfs[x][0] != '1' && a->map_dfs.map_dfs[x][0] != '9')
			a->map_dfs.map_dfs[x][0] = '9';
	}
	x = -1;
	while (++x < a->map.x)
	{
		if (a->map_dfs.map_dfs[x][a->map.y - 1] != '1'
			&& a->map_dfs.map_dfs[x][a->map.y - 1] != '9')
			a->map_dfs.map_dfs[x][a->map.y - 1] = '9';
	}
	dfs_out_2(a);
}

void	dfs_map(t_all *a)
{
	int	i;
	int	j;

	a->map_dfs.spr_x = ft_calloc(sizeof(double), a->sprite.cnt);
	a->map_dfs.spr_y = ft_calloc(sizeof(double), a->sprite.cnt);
	a->map_dfs.map_dfs = ft_calloc(sizeof(char *), a->map.x + 1);
	i = 0;
	while (i < a->map.x)
	{
		a->map_dfs.map_dfs[i] = ft_calloc(sizeof(char), a->map.y + 1);
		i++;
	}
	i = -1;
	while (++i < a->map.x)
	{
		j = -1;
		while (++j < (int)ft_strlen(a->map.map[i]))
			dfs_map_make(a, i, j);
		if ((int)ft_strlen(a->map.map[i]) < a->map.y)
			while ((a->map.y) - j)
				a->map_dfs.map_dfs[i][j++] = '9';
		a->map_dfs.map_dfs[i][j] = '\0';
	}
	dfs_out(a);
	dfs_in(a);
}
