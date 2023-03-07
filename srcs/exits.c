/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:17:47 by dsas              #+#    #+#             */
/*   Updated: 2023/03/07 19:50:04 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(0);
	return (1);
}

int	escape(t_fdf *data)
{
	mlx_destroy_window(data->mxl, data->mlx_win);
	mlx_destroy_image(data->mxl, data->img);
	if (data->matrix)
		free_2dstring(data->matrix, data);
	if (data->color_matrix)
		free_2dstring(data->color_matrix, data);
	free(data->mouse);
	free(data);
	exit(1);
}
