/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:55:07 by dsas              #+#    #+#             */
/*   Updated: 2023/03/06 18:02:32 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(fdf *data)
{
	float	x_step;
	float	y_step;
	float	x;
	float	y;
	int		max;

	x = (float)data->x;
	y = (float)data->y;
	x_step = (int)data->x1 - x;
	y_step = (int)data->y1 - y;
	if (fabsf(x_step) >= fabsf(y_step))
		max = (int)fabsf(x_step);
	else
		max = (int)fabsf(y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(x - data->x1) || (int)(y - data->y1))
	{
		my_mlx_pixel_put(data, (data->x_start_point + x), \
					(data->y_start_point + y), data->color);
		x += x_step;
		y += y_step;
	} 
}

