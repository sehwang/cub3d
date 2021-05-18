/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwang <sehwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:13:54 by sehwang           #+#    #+#             */
/*   Updated: 2021/05/18 14:11:07 by sehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h> // check
# include <string.h> //remove
#include "../mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

typedef struct	s_player
{
	double 		x;
	double 		y;
	double		dir;
}				t_player;

typedef struct	s_spr
{
	double		x;
	double		y;
}				t_spr;

typedef struct	s_win
{
	void		*ptr;
	int			x;
	int			y;
}				t_win;

typedef struct	s_map
{
	char		**tap;
	int			r;
	int			c;
	int			spr;//???
}				t_map;

typedef struct	s_img
{
	void		*ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_testure
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
	char		*floor;
	char		*ceiling;
	int			error;
}				t_texture;

typedef struct 	s_step
{
	int			x;
	int			y;
	double		nx;
	double		ny;
}				t_step;

typedef	struct	s_slop
{
	double		x;
	double		y;
}				t_slop;

typedef struct s_wall
{
	char		dir;
	int			mx;
	int			my;
	double		x;
	double		y;
}				t_wall;

typedef struct	s_dist
{
	double		v;
	double		h;
}				t_dist;

typedef	struct	s_ray
{
	t_step		step;
	t_slop		slop;
	t_wall		wall;
	t_dist		dist;
	double		f;
	double		g;
	double		*len;
}				t_ray;

typedef struct	s_game
{
	void		*mlx;
	t_win		win;
	t_player	player;
	t_spr		spr;
	t_img		img;
	t_map		map;
	t_ray		ray;
	t_texture	text;
	int			error;
}				t_game;

//FOV revise
# define FOV 60
# define PI 3.141592

//Color
# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF

//key input
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define UP 			126
# define DOWN			125
# define LEFT 			123
# define RIGHT 			124

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_release	3
# define X_EVENT_KEY_EXIT		17 //exit key code

//move
# define SPEED 15
# define TURN 0.05

//parsing
int		ft_parse(char *cub, t_game *game);
int		get_next_line(int fd, char **line);

//game
int		ft_game(t_game *game);

//raycast
int		ft_raycast(t_game *game);
//rendering
int		ft_rendering(t_game *game);

//macro
int 		is_zero(double d);
int			sgn(double d);
double	deg2rad(double th);
double	rad2deg(double th);
char		map_get_cell(int x, int y, t_game *game);
double		l2dist(double x1, double y1, double x2, double y2);

//
void	ft_print_error(t_game *game);

//utils

int		ft_isalpha(int c);
int		ft_isdigit(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_check_extention(char *file, char *extention);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);

//others
int			ft_atoi(const char *nptr);
char		**ft_split(char const *s, char c);
#endif
