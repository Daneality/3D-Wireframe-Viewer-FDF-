/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:55:07 by dsas              #+#    #+#             */
/*   Updated: 2023/03/07 19:57:26 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(t_fdf *data)
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

void	draw_map(t_fdf *data)
{
	int	x;
	int	y;

	if (data->img)
	{
		mlx_destroy_image(data->mxl, data->img);
		data->img = mlx_new_image(data->mxl, data->win_width, data->win_height);
	}
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				isometric_x(x, y, data);
			if (y < data->height - 1)
				isometric_y(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mxl, data->mlx_win, data->img, 0, 0);
}
