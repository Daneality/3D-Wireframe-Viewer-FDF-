/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:20:49 by dsas              #+#    #+#             */
/*   Updated: 2023/03/07 19:42:44 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	inititialize_win(fdf *data)
{
	data->win_width = 2000;
	data->win_height = 1000;
	data->angle = 0.9;
	data->zoom_height = 1;
	data->project = True;
	data->constant = 1;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->mxl = mlx_init();
	data->mlx_win = mlx_new_window(data->mxl, \
	data->win_width, data->win_height, "FDF");
	data->img = mlx_new_image(data->mxl, data->win_width, data->win_height);
	data->addr = mlx_get_data_addr(data->img, \
	&data->bits_per_pixel, &data->line_length, &data->endian);
	if (data->win_width > data->win_height)
		data->constant = data->win_width / data->win_height;
	data->zoom = data->win_width / data->width / 1.5 / data->constant;
	data->x_start_point = data->win_width / 2 - data->width / 3;
	data->y_start_point = data->win_height / 2 - data->height / 3 * data->zoom;
}

int	main(int argc, char *argv[])
{
	fdf	*data;

	if (argc != 2)
		error("invalid number of arguments\n");
	data = (fdf *)ft_calloc(1, (sizeof(fdf)));
	if (!data)
		return (0);
	data->mouse = (t_mouse *)ft_calloc(1, (sizeof(t_mouse)));
	get_map(argv[1], data);
	inititialize_win(data);
	draw_map(data);
	mlx_hook(data->mlx_win, 2, 0, key, data);
	mlx_hook(data->mlx_win, 17, 0, escape, data);
	mlx_hook(data->mlx_win, 4, 0, mous_press, data);
	mlx_hook(data->mlx_win, 5, 0, mous_release, data);
	mlx_hook(data->mlx_win, 6, 0, mous_move, data);
	mlx_loop(data->mxl);
	return (0);
}
