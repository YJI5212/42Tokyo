/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoinoue <yoinoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 19:28:53 by yoinoue           #+#    #+#             */
/*   Updated: 2021/02/12 17:15:36 by yoinoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
**----------defalut header files---------
*/
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include "mlx.h"
# include <stdio.h>

/*
**------------libft header file------------
*/
# include "../libft/libft.h"

/*
**-------------define key code-----------
*/
# ifdef __MACH__
#  define ESC				53
#  define W					13
#  define A					0
#  define S					1
#  define D					2
#  define RIGHT				124
#  define LEFT				123
#  define UP				126
#  define DOWN				125
# else
#  define ESC				0xff1b
#  define W					0x77
#  define A					0x61
#  define S					0x73
#  define D					0x64
#  define RIGHT				0xff53
#  define LEFT				0xff51
#  define UP				0xff52
#  define DOWN				0xff54
# endif

/*
**---------define texture numbers--------
*/
# define NORTH_TEXTURE		0
# define SOUTH_TEXTURE		1
# define EAST_TEXTURE		2
# define WEST_TEXTURE		3
# define SPRITE_TEXTURE		4

/*
**--------------define others------------
*/
# define BMP_HEADER_SIZE	54

/*
**--------------structures---------------
*/
typedef struct				s_render_fc_vct
{
	float					raydirx0;
	float					raydiry0;
	float					raydirx1;
	float					raydiry1;
	int						p;
	float					posz;
	float					rowdistance;
	float					floorstepx;
	float					floorstepy;
	float					floorx;
	float					floory;
	int						color;
}							t_render_fc_vct;

typedef struct				s_render_w_vct
{
	double					camerax;
	double					raydirx;
	double					raydiry;
	int						mapx;
	int						mapy;
	double					sidedistx;
	double					sidedisty;
	double					deltadistx;
	double					deltadisty;
	double					perpwalldist;
	int						stepx;
	int						stepy;
	int						hit;
	int						side;
	int						lineheight;
	int						drawstart;
	int						drawend;
	int						texnum;
	double					wallx;
	int						texx;
	double					step;
	double					texpos;
	int						texy;
	int						color;
}							t_render_w_vct;

typedef struct				s_render_sp_vct
{
	int						i;
	double					spritex;
	double					spritey;
	double					invdet;
	double					transformx;
	double					transformy;
	int						spritescreenx;
	int						spriteheight;
	int						drawstarty;
	int						drawendy;
	int						spritewidth;
	int						drawstartx;
	int						drawendx;
	int						stripe;
	int						texx;
	int						y;
	int						d;
	int						texy;
	int						color;
}							t_render_sp_vct;

typedef struct				s_data
{
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
}							t_data;

typedef struct				s_vectors
{
	double					posx;
	double					posy;
	double					dirx;
	double					diry;
	double					planex;
	double					planey;
}							t_vectors;

typedef struct				s_info
{
	int						resolution[2];
	char					*path_n;
	char					*path_e;
	char					*path_w;
	char					*path_s;
	char					*path_sprite;
	int						floor_rgb[3];
	int						ceiling_rgb[3];
	char					**map;
}							t_info;

typedef struct				s_tex
{
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
	int						texwidth;
	int						texheight;
}							t_tex;

typedef struct				s_sp_data
{
	double					x;
	double					y;
	int						texture;
}							t_sp_data;

typedef struct				s_sp_array
{
	double					dist;
	int						order;
}							t_sp_array;

typedef struct				s_vars
{
	void					*mlx;
	void					*win;

	int						screenwidth;
	int						screenheight;

	t_vectors				vct;
	t_info					info;
	t_data					img;
	t_tex					texture[5];
	unsigned int			*buf;

	int						numsprites;
	t_sp_data				*sprite_data;
}							t_vars;

typedef struct				s_search_pl_and_sp
{
	int						x;
	int						y;
	int						i;
}							t_search_pl_and_sp;

typedef struct				s_info_init
{
	int						fd;
	int						rc;
	char					*map_info;
	int						flag;
}							t_info_init;

/*
**-----------Prototype declaration----------
*/
/*
**cub3d.c
*/
void						sortsprites(
	t_vars *vars, t_sp_array array[],
	int spriteorder[], double spritedistance[]);
void						my_mlx_pixel_put(
	t_vars *vars, int x, int y, int color);
int							my_get_pixel_color(
	t_tex *texture, int texx, int texy);
void						my_mlx_put_image_to_window(
	t_vars *vars, int save_flag);
void						free_all(t_vars *vars);
int							close_window(t_vars *vars);

/*
**error.c
*/
# define INPUT_ERROR		1
# define MAP_ERROR			2
# define MEMORY_ERROR		3
# define FILE_ERROR			4

int							error_check(int my_errno);

/*
**flood_fill.c
*/
int							check_map_flood_fill(
	char **map, int x, int y, int *flag);
int							search_player_and_sprite(t_vars *vars_p);

/*
**flood_fill2.c
*/
void						set_dir_and_plane_ne(
	t_vars *vars_p, int x, int y);
void						set_dir_and_plane_ws(
	t_vars *vars_p, int x, int y);

/*
**get_next_line.c
*/
int							get_next_line(int fd, char **line);

/*
**info_check.c
*/
int							check_name(char *path);
int							check_resolution(
	t_vars *vars_p, char *map_info);
int							check_tex_and_sprite(
	t_vars *vars_p, char *map_info);
int							check_map_file(
	t_vars *vars_p, char *map_info_line, int flag);
int							is_valid_color(int *color_array);

/*
**info_check2.c
*/
int							check_floor_and_ceiling(
	t_vars *vars_p, char *map_info);
int							check_all_key_exist(t_vars *vars_p);

/*
**info_fill_tex.c
*/
int							fill_no(
	t_vars *vars_p, char *map_info_line);
int							fill_so(
	t_vars *vars_p, char *map_info_line);
int							fill_we(
	t_vars *vars_p, char *map_info_line);
int							fill_ea(
	t_vars *vars_p, char *map_info_line);
int							fill_s(
	t_vars *vars_p, char *map_info_line);

/*
**info.c
*/
void						init_vars(t_vars *vars_p);
int							info_init(t_vars *vars, char *path);

/*
**utils.c
*/
void						**ft_ptrjoin(
	const void **array, const void *new);
size_t						ft_ptrlen(const void **array);
void						ft_ptrcpy(void **dst, const void **src);
void						ft_ptrcat(void **dst, const void *src);
void						free_all(t_vars *vars);

/*
**bmp.c
*/
void						header_init(
	char *header, t_vars vars, int filesize);
int							bmp_process(
	t_vars vars, int filesize, int fd);

/*
**keydown.c
*/
int							keydown(int keycode, t_vars *vars);

/*
**fill_tex.c
*/
void						fill_texture(t_vars *vars);

/*
**render_floor_and_ceiling.c
*/
void						render_set_mlx(t_vars *vars);
void						render_floor_and_ceiling(t_vars *vars);

/*
**render_wall1.c
*/
void						render_walls(t_vars *vars, double *zbuffer);

/*
**render_wall2.c
*/
void						render_w_x1(
	t_vars *vars, t_render_w_vct *vct_data, int x);
void						render_w_x2(
	t_vars *vars, t_render_w_vct *vct_data);
void						render_w_x3(
	t_vars *vars, t_render_w_vct *vct_data);
void						render_w_x4(
	t_vars *vars, t_render_w_vct *vct_data);

/*
**render_sprite.c
*/
void						render_sprite(
	t_vars *vars, double *zbuffer);

/*
**render_sprite2.c
*/
void						calc_projection(
	t_vars *vars, t_render_sp_vct *vct_data, int spriteorder[]);

/*
**screen.c
*/
int							set_screensize(t_vars *vars);
int							close_window(t_vars *vars);

/*
**my_mlx.c
*/
void						my_mlx_pixel_put(
	t_vars *vars, int x, int y, int color);
int							my_get_pixel_color(
	t_tex *texture, int texx, int texy);
void						my_mlx_put_image_to_window(
	t_vars *vars, int save_flag);

#endif
