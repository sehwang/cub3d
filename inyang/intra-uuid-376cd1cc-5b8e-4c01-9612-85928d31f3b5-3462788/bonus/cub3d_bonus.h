/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:57:24 by inyang            #+#    #+#             */
/*   Updated: 2021/05/14 15:10:24 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <math.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "../assets/libft/libft.h"
# include "../assets/get_next_line/get_next_line.h"
# include "../assets/mlx/mlx.h"

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define TEXWIDTH 			64
# define TEXHEIGHT 			64

# define FILE_HEADER_SIZE	14
# define INFO_HEADER_SIZE	40
# define IMG_DEPTH			4
# define BMP_BPP 			32

# define K_A 				0
# define K_D 				2
# define K_S 				1
# define K_W 				13
# define K_AR_L 			123
# define K_AR_R 			124
# define K_ESC 				53

typedef	struct			s_base {
	int					width;
	int					height;

	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*s;

	int					f[3];
	int					c[3];
	int					cnt;
	int					enter;
}						t_base;

typedef struct			s_txtr {
	int					par_cnt;
	int					*width;
	int					*height;
	int					*bpp;
	int					*size_line;
	int					*endian;
}						t_txtr;

typedef struct			s_map {
	char				**map;
	int					**map_int;
	int					size;
	int					x;
	int					y;
}						t_map;

typedef struct			s_dfs {
	char				**map_dfs;
	double				*spr_x;
	double				*spr_y;
}						t_dfs;

typedef struct			s_player {
	int					cnt;
	double				pos_x;
	double				pos_y;
	char				view;
}						t_player;

typedef struct			s_img
{
	void				*img;
	int					*data;
	int					size_l;
	int					bpp;
	int					endian;
	int					img_width;
	int					img_height;
}						t_img;

typedef struct			s_calc
{
	double				cam_x;
	double				raydir_x;
	double				raydir_y;
	int					map_x;
	int					map_y;
	double				side_dist_x;
	double				side_dist_y;
	double				d_dist_x;
	double				d_dist_y;
	double				p_w_dist;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	double				wall_x;
	int					draw_start;
	int					draw_end;
	int					tex_num;
	int					tex_x;
	int					line_h;
	double				step;
	double				tex_pos;
	int					tex_y;
	int					color;
}						t_calc;

typedef struct			s_info
{
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				vec_x;
	double				vec_y;
	void				*mlx;
	void				*win;
	int					**buf;
	int					**texture;
	double				move_speed;
	double				rot_speed;
	double				*z_buffer;
}						t_info;

typedef struct			s_sprite
{
	double				*x;
	double				*y;
	int					texture;
	int					cnt;
	int					xy_cnt;
	double				trans_x;
	double				trans_y;
	int					screen_x;
	int					spr_h;
	int					spr_w;
	int					draw_s_x;
	int					draw_s_y;
	int					draw_f_x;
	int					draw_f_y;
	int					color;
}						t_sprite;

typedef struct			s_pair
{
	double				first;
	int					second;
}						t_pair;

typedef struct			s_bitmapfileheader
{
	unsigned short		bf_type;
	unsigned int		bf_size;
	unsigned short		bf_reserved1;
	unsigned short		bf_reserved2;
	unsigned int		bf_off_bits;
}						t_bitmapfileheader;

typedef struct			s_bitmapinfoheader
{
	unsigned int		bi_size;
	int					bi_width;
	int					bi_height;
	unsigned short		bi_planes;
	unsigned short		bi_bit_count;
	unsigned int		bi_compression;
	unsigned int		bi_size_image;
	int					bi_x_pels_per_meter;
	int					bi_y_pels_per_meter;
	unsigned int		bi_clr_used;
	unsigned int		bi_clr_important;
}						t_bitmapinfoheader;

typedef struct			s_bmp
{
	int					save;
	int					fd;
}						t_bmp;

typedef struct			s_all {
	void				*mlx;
	void				*win;
	int					save;
	int					i;

	t_base				base;
	t_txtr				txtr;
	t_map				map;
	t_dfs				map_dfs;
	t_player			pl;
	t_img				img;
	t_info				info;
	t_calc				calc;
	t_sprite			sprite;
	t_pair				pair;
	t_bitmapfileheader	bfh;
	t_bitmapinfoheader	bih;
	t_bmp				bmp;
}						t_all;

char					check_save(char *av, char *word);
char					check_word(char *av, char *word);
char					**comma_to_space(char *line);
int						ft_isspace(char *line);
int						split_count(char **arr);
int						digit_check(char *arr);

void					base_reset(char *src, t_all *a);

void					read_cub_src(t_all *a, char *src);
void					basic_info(t_all *a, char *line, int i);
void					put_map_r(t_all *a, char *line);
int						put_map_tex(t_all *a, char *line, int ewsn);
int						put_map_rgb(t_all *a, char *line, int fc);

void					map_line_info(t_all *a, char *line);

int						parse_map_start(t_all *a, char *line, int strlen);

void					after_map(t_all *a);
void					ft_r_tex_info(t_all *a, char *line);

void					dfs_map(t_all *a);
void					dfs_out(t_all *a);
void					dfs_out_2(t_all *a);
void					change_to_nine(t_all *a, int x, int y);
void					dfs_in(t_all *a);

void					print_error(int error);
void					print_error_2(int error);
void					parse_check(t_all *a);
void					parse_check_1(t_all *a);

int						map_yoso_check(char *a);
void					dfs_map_make(t_all *a, int i, int j);

int						graphic_start(t_all *a);

int						ft_close_program(void);
void					calc(t_all *a);
int						main_loop(t_all *a);
int						key_press(int key, t_all *a);
void					load_image(t_all *a, int *texture, char *path);
void					load_texture(t_all *a);

void					ft_map_to_int(t_all *a);

void					key_update(t_all *a);

int						texture_alloc(t_all *a);

void					calc_1(t_all *a, int x);
void					calc_1_1(t_all *a);
void					calc_2(t_all *a);
void					calc_3(t_all *a);
void					calc_4(t_all *a, int x);

void					texture_nsew(t_all *a);
void					key_rl_cal(int i, double old_dir_x,
							double old_plane_x, t_all *a);
void					key_rl_cal_2(int i, double old_dir_x,
							double old_plane_x, t_all *a);

void					player_view(t_all *a);
void					player_view_ew(t_all *a);

void					sort_sprites(int *order, double *dist, int amount);
void					sprite_draw(t_all *a);
void					sprite_pos(t_all *a, int i, int *sprite_order);
void					sprite_size(t_all *a);
void					stripe_draw(t_all *a);

void					bmp(t_all *a);

void					free_double_array(char **map, int cnt);

void					path_check(t_all *a);
void					resolution_size(t_all *a);
int						enter_check(t_all *a, char *line);
int						cub_check(t_all *a, char *line);

void					music_start(void);
void					music_stop(void);

#endif
