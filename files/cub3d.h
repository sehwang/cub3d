/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:44:03 by sehwang           #+#    #+#             */
/*   Updated: 2021/04/21 17:51:48 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"

// window
# define WIN_WIDTH 1000
# define WIN_HEIGHT 800

//img1
# define IMG_WIDTH 400
# define IMG_HEIGHT 300

//img2
# define IMG2_WIDTH 400
# define IMG2_HEIGHT 300

// key press
#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_release		3
#define X_EVENT_KEY_EXIT		17 //exit key code

//Mac key code example
#define KEY_ESC			53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

typedef struct 	s_param{
	int			x;
	int			y;
	char		str[3];
}				t_param;

typedef struct 	s_img{
	void		*ptr;
	int			*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

int		key_press(int keycode, t_param *param);
void	param_init(t_param *param);

#endif
