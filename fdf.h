/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandres <brandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:42:53 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/05 19:00:01 by brandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include "fcntl.h"
# include "sys/types.h"
# include "sys/uio.h"

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

# include <stdio.h>
# include <string.h>

//# define BUFF_SIZE  50

typedef struct  s_fdf
{
    int     width;
    int     height;
    int     zoom;
    int     color;
    int     color1;
    int     color2;
    int     shift_x;
    int     shift_y;
    int     **z_matrix;
    void    *mlx_ptr;
    void    *win_ptr;
    int     chchchaaanges;
    int     isom;
    float   angle;
    double  alpha;
    double  beta;
    double  gamma;
    int     x;
    int     y;
    int     z;
}               t_fdf;

void    read_file(char *file_name, t_fdf *data);
int	    get_next_line(const int fd, char **line);
int		counter(char *str, char c);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);
void    zooom(t_fdf *data, int key);
void    colors(int key, t_fdf *data);
int     deal_key(int key, t_fdf *data);
void    change_colors(int key, t_fdf *data);
int		minn(int a, int b);
void	print_menu(t_fdf *data);
void	rotation_x(int *y, int *z, double alpha);
void	rotation_y(int *x, int *z, double beta);
void	rotation_z(int *x, int *y, double gamma);

#endif