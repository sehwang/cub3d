/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 01:30:26 by inyang            #+#    #+#             */
/*   Updated: 2021/05/14 15:12:01 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		parse_check_1(t_all *a)
{
	if (a->pl.cnt == 0)
	{
		printf("No player\n");
		exit(0);
	}
	else if (a->pl.cnt > 1)
	{
		printf("Too many players\n");
		exit(0);
	}
	else if (a->map.map == NULL)
	{
		printf("No map here\n");
		exit(0);
	}
	else if (a->map.x + a->map.y < 6)
	{
		printf("Too small map\n");
		exit(0);
	}
}

void		parse_check(t_all *a)
{
	if (a->base.width == 0 || a->base.height == 0)
	{
		printf("No resolution input\n");
		exit(0);
	}
	else if (a->base.no == NULL || a->base.so == NULL ||
		a->base.we == NULL || a->base.ea == NULL || a->base.s == NULL)
	{
		printf("No texture for NSEWSP\n");
		exit(0);
	}
	else if (a->base.f[0] > 255 || a->base.f[1] > 255 || a->base.f[2] > 255
		|| a->base.f[0] < 0 || a->base.f[1] < 0 || a->base.f[2] < 0)
	{
		printf("Invalid color code for floor\n");
		exit(0);
	}
	else if (a->base.c[0] > 255 || a->base.c[1] > 255 || a->base.c[2] > 255
		|| a->base.c[0] < 0 || a->base.c[1] < 0 || a->base.c[2] < 0)
	{
		printf("Invalid color code for ceiling\n");
		exit(0);
	}
	parse_check_1(a);
}

void		print_error_2(int error)
{
	if (error == 12)
		printf("Tab in Map!");
	exit(0);
}

void		print_error(int error)
{
	if (error == 1)
		printf("AC or AV error : check again\n");
	else if (error == 2)
		printf("Fail to open file\n");
	else if (error == 3)
		printf(".cub file style error\n");
	else if (error == 4)
		printf("Uninitialized resolution\n");
	else if (error == 5)
		printf("Invalid resolution\n");
	else if (error == 6)
		printf("Uninitialized NSEWSP texture path\n");
	else if (error == 7)
		printf("Invalid map -> Enemy killed player\n");
	else if (error == 8)
		printf("Invalid texture\n");
	else if (error == 9)
		printf("Invalid color code\n");
	else if (error == 10)
		printf("Invalid things in map\n");
	else if (error == 11)
		printf("Player error\n");
	exit(0);
}
