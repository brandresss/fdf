/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <brandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:47:55 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/05 21:46:44 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    change_angle(t_fdf *data, int key)
{
    float   step;

    step = 0.1;
    if (data->angle == -1)
        data->angle = 360;
    if (data->angle == 361)
        data->angle = 0;
    if (key == 5)
    {
        data->angle -= step;
    }
    if (key == 4)
    {
        data->angle += step;
    }
}

void    isom(t_fdf *data, int key)
{
    if (data->isom == 0)
        data->isom = 1;
    else
        data->isom = 0;
}

void	zooom(t_fdf *data, int key)
{
	int	step;

	step = data->zoom / 2;
	if (step == 0)
		step = 1;
	if (key == 6 && (data->zoom - step > 0))
		data->zoom -= step;
	if (key == 7 && (data->zoom + step < 1500))
		data->zoom += step;
	//printf("%d %d\n", data->zoom, step);
}

void	change_z(t_fdf *data,int key)
{
	int	step;

	step = 1;
	if (key == 29)
		data->chchchaaanges *= -1;
	if (key == 24 && data->chchchaaanges < 100)
		data->chchchaaanges += step;
	if (key == 27 && data && data->chchchaaanges > -100)
		data->chchchaaanges -= step;
}

void rotate(int key, t_fdf *data)
{
    if (key == 26)
    {
        rotation_x(&data->y, &data->z, data->alpha);
        data->alpha += 0.1;
    }
    if (key == 28)
    {
        rotation_y(&data->x, &data->z, data->beta);
        data->beta += 0.1;    
    }
    if (key == 25)
    {
        rotation_z(&data->x, &data->y, data->gamma);
        data->gamma += 0.1;
    } 
}

int    deal_key(int key, t_fdf *data)
{
    printf("%d\n", key);
    if (key == 126 && data->shift_y > -5000)
        data->shift_y -= 10;
    if (key == 125 && data->shift_y < 5000)
        data->shift_y += 10;
    if (key == 123 && data->shift_x > -5000)
        data->shift_x -= 10;
    if (key == 124 && data->shift_x < 5000)
        data->shift_x += 10;
    if (key == 18 || key == 19 || (key >= 20 && key<= 26) || key == 28 || key == 29)
        change_colors(key, data);
	if (key == 6 || key == 7)
		zooom(data, key);
	if (key == 29 || key == 27 || key == 24)
		change_z(data, key);
    if (key == 34)
        isom(data, key);
    if (key == 5 || key == 4)
        change_angle(data, key);
    if (key == 53)
        exit(1);
    if (key == 26 || key == 28 || key == 25)
        rotate(key, data);
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    draw(data);
    return (0);
}