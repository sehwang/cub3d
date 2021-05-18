/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:18:11 by sehwang           #+#    #+#             */
/*   Updated: 2021/04/29 17:32:05 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_W)//Action when W key pressed
		game->user.cor[0]++;
	else if (key_code == KEY_S) //Action when S key pressed
		game->user.cor[0]--;
	else if (key_code == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	printf("x: %d, y: %d\n", game->user.cor[0], game->user.cor[1]);
	return (0);
}
