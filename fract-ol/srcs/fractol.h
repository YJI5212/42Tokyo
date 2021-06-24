#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "mlx.h"

# ifdef __MACH__
#  define ESC 53
#  define CLOSE_BOTTON 17
# else
#  define ESC 0xff1b
#  define CLOSE_BOTTON 33
#endif

# define WIDTH	1200
# define HEIGHT	800
# define TITLE "fractol by yoinoue"

# define BLACK	0x000000
# define CRIMSON 0xDC143C

# define RED	"\x1b[31m"
# define GREEN	"\x1b[32m"
# define BLUE	"\x1b[34m"
# define RESET	"\x1b[39m"

enum e_name
{
	Mandelbrot,
	Julia
};

enum e_mouse
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	SCROLL_DOWN = 4,
	SCROLL_UP = 5
};

typedef struct s_cmp
{
	int	x;
	int	y;
}	t_cmp;

typedef struct s_cnb
{
	float	Re;
	float	Im;
}	t_cnb;

typedef struct s_hsv
{
	int	h;
	int	s;
	int	v;
}	t_hsv;

typedef struct s_rgb
{
	int r;
	int g;
	int b;
}	t_rgb;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_info
{
	enum e_name	name;

	void		*mlx;
	void		*win;

	t_image		img;
	int			color;

	float		zoom;

	t_cmp		cur;
	t_cmp		offset;
	int			max;
	t_cmp		min;
	int			depth;

	t_cnb		julia_c;
}	t_info;

/*
** my_mlx.c
*/
void	my_mlx_hook(t_info *info);
void	my_mlx_pixel_put(t_info *info, int x, int y, int color);
int		key_hook(int key, t_info *info);
int		zoom_hook(int button, int x, int y, t_info *info);
int		motion_hook(int x, int y, t_info *info);
int		close_hook(t_info *info);
/*
** init.c
*/
int		init_name(t_info *info, char *name);
int		init_vars(t_info *info);
void	init_img(t_info *info);
void	init_set_case(t_info *info);
/*
** fractol.c
*/
void	fractol(t_info *info);
void	draw(t_info *info);
/*
** mandelbrot.c
*/
void	make_mandelbrot(t_info *info, t_cnb z, t_cnb c);
/*
** julia.c
*/
void	set_julia_c(t_info *info);
void	make_julia(t_info *info, t_cnb z);
/*
** color.c
*/
int		color_calc(t_info *info);
void	hsv2rgb(t_hsv hsv, t_rgb *rgb);
void	hsv2rgb_sub1(t_hsv hsv, t_rgb *rgb, int max, int min);
void	hsv2rgb_sub2(t_hsv hsv, t_rgb *rgb, int max, int min);
int		rgb2hex(t_rgb rgb);

#endif
