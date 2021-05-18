/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:23:28 by inyang            #+#    #+#             */
/*   Updated: 2021/05/14 15:11:37 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_double_array(char **map, int cnt)
{
	int i;

	i = 0;
	if (map[i])
	{
		while (i < cnt)
		{
			free(map[i]);
			i++;
		}
	}
	free(map);
	map = 0;
}
