/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:21:00 by inyang            #+#    #+#             */
/*   Updated: 2021/05/10 14:54:17 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bitmap_file_header(t_all *a)
{
	a->bfh.bf_type = 'B';
	a->bfh.bf_type <<= 8;
	a->bfh.bf_type += 'M';
	a->bfh.bf_size = 54 + 4 * a->base.width * a->base.height;
	a->bfh.bf_reserved1 = 0;
	a->bfh.bf_reserved2 = 0;
	a->bfh.bf_off_bits = 54;
	write(a->bmp.fd, "B", 1);
	write(a->bmp.fd, "M", 1);
	write(a->bmp.fd, &a->bfh.bf_size, 4);
	write(a->bmp.fd, &a->bfh.bf_reserved1, 2);
	write(a->bmp.fd, &a->bfh.bf_reserved2, 2);
	write(a->bmp.fd, &a->bfh.bf_off_bits, 4);
}

void	bitmap_info_header(t_all *a)
{
	a->bih.bi_size = 40;
	a->bih.bi_width = a->base.width;
	a->bih.bi_height = -a->base.height;
	a->bih.bi_planes = 1;
	a->bih.bi_bit_count = 32;
	a->bih.bi_compression = 0;
	a->bih.bi_size_image = 4 * a->base.width * a->base.height;
	a->bih.bi_x_pels_per_meter = 0;
	a->bih.bi_y_pels_per_meter = 0;
	a->bih.bi_clr_used = 0;
	a->bih.bi_clr_important = 0;
	write(a->bmp.fd, &a->bih.bi_size, 4);
	write(a->bmp.fd, &a->bih.bi_width, 4);
	write(a->bmp.fd, &a->bih.bi_height, 4);
	write(a->bmp.fd, &a->bih.bi_planes, 2);
	write(a->bmp.fd, &a->bih.bi_bit_count, 2);
	write(a->bmp.fd, &a->bih.bi_compression, 4);
	write(a->bmp.fd, &a->bih.bi_size_image, 4);
	write(a->bmp.fd, &a->bih.bi_x_pels_per_meter, 4);
	write(a->bmp.fd, &a->bih.bi_y_pels_per_meter, 4);
	write(a->bmp.fd, &a->bih.bi_clr_used, 4);
	write(a->bmp.fd, &a->bih.bi_clr_important, 4);
}

void	bmp(t_all *a)
{
	a->bmp.fd = open("save.bmp", O_RDWR | O_TRUNC | O_APPEND | O_CREAT
	, S_IRWXU | S_IRWXG | S_IRWXO);
	bitmap_file_header(a);
	bitmap_info_header(a);
	write(a->bmp.fd, a->img.data, a->bih.bi_size_image);
	close(a->bmp.fd);
	printf("Say CHEESE~\n");
	exit(0);
}
