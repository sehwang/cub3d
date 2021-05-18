/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 00:07:03 by inyang            #+#    #+#             */
/*   Updated: 2021/05/14 15:11:08 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int ac, char **av)
{
	t_all	a;

	if (ac == 2 && check_word(av[1], "cub") == 1)
		base_reset(av[1], &a);
	else if (ac == 3 && (check_word(av[1], "cub") == 1)
		&& (check_save(av[2], "--save") == 1))
	{
		a.bmp.save = 1;
		base_reset(av[1], &a);
	}
	else
		print_error(1);
	return (0);
}
