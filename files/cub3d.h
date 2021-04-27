/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:14:50 by sehwang           #+#    #+#             */
/*   Updated: 2021/04/27 15:19:53 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

//screen
# define WIN_WIDTH 1000
# define WIN_HEIGHT 800

//key
#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_release		3
#define X_EVENT_KEY_EXIT		17 //exit key code

//Mac key code example
//All the key code example other than below is described on the site linked in READEME.md
#define KEY_ESC			53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct	s_user
{
	int cor[2];
	float rad;
}				t_user;

typedef	struct 	s_game
{
	void	*mlx;
	void	*win;
	int		**map;
	t_user	user;
	int		err_code;
}				t_game;

int				key_press(int keycode, t_user *user);

#endif
