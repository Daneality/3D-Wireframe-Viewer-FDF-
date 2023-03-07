/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:14:04 by dsas              #+#    #+#             */
/*   Updated: 2023/03/07 19:54:03 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	mous_press(int button, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	if (button == 4 || button == 5)
		zoom_key(button, data);
	else if (button == 1)
		data->mouse->is_pressed = True;
	return (0);
}

int	mous_release(int button, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	(void)button;
	data->mouse->is_pressed = False;
	return (0);
}

int	mous_move(int x, int y, t_fdf *data)
{
	data->mouse->previous_x = data->mouse->x;
	data->mouse->previous_y = data->mouse->y;
	data->mouse->x = x;
	data->mouse->y = y;
	if (data->mouse->is_pressed == True)
	{
		data->x_angle += (data->mouse->previous_x - data->mouse->x) * 0.002;
		data->y_angle += (data->mouse->previous_y - data->mouse->y) * 0.002;
		draw_map(data);
	}
	return (0);
}
