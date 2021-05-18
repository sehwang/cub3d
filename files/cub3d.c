/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:14:04 by sehwang           #+#    #+#             */
/*   Updated: 2021/05/17 17:42:30 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int ft_info_init(t_game *game)
{
	game->win.ptr = NULL;
	game->win.x = -1;
	game->win.x = -1;
	game->player.x = -1;
	game->player.y = -1;
	game->player.dir = -1;
	game->spr.x = -1;
	game->spr.y = -1;
	game->map.tap = NULL;
	game->map.r = -1;
	game->map.c = -1;
	game->map.spr = -1;
	game->ray.len = NULL;
	game->text.north = NULL;
	game->text.south = NULL;
	game->text.east = NULL;
	game->text.west = NULL;
	game->text.ceiling = NULL;
	game->text.floor = NULL;
	game->text.sprite = NULL;
	game->text.error = -1;
	//printf("\ninfo_works\n\n");
	game->error = -1;
	return (1);
}

void	ft_init(char *cub, int option)
{
	t_game	game;
	ft_info_init(&game);
	ft_parse(cub, &game);
	ft_game(&game);
	printf("%s, %d\n", cub, option);
	//printf("init works\n\n");
	exit (0);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ft_check_extention(av[1], "cub"))
	{
		if (ac == 3 && ft_strcmp(av[2], "--save") == 0)
			ft_init(av[1], 1);
		else if (ac == 2)
			ft_init(av[1], 0);
	}
	write(2, "arg_err", 8);
	return (0);
}
