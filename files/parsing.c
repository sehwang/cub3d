/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:41:01 by sehwang           #+#    #+#             */
/*   Updated: 2021/05/18 11:45:21 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_valid_info(t_game *game)
{
	int r;
	int c;
	char	*t;

	game->map.c = 0;
	while (game->map.tap[game->map.c])
		game->map.c++;
	r = 0;
	while (r < game->map.c)
	{
		t = game->map.tap[r];
		if (r == 0 || r == game->map.c)
		{
			c = 0;
			while (*(t + c) != '\0')
			{
				if (*(t + c) != '1')
						game->error = 2;
				c++;
			}
			game->map.r = game->map.r >= c ? game->map.r : c;
		}
		else
		{
			c = 0;
			t = game->map.tap[r];
			while (*(t + c) != '\0')
			{
				if (*(t + c) == '2')
				{
					game->spr.x = c + 1;
					game->spr.y = r + 1;
				}
				if (ft_isalpha(*(t + c)))
				{
					if (*(t + c) == 'N')
						game->player.dir = 90;
					else if (*(t + c) == 'S')
						game->player.dir = 270;
					else if (*(t + c) == 'E')
						game->player.dir = 0;
					else if (*(t + c) == 'W')
						game->player.dir = 180;
					game->player.x = c + 1;
					game->player.y = r + 1;
				}
				c++;
			}
			game->map.r = game->map.r >= c ? game->map.r : c;
			if (*(t + c - 1) != '1')
				game->error = 2;
		}
		r++;
	}
	return (0);
}

int			ft_put_resolution(t_game *game, char *line)
{
	int		i;
	int		flag;

	i = 1;
	while (line[i] == ' ')
		i++;
	flag = 0;
	while (i < ft_strlen(line))
	{
		if (ft_isdigit(line[i]) && flag == 0)
		{
			game->win.x = ft_atoi(&line[i]);
			while (ft_isdigit(line[i]))
				i++;
			flag = 1;
		}
		else if (ft_isdigit(line[i]) && flag == 1)
		{
			game->win.y = ft_atoi(&line[i]);
			while (ft_isdigit(line[i]))
				i++;
			flag += 1;
		}
		else
			game->error = 1;
		i++;
	}
	game->ray.len = (double*)malloc(sizeof(double) * game->win.x);
	return (0);
}

void		ft_put_tex(t_game *game, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		game->text.north = ft_strdup(&line[3]);
	else if (line[0] == 'S' && line[1] == 'O')
		game->text.south = ft_strdup(&line[3]);
	else if (line[0] == 'W' && line[1] == 'E')
		game->text.west = ft_strdup(&line[3]);
	else if (line[0] == 'E' && line[1] == 'A')
		game->text.east = ft_strdup(&line[3]);
	else if (line[0] == 'S' && line[1] == ' ')
		game->text.sprite = ft_strdup(&line[2]);
	else if (line[0] == 'F' && line[1] == ' ')
		game->text.floor = ft_strdup(&line[2]);
	else if (line[0] == 'C' && line[1] == ' ')
		game->text.ceiling = ft_strdup(&line[2]);
	else
		game->error = 1;
}

int		ft_info_check(t_game *game)
{
	int	flag;

	flag = 1;
	if (game->win.x == -1 || game->win.y == -1)
		flag = 0;
	if (game->text.north == NULL || game->text.south == NULL || game->text.east == NULL || game->text.west == NULL)
		flag = 0;
	if (game->text.sprite == NULL || game->text.floor == NULL || game->text.ceiling == NULL)
		flag = 0;
	return (flag);
}

int			ft_put_game_info(t_game *game, char *line)
{
	char	i;
	int		flag;
	static char	*map_tmp;

	flag = 0;
	i = line[0];
	if (ft_isalpha(i))
	{
		if (i == 'R')
			flag = ft_put_resolution(game, line);
		else if (i == 'N' || i == 'S' || i == 'W' || i == 'E' || i == 'S' || i == 'F' || i == 'C')
			ft_put_tex(game, line);
		else
			printf("parsing error\n");
		return (0);
	}
	else if (ft_info_check(game))
	{
		if (i == '\0')
			return (0);
		else if (i == '1' || i == ' ')
		{
			map_tmp = ft_strjoin(map_tmp, " ");
			map_tmp = ft_strjoin(map_tmp, line);
			game->map.tap = ft_split(map_tmp, ' ');
		}
		else
			game->error = 1;
		return (0);
	}
	return (0);
}

int ft_parse(char *cub, t_game *game)
{
	int fd;
	int i;
	char *line;

	if (!(fd = open(cub, O_RDONLY)))
		printf("cub read error");
	while ((i = get_next_line(fd, &line) > 0))
	{
		ft_put_game_info(game, line);
		free(line);
	}
	ft_put_game_info(game, line);
	free(line);
	close(fd);
	if (i == -1)
		printf("cub read error");
	if (ft_valid_info(game) == -1)
		exit (0);
	ft_print_error(game);
	printf("R ===   x: %d, y: %d  Error: %d\n", game->win.x, game->win.y, game->error);
	printf("P ===   x: %f, y: %f  Error: %d\n", game->player.x, game->player.y, game->error);
	printf("S ===   x: %f, y: %f  Error: %d\n", game->spr.x, game->spr.y, game->error);
	printf("No: %s\nSo: %s\nSp: %s\nC: %s\n\n", game->text.north, game->text.south, game->text.sprite, game->text.ceiling);
	return (0);
}
