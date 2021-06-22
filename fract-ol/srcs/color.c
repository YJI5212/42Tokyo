#include "fractol.h"

int	color_calc(t_info *info)
{
	t_hsv	color_hsv;
	t_rgb	color_rgb;
	double	per;

	per = (double)info->depth / info->max;
	color_hsv = (t_hsv) {.h = per * 360, .s = 1, .v = 1};
	hsv2rgb(color_hsv, &color_rgb);
	return (rgb2hex(color_rgb));
}

void	hsv2rgb(t_hsv hsv, t_rgb *rgb)
{
	int	max, min;

	max = hsv.v;
	min = max - ((hsv.s / 255) * max);
	hsv2rgb_sub1(hsv, rgb, max, min);
	hsv2rgb_sub2(hsv, rgb, max, min);
}

void	hsv2rgb_sub1(t_hsv hsv, t_rgb *rgb, int max, int min)
{
	if (0 <= hsv.h && hsv.h < 60)
	{
		rgb->r = 255;
		rgb->g = (hsv.h / 60) * (max - min) + min;
		rgb->b = min;
	}
	if (60 <= hsv.h && hsv.h < 120)
	{
		rgb->r = ((120 - hsv.h) / 60) * (max - min) + min;
		rgb->g = max;
		rgb->b = min;
	}
	if (120 <= hsv.h && hsv.h < 180)
	{
		rgb->r = min;
		rgb->g = max;
		rgb->b = ((hsv.h - 120) / 60) * (max - min) + min;
	}
}

void	hsv2rgb_sub2(t_hsv hsv, t_rgb *rgb, int max, int min)
{
	if (180 <= hsv.h && hsv.h < 240)
	{
		rgb->r = min;
		rgb->g = ((240 - hsv.h) / 60) * (max - min) + min;
		rgb->b = max;
	}
	if (240 <= hsv.h && hsv.h < 300)
	{
		rgb->r = ((hsv.h - 240) / 60) * (max - min) + min;
		rgb->g = min;
		rgb->b = max;
	}
	if (300 <= hsv.h && hsv.h < 360)
	{
		rgb->r = max;
		rgb->g = min;
		rgb->b = ((360 - hsv.h) / 60) * (max - min) + min;
	}
}

int	rgb2hex(t_rgb rgb)
{
	int ret_r, ret_g, ret_b;

	ret_r = (rgb.r / 16) * (int)pow(16, 5) + (rgb.r % 16) * (int)pow(16, 4);
	ret_g = (rgb.g / 16) * (int)pow(16, 3) + (rgb.g % 16) * (int)pow(16, 2);
	ret_b = (rgb.b / 16) * (int)pow(16, 1) + (rgb.b % 16) * (int)pow(16, 0);
	return (ret_r + ret_g + ret_b);
}
