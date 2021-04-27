/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:02:20 by sehwang           #+#    #+#             */
/*   Updated: 2021/04/27 15:34:46 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//# define WIN_WIDTH 800
//# define WIN_HEIGHT 600

# define IMG_WIDTH 400
# define IMG_HEIGHT 300

void	*game_init()
{
	t_game *game;

	game = malloc(sizeof(t_game));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "tester");
	
	game->user.cor[0] = -1;
	game->user.cor[1] = -1;
	game->map = NULL;
	game->err_code = 0;

	return (game);
}

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

int		main()
{
	t_game *game;
	t_img	img;
	
//	int img_width;
//	int img_height;
	
	int count_w;
	int count_h;

	game = game_init();
	img.ptr = mlx_new_image(game->mlx, IMG_WIDTH, IMG_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_l, &img.endian);
	
	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
			img.data[count_h * IMG_WIDTH + count_w] = 0xFFFFFF;
	}



	//img = mlx_xpm_file_to_image(game->mlx, "../img/wall_e.xpm", &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img.ptr, 0, 0);
	
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &key_press, &game->user);
	mlx_loop(game->mlx);
	free(game);

	return 0;
}
