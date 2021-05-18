/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:02:20 by sehwang           #+#    #+#             */
/*   Updated: 2021/04/30 11:38:35 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_game *game)
{
 	game->mlx = mlx_init();
 	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "tester");
	game->user.cor[0] = 0;
	game->user.cor[1] = 0;
	int map[ROWS][COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, map, sizeof(int) * ROWS * COLS);
}

void	img_init(t_game *game)
{
	game->img.ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.ptr, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

int		main_loop(t_game *game)
{
	draw_rectangles(game);
	draw_lines(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
	return 0;
}

int		main(void)
{
	t_game game;

	game_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);

	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}





// //////////////////////////////



// void	*game_init()
// {
// 	t_game *game;

// 	game = malloc(sizeof(t_game));
// 	game->mlx = mlx_init();
// 	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "tester");

// 	game->user.cor[0] = -1;
// 	game->user.cor[1] = -1;
// 	game->map = NULL;
// 	game->err_code = 0;

// 	return (game);
// }

// int		put_map(t_img tile)
// {

// 	int count_w;
// 	int count_h;

// 	count_h = -1;
// 	while (++count_h < TILE_SIZE)
// 	{
// 		count_w = -1;
// 		while (++count_w < TILE_SIZE)
// 			tile.data[count_h * TILE_SIZE + count_w] = 0xFFFFFF;
// 	}
// 	return 0;
// }

// int		main()
// {
// 	t_game *game;
// 	t_img	tile;


// 	game = game_init();




// 	put_map(img);

// 	//while ()

// 	mlx_put_image_to_window(game->mlx, game->win, img.ptr, 0, 0);
// 	mlx_put_image_to_window(game->mlx, game->win, img.ptr, 100, 100);

// 	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &key_press, &game->user);
// 	mlx_loop(game->mlx);
// 	free(game);

// 	return 0;
// }
