/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:14:50 by sehwang           #+#    #+#             */
/*   Updated: 2021/04/30 12:30:41 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
#include <string.h>
# include <math.h>

//screen

// tile
# define TILE_SIZE 50

# define ROWS 11
# define COLS 15
# define WIN_WIDTH COLS * TILE_SIZE
# define WIN_HEIGHT ROWS * TILE_SIZE

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

# define TO_COORD(X, Y) ((int)floor(Y) * WIN_WIDTH + (int)floor(X))

typedef struct	s_user
{
	int cor[2];
	float rad;
}				t_user;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef	struct 	s_game
{
	void	*mlx;
	void	*win;
	int 	map[ROWS][COLS];
	t_img	img;
	t_user	user;
	//int		err_code;
}				t_game;

int		deal_key(int key_code, t_game *game);
void	draw_rectangle(t_game *game, int x, int y);
void	draw_rectangles(t_game *game);
void 	draw_lines(t_game *game);
void	draw_line(t_game *game, double x1, double y1, double x2, double y2);

#endif
