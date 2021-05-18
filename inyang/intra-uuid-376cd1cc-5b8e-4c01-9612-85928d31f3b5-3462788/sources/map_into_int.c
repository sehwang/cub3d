/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_into_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 03:00:21 by inyang            #+#    #+#             */
/*   Updated: 2021/05/09 01:42:20 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_player_view(t_all *a, int i, int j)
{
	if (a->map.map[i][j] == 'N')
		a->pl.view = 'N';
	else if (a->map.map[i][j] == 'S')
		a->pl.view = 'S';
	else if (a->map.map[i][j] == 'E')
		a->pl.view = 'E';
	else if (a->map.map[i][j] == 'W')
		a->pl.view = 'W';
}

void	ft_map_to_int_2(t_all *a)
{
	int i;
	int j;

	i = -1;
	while (++i < a->map.x)
	{
		j = -1;
		while (++j < a->map.y)
		{
			if (a->map.map[i][j] == 'N' || a->map.map[i][j] == 'E' ||
				a->map.map[i][j] == 'S' || a->map.map[i][j] == 'W')
			{
				ft_player_view(a, i, j);
				a->map.map_int[i][j] = 0;
			}
			if (a->map.map[i][j] != '0' && a->map.map[i][j] != '1')
				a->map.map_int[i][j] = 0;
			else
				a->map.map_int[i][j] = a->map.map[i][j] - 48;
		}
	}
}

void	ft_map_to_int(t_all *a)
{
	int i;

	a->map.map_int = (int **)ft_calloc(sizeof(int *), a->map.x);
	if (!a->map.map_int)
		exit(0);
	i = -1;
	while (++i < a->map.x)
	{
		a->map.map_int[i] = (int *)ft_calloc(sizeof(int), a->map.y);
		if (!a->map.map_int[i])
		{
			free(a->map.map_int[i]);
			exit(0);
		}
	}
	ft_map_to_int_2(a);
}
