/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:29:24 by inyang            #+#    #+#             */
/*   Updated: 2021/05/10 20:37:46 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_image(t_all *a, int *texture, char *path)
{
	int x;
	int y;

	y = -1;
	a->img.img = mlx_xpm_file_to_image(a->info.mlx, path,
		&a->img.img_width, &a->img.img_height);
	if (a->img.img == NULL)
	{
		printf("Invalid xpm\n");
		exit(0);
	}
	a->img.data = (int *)mlx_get_data_addr(a->img.img, &a->img.bpp,
		&a->img.size_l, &a->img.endian);
	while (++y < a->img.img_height)
	{
		x = -1;
		while (++x < a->img.img_width)
		{
			texture[a->img.img_width * y + x] =
				a->img.data[a->img.img_width * y + x];
		}
	}
	mlx_destroy_image(a->info.mlx, a->img.img);
}

void	load_texture(t_all *a)
{
	load_image(a, a->info.texture[0], a->base.no);
	load_image(a, a->info.texture[1], a->base.so);
	load_image(a, a->info.texture[2], a->base.ea);
	load_image(a, a->info.texture[3], a->base.we);
	load_image(a, a->info.texture[4], a->base.s);
}

void	texture_init(t_all *a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < TEXHEIGHT * TEXWIDTH)
		{
			a->info.texture[i][j] = 0;
		}
	}
}

int		texture_alloc(t_all *a)
{
	int i;

	a->info.z_buffer = ft_calloc(sizeof(double), a->base.width);
	a->info.buf = ft_calloc(sizeof(int *), (a->base.height));
	i = -1;
	while (++i < a->base.height)
		a->info.buf[i] = ft_calloc(sizeof(int), (a->base.width));
	if (!(a->info.texture = (int **)malloc(sizeof(int *) * 5)))
		return (-1);
	i = -1;
	while (++i < 5)
	{
		if (!(a->info.texture[i] =
			(int *)malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH))))
			return (-1);
	}
	texture_init(a);
	load_texture(a);
	return (0);
}
