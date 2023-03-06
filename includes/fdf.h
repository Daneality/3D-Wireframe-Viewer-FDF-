/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:18:01 by dsas              #+#    #+#             */
/*   Updated: 2023/03/06 17:51:29 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include <stddef.h>

typedef enum Bool
{
	False,
	True
}					t_bool;

typedef struct s_mouse
{
	t_bool				is_pressed;
	int					x;
	int					y;
	int					previous_x;
	int					previous_y;
}						t_mouse;

typedef struct s_fdf
{
	void	*mxl;
	void	*mlx_win;
	int		**matrix;
	int		**color_matrix;
	int		width;
	int		height;

	float	zoom;
	float	angle;
	t_bool	project;
	float	zoom_height;
	int		color;
	int		y_start_point;
	int		x_start_point;
	int		constant;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		x;
	int		y;
	int		x1;
	int		y1;
	int		z;
	int		z1;
	double	z_angle;
	double	y_angle;
	double	x_angle;

	int		win_width;
	int		win_height;
	t_mouse	*mouse;
}			fdf;

void	my_mlx_pixel_put(fdf *data, int x, int y, int color);
void	fill(int x, int y, fdf *data);
void	free_2dstring(int **matrix, fdf *data);
int		**fill_matrix(int height, int width);
int		**get_map(char *name, fdf *data);
int		get_color(char *temp);
void	color(fdf *data);


#endif