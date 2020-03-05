/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:39:09 by ksenaida          #+#    #+#             */
/*   Updated: 2020/03/04 20:02:33 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void     change_colors(int key, t_fdf *data)
{
    if (key == 18)
    {
        data->color1 = 0xFFFFFF;
        data->color2 = 0xFFFFFF;
    }
    if (key == 19)
    {
        data->color1 = 0xFF8C00;
        data->color2 = 0x1E90FF;
    }
    if (key == 20)
    {
        data->color1 = 0x87CEEB;
        data->color2 = 0xFF1493;
    }
}