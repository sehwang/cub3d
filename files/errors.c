/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:59:37 by sehwang           #+#    #+#             */
/*   Updated: 2021/05/18 11:49:25 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_error(t_game *game)
{
	if (game->error == -1)
		printf("OK\n");
	else
	{
		if (game->error == 0)
			printf("arg_error\n");
		else if (game->error == 1)
			printf("cub input error\n");
		else if (game->error == 2)
			printf("map error\n");
		else if (game->error == 3)
			printf("00\n");
		else if (game->error == 4)
			printf("00\n");
		else if (game->error == 5)
			printf("00\n");
		else if (game->error == 6)
			printf("00\n");
		else if (game->error == 7)
			printf("00\n");
		else if (game->error == 8)
			printf("00\n");
		else if (game->error == 9)
			printf("00\n");
		exit(0);
	}
}
