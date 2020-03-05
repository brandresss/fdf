/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sonya.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <brandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:49:44 by brandres          #+#    #+#             */
/*   Updated: 2020/03/05 21:18:33 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_fdf *data)
{
	int		y;

	y = 0;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 65, y += 20, 0xFFFFFF, "How to Use");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 35, 0xFFFFFF, "Zoom: z/x");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF, "Move: Arrows");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF, "Flatten: </>");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF, "Rotate: Press & Move");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF, "Rotate:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, 0xFFFFFF, "X-Axis - 7");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, 0xFFFFFF, "Y-Axis - 8");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, 0xFFFFFF, "Z-Axis - 9");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, 0xFFFFFF, "Projection");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, 0xFFFFFF, "ISO: I Key");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, 0xFFFFFF, "Parallel: I Key");

}

void	rotation_x(int *y, int *z, double alpha)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	rotation_y(int *x, int *z, double beta)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void	rotation_z(int *x, int *y, double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}