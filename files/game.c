/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:52:00 by sehwang           #+#    #+#             */
/*   Updated: 2021/05/18 15:15:50 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_keyintput(int key_code, t_game *game)//변경 필요
{
	if (key_code == KEY_W)
		game->player.y += 1;
	else if (key_code == KEY_S)
		game->player.y -= 1;
	else if (key_code == KEY_A)
		game->player.x -= 1;
	else if (key_code == KEY_D)
		game->player.x += 1;
	else if (key_code == LEFT)
		game->player.dir += 0.1;
	else if (key_code == RIGHT)
		game->player.x -= 0.1;
	else if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

int		ft_rendering(t_game *game)
{
	ft_raycast(game);
	ft_print_error(game);
	printf("rendering works\n\n");
	return (0);
}

int		ft_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win.ptr = mlx_new_window(game->mlx, game->win.x, game->win.y, "cub3D");

	img_init(game);
	mlx_loop_hook(game->mlx, &ft_rendering, game);//rendering
	mlx_hook(game->win.ptr, X_EVENT_KEY_PRESS, 0, &ft_keyintput, game);
	//printf("player x: %.2f, y: %.2f\n", game->player.x, game->player.y);
	ft_print_error(game);
	mlx_loop(game->mlx);

	return (1);
}
