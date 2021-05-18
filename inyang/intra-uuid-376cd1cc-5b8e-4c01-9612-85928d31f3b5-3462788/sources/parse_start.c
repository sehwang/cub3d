/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:11:40 by inyang            #+#    #+#             */
/*   Updated: 2021/05/14 14:05:50 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		put_map_rgb(t_all *a, char *line, int fc)
{
	char	**file;
	int		i;

	file = comma_to_space(line);
	i = 0;
	i = -1;
	a->base.cnt++;
	if (fc == 0)
	{
		a->base.f[0] = ft_atoi(file[0]);
		a->base.f[1] = ft_atoi(file[1]);
		a->base.f[2] = ft_atoi(file[2]);
	}
	if (fc == 1)
	{
		a->base.c[0] = ft_atoi(file[0]);
		a->base.c[1] = ft_atoi(file[1]);
		a->base.c[2] = ft_atoi(file[2]);
	}
	if (digit_check(file[0]) != 3 || digit_check(file[1]) != 3 ||
		digit_check(file[2]) != 3)
		print_error(9);
	free_double_array(file, 3);
	return (0);
}

int		put_map_tex(t_all *a, char *line, int ewsn)
{
	char	**file;

	file = ft_split(line, ' ');
	if (split_count(file) != 2 || (check_word(file[1], "xpm") != 1))
		print_error(8);
	a->base.cnt++;
	if (ewsn == 0 && a->base.no == NULL)
		a->base.no = ft_strdup(file[1]);
	else if (ewsn == 1 && a->base.so == NULL)
		a->base.so = ft_strdup(file[1]);
	else if (ewsn == 2 && a->base.we == NULL)
		a->base.we = ft_strdup(file[1]);
	else if (ewsn == 3 && a->base.ea == NULL)
		a->base.ea = ft_strdup(file[1]);
	else if (ewsn == 4 && a->base.s == NULL)
		a->base.s = ft_strdup(file[1]);
	else
		print_error(8);
	free_double_array(file, 2);
	return (0);
}

void	put_map_r(t_all *a, char *line)
{
	char	**arr;

	if (a->base.width != 0 || a->base.height != 0)
		print_error(4);
	arr = ft_split(line, ' ');
	if (split_count(arr) == 3)
	{
		a->base.width = ft_atoi(arr[1]);
		a->base.height = ft_atoi(arr[2]);
	}
	if (a->base.width <= 0 || a->base.height <= 0 || split_count(arr) != 3
		|| digit_check(arr[1]) != 3 || digit_check(arr[2]) != 3)
		print_error(5);
	resolution_size(a);
	free_double_array(arr, 3);
	a->base.cnt++;
}

void	basic_info(t_all *a, char *line, int i)
{
	if (*line != '\0')
	{
		if (line[i] == 'R' && line[i + 1] == ' ')
			put_map_r(a, line);
		else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
			put_map_tex(a, line, 0);
		else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
			put_map_tex(a, line, 1);
		else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
			put_map_tex(a, line, 2);
		else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
			put_map_tex(a, line, 3);
		else if (line[i] == 'S' && line[i + 1] == ' ')
			put_map_tex(a, line, 4);
		else if (line[i] == 'F' && line[i + 1] == ' ')
			put_map_rgb(a, line + 2, 0);
		else if (line[i] == 'C' && line[i + 1] == ' ')
			put_map_rgb(a, line + 2, 1);
		else
			print_error(3);
	}
}

void	read_cub_src(t_all *a, char *src)
{
	int		fd;
	int		value;
	char	*line;
	char	*line_tmp;

	fd = open(src, O_RDONLY);
	if (fd == -1)
		print_error(2);
	value = 1;
	while (value == 1)
	{
		value = get_next_line(fd, &line);
		if (a->base.cnt != 8)
		{
			line_tmp = ft_strtrim(line, " ");
			basic_info(a, line_tmp, a->i);
			free(line_tmp);
		}
		else if (a->base.cnt == 8)
			map_line_info(a, line);
		free(line);
	}
	a->map.x += 1;
	after_map(a);
}
