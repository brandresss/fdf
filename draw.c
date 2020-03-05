/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <brandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:09:09 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/05 21:47:50 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

//#define MAX(a, b) (a > b ? a : b)
//#define MOD(a) (a < 0) ? -a : a

int		maxn(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		minn(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		modn(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

void	isometric(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	ttt(t_fdf *data, float *x, float *y, int *z)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(data->alpha) + *z * sin(data->alpha);
	*z = -previous_y * sin(data->alpha) + *z * cos(data->alpha);
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	printf("x:%d y:%d z:%d\n", data->x, data->y, data->z);
	printf("a:%f b:%f g:%f\n", data->alpha, data->beta, data->gamma);
	z = data->z_matrix[(int)y][(int)x] * data->chchchaaanges;
	z1 = data->z_matrix[(int)y1][(int)x1] * data->chchchaaanges;

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	data->color = (z || z1) ? data->color1 : data->color2;
	if (data->isom)
	{
		isometric(&x, &y, z, data->angle);
		isometric(&x1, &y1, z1, data->angle);
	}
	
	else
	{
		ttt(data, &x, &y, &z);
	}
	
	
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;

	x_step = x1 - x;
	y_step = y1 - y;
	max = maxn(modn(x_step), modn(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
  {
	 // int	x;
	 // int	y;

	  data->y = 0;
	  while(data->y < data->height)
	  {
		  data->x = 0;
		  while(data->x < data->width)
		  {
			if (data->x < data->width - 1)
				bresenham(data->x, data->y, data->x + 1, data->y, data);
			if (data->y < data->height - 1)
				bresenham(data->x, data->y, data->x, data->y + 1, data);
			data->x++;
		  }
		  data->y++;
	  }
	  print_menu(data);
  }