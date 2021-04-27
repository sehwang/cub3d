/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:18:11 by sehwang           #+#    #+#             */
/*   Updated: 2021/04/27 15:23:27 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				key_press(int keycode, t_user *user)
{
	if (keycode == KEY_W)//Action when W key pressed
		user->cor[0]++;
	else if (keycode == KEY_S) //Action when S key pressed
		user->cor[0]--;
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	printf("x: %d, y: %d\n", user->cor[0], user->cor[1]);
	return (0);
}
