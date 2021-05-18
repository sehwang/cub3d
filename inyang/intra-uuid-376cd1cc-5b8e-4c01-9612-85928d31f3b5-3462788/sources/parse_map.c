/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:33:40 by inyang            #+#    #+#             */
/*   Updated: 2021/05/13 22:25:21 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map_count(t_all *a, char *line)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		if (map_yoso_check(&line[i]) == 5)
			cnt++;
		else if (line[i] == '\t')
			cnt += 4;
		else
			print_error(10);
		i++;
	}
	if (a->map.y < cnt)
		a->map.y = cnt;
	return (cnt);
}

char	*line_malloc(t_all *a, char *line, int strlen)
{
	char	*box;
	int		i;
	int		j;

	if (!(box = malloc(sizeof(char) * (strlen + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (line[j] != '\0')
	{
		if (map_yoso_check(&line[j]) == 5)
		{
			if (line[j] == '2')
				a->sprite.cnt++;
			box[i++] = line[j];
		}
		else if (line[j] == '\t')
			print_error_2(12);
		j++;
	}
	box[i] = '\0';
	return (box);
}

int		parse_map_start(t_all *a, char *line, int strlen)
{
	char	**map_save;
	int		i;

	if (!(map_save = ft_calloc(sizeof(char *), (a->map.x + 1))))
	{
		printf("map allocate error");
		exit(0);
	}
	i = -1;
	while (++i < a->map.x)
		map_save[i] = a->map.map[i];
	if ((map_save[a->map.x] = line_malloc(a, line, strlen)) == NULL)
	{
		printf("x error");
		exit(0);
	}
	if (a->map.map)
		free(a->map.map);
	a->map.map = map_save;
	return (0);
}

void	map_line_info(t_all *a, char *line)
{
	int	strlen;

	strlen = map_count(a, line);
	a->map.x++;
	a->base.enter = 1;
	parse_map_start(a, line, strlen);
}
