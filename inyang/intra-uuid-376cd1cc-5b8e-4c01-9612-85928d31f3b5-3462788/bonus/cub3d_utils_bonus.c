/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:49:56 by inyang            #+#    #+#             */
/*   Updated: 2021/05/14 15:11:26 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	check_save(char *av, char *word)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
		i++;
	if (i == 6 && av[i - 1] == word[5] && av[i - 2] == word[4]
		&& av[i - 3] == word[3] && av[i - 4] == word[2]
		&& av[i - 5] == word[1] && av[i - 6] == word[0])
		return (1);
	return (0);
}

char	check_word(char *av, char *word)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
		i++;
	if (i > 4 && av[i - 1] == word[2] && av[i - 2] == word[1]
		&& av[i - 3] == word[0] && av[i - 4] == '.')
		return (1);
	return (0);
}
