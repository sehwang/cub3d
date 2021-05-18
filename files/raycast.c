/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:10:25 by sehwang           #+#    #+#             */
/*   Updated: 2021/05/18 15:31:13 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_wall_interaction(t_game *game, double ray_dir)//아래 변수들 game struct에 넣어줄 필요 있
{
	char	cell;
	int		hit;
	int		hit_side; //가로로?세로로? 세로 = 1, 가로 = 0

	// game->ray.step.x = sgn(cos(ray_dir));
	// game->ray.step.y = sgn(sin(ray_dir));

	game->ray.step.x = cos(ray_dir) > 0 ? 1 : cos(ray_dir) == 0 ? 0 : -1;
	game->ray.step.y = sin(ray_dir) > 0 ? 1 : sin(ray_dir) == 0 ? 0 : -1;

	game->ray.slop.x = tan(ray_dir);//infinit
	game->ray.slop.y = 1 / tan(ray_dir);

	//game->ray.step.nx = (game->ray.step.x > 0) ? floor(game->player.x) + 1 : ((game->ray.step.x < 0) ? ceil(game->player.x)-1 : game->player.x);
	//game->ray.step.nx = (game->ray.step.y > 0) ? floor(game->player.y) + 1 : ((game->ray.step.y < 0) ? ceil(game->player.y)-1 : game->player.y);

	if (game->ray.step.x > 0)
		game->ray.step.nx = floor(game->player.x) + 1;
	else if (game->ray.step.x < 0)
		game->ray.step.nx = ceil(game->player.x) - 1;
	else
		game->ray.step.nx = game->player.x;

	if (game->ray.step.y > 0)
		game->ray.step.ny = floor(game->player.y) + 1;
	else if (game->ray.step.y < 0)
		game->ray.step.ny = ceil(game->player.y) - 1;
	else
		game->ray.step.ny = game->player.y;

	//printf("\nray=%.2f deg, xstep=%d, ystep=%d, xslope=%.2f, yslope=%.2f, nx=%.2f, ny=%.2f\n",
	//rad2deg(ray_dir), game->ray.step.x, game->ray.step.y, game->ray.slop.x, game->ray.slop.y, game->ray.step.nx, game->ray.step.ny);

	hit = 0;
	while (!hit)
	{
		if (game->ray.step.x != 0)
			game->ray.f = game->ray.slop.x * (game->ray.step.nx - game->player.x) + game->player.y;
		if (game->ray.step.y != 0)
			game->ray.g = game->ray.slop.y * (game->ray.step.ny - game->player.y) + game->player.x;

		game->ray.dist.v = l2dist(game->player.x, game->player.y, game->ray.step.nx, game->ray.f);
		game->ray.dist.h = l2dist(game->player.x, game->player.y, game->ray.g, game->ray.step.ny);

		if ( game->ray.dist.v < game->ray.dist.h)
		{
			game->ray.wall.mx = (game->ray.step.x == 1) ? (int)(game->ray.step.nx) : (int)(game->ray.step.nx)-1 ;
			game->ray.wall.my = (int) game->ray.f;
			hit_side = 1;
			//printf(" V(%d, %.2f) ->", game->ray.wall.mx, game->ray.f);
		}
		else
		{
			game->ray.wall.mx = (int) game->ray.g;
			game->ray.wall.my = (game->ray.step.y == 1) ? (int)(game->ray.step.ny) : (int)(game->ray.step.ny)-1 ;
			hit_side = 0;
		}
		cell = map_get_cell(game->ray.wall.mx, game->ray.wall.my, game);
	//	printf("cell %c\n\n\n", cell);
		if (cell < '0')
			break ;
		if (cell == '1')
		{
			if (hit_side == 1)
			{
				game->ray.wall.dir = (game->ray.step.x > 0) ? 'w' : 'e';
				game->ray.wall.x = game->ray.step.nx;
				game->ray.wall.y = game->ray.f;
			}
			else {
				game->ray.wall.dir = (game->ray.step.y > 0) ? 'n' : 's';
				game->ray.wall.x = game->ray.g;
				game->ray.wall.y = game->ray.step.ny;
			}
			hit = 1;
			break;
		}
		if(hit_side == 1 )
			game->ray.step.nx += game->ray.step.x;
		else
			game->ray.step.ny += game->ray.step.y;
	}
	return (hit);
}

double	single_ray(int i, t_game *game)
{
	double	ray_dir;
	double	wdist;

	ray_dir = deg2rad((game->player.dir + FOV/2) - (i * FOV / (game->win.x - 1)));
	get_wall_interaction(game, ray_dir);
	wdist = l2dist(game->player.x, game->player.y, game->ray.wall.x, game->ray.wall.y);
	printf("num: %d, x: %.2f, y: %.2f, dir %.2f\n", i, game->player.x, game->player.y, game->player.dir);
	return (wdist);
}

// void	ft_print_map(t_game *game)// tmp
// {
// 	for( int y=game->map.r-1; y>=0; y-- ) {
//         for( int x=0; x<game->map.c; x++ ) {
//             printf("%c ", (map_get_cell(x,y, game)=='1' ? '#':'.'));
//         }
//         putchar('\n');
//     }
// }

int		ft_raycast(t_game *game)
{
	int i;

	//ft_print_map(game);//tmp
	i = 0;
	while (i < game->win.x)
	{
		game->ray.len[i] = single_ray(i, game);
		//printf("** ray %d: dist %.2f\n", i, game->ray.len[i]);
		i++;
	}
	ft_print_error(game);
	return (0);
}
