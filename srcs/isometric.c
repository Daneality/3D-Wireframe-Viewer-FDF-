/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:48:51 by dsas              #+#    #+#             */
/*   Updated: 2023/03/07 19:39:56 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	xy_isometric(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.9);
	*y = (*x + *y) * sin(0.9) - z;
}

void	isometric_x(int x, int y, fdf *data)
{
	fill(x, y, data);
	data->x1 = x + 1;
	data->y1 = y;
	color(data);
	data->x *= data->zoom;
	data->x1 *= data->zoom;
	data->y *= data->zoom;
	data->y1 *= data->zoom;
	data->z *= data->zoom_height;
	data->z1 *= data->zoom_height;
	rotate_x(&data->y, &data->z, data->x_angle);
	rotate_x(&data->y1, &data->z1, data->x_angle);
	rotate_y(&data->x, &data->z, data->y_angle);
	rotate_y(&data->x1, &data->z1, data->y_angle);
	rotate_z(&data->x, &data->y, data->z_angle);
	rotate_z(&data->x1, &data->y1, data->z_angle);
	if (data->project == True)
	{
		xy_isometric(&data->x, &data->y, data->z);
		xy_isometric(&data->x1, &data->y1, data->z1);
	}
	draw_line(data);
}

void	isometric_y(int x, int y, fdf *data)
{
	fill(x, y, data);
	data->y1 = y + 1;
	data->x1 = x;
	color(data);
	data->x *= data->zoom;
	data->x1 *= data->zoom;
	data->y *= data->zoom;
	data->y1 *= data->zoom;
	data->z *= data->zoom_height;
	data->z1 *= data->zoom_height;
	rotate_x(&data->y, &data->z, data->x_angle);
	rotate_x(&data->y1, &data->z1, data->x_angle);
	rotate_y(&data->x, &data->z, data->y_angle);
	rotate_y(&data->x1, &data->z1, data->y_angle);
	rotate_z(&data->x, &data->y, data->z_angle);
	rotate_z(&data->x1, &data->y1, data->z_angle);
	if (data->project == True)
	{
		xy_isometric(&data->x, &data->y, data->z);
		xy_isometric(&data->x1, &data->y1, data->z1);
	}
	draw_line(data);
}
