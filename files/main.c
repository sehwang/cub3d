/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:04:32 by sehwang           #+#    #+#             */
/*   Updated: 2021/04/21 17:58:33 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	void		*mlx;
	void		*win;

	t_img		img;
	int			img_w;
	int			img_h;

	int			cnt_w;
	int			cnt_h;

	t_param 	param;

	param_init(&param);
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "test");

	//xpm img
	img.ptr	= mlx_xpm_file_to_image(mlx, "img/wall_n.xpm", &img_w, &img_h);
	img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_l, &img.endian);

	cnt_h = -1;
	while (++cnt_h < img.height)
	{
		cnt_w = -1;
		while (++cnt_w < img.width / 2)
		{
			if (cnt_w % 2)
				img.data[cnt_h * img.width + cnt_w] = 0xFFFFFF;
			else
				img.data[cnt_h * img.width + cnt_w] = 0xFF0000;
		}
	}
	mlx_put_image_to_window(mlx, win, img.ptr, 500, 500);

	// key input
	printf("-------------------------------\n");
	printf("'W key': Add 1 to x.\n");
	printf("'S key': Subtract 1 from x\n");
	printf("'ESC key': Exit this program\n");
	printf("'Other keys': print current x \n");
	printf("-------------------------------\n");
	printf("Current x = 3\n");
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &param);//parameter check
	mlx_loop(mlx);
}
