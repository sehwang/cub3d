/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:33:07 by inyang            #+#    #+#             */
/*   Updated: 2021/05/14 14:07:26 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_comma(char *line)
{
	int	comma_cnt;
	int	i;

	comma_cnt = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == ',')
			comma_cnt++;
	}
	if (comma_cnt != 2)
		print_error(9);
}

char	**comma_to_space(char *line)
{
	int		i;
	char	**tmp;
	char	*trimmed;
	int		num;

	check_comma(line);
	i = 0;
	num = 0;
	tmp = ft_split(line, ',');
	if (split_count(tmp) != 3)
		print_error(9);
	i = -1;
	while (++i < 3)
	{
		trimmed = ft_strtrim(tmp[i], " ");
		num = -1;
		while (++num < (int)ft_strlen(trimmed))
		{
			if (ft_isdigit(trimmed[num]) != 1)
				print_error(9);
		}
		free(tmp[i]);
		tmp[i] = trimmed;
	}
	return (tmp);
}

int		digit_check(char *arr)
{
	int i;
	int	check;

	i = 0;
	check = 0;
	while (arr[i])
	{
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			i++;
			check++;
		}
		else
			i++;
	}
	if (check == i)
		return (3);
	else
		return (4);
}

int		split_count(char **arr)
{
	int	cnt;
	int i;

	cnt = 0;
	i = 0;
	while (arr[i])
	{
		cnt++;
		i++;
	}
	return (cnt);
}

int		ft_isspace(char *line)
{
	int	i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
	|| (line[i] == '\r' || line[i] == '\v' || line[i] == '\f'))
		return (3);
	return (0);
}
