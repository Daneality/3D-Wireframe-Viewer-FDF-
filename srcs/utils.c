/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:38:29 by dsas              #+#    #+#             */
/*   Updated: 2023/03/06 17:39:34 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x < data->win_width && y <= data->win_height && x > 0 && y > 0)
	{
		dst = data->addr + (y * data->line_length + \
					x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	fill(int x, int y, fdf *data)
{
	data->x = x;
	data->y = y;
}

void	free_2dstring(int **matrix, fdf *data)
{
	int	y;

	y = 0;
	while (y < data->height)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

int	**fill_matrix(int height, int width)
{
	int	i;
	int	**data;

	i = 0;
	data = (int **)ft_calloc(sizeof(int *), (height + 1));
	while (i < height)
	{
		data[i++] = (int *)ft_calloc(sizeof(int), (width + 1));
	}
	return (data);
}
