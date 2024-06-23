/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:35:36 by ycantin           #+#    #+#             */
/*   Updated: 2024/06/23 11:37:19 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	image_pixel_placement(t_fdf *data, int x, int y, int color)
{
	int	pixel;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		pixel = (y * data->image.line_len) + (x * (data->image.bits_per_pixel
					/ 8));
		*(unsigned int *)(pixel + data->image.img_pixel_ptr) = color;
	}
}

void	grid(t_fdf *data)
{
	draw_vertical(data);
	draw_horizontal(data);
}

void	draw_horizontal(t_fdf *data)
{
	int	x[2];
	int	y[2];

	y[0] = 0;
	while (y[0] < data->height)
	{
		x[0] = 0;
		while (x[0] < data->width - 1)
		{
			x[1] = x[0] + 1;
			y[1] = y[0];
			transform(data, x, y);
			my_bresenham(data);
			x[0]++;
		}
		y[0]++;
	}
}

void	draw_vertical(t_fdf *data)
{
	int	x[2];
	int	y[2];

	y[0] = 0;
	while (y[0] < data->height - 1)
	{
		x[0] = 0;
		while (x[0] < data->width)
		{
			x[1] = x[0];
			y[1] = y[0] + 1;
			transform(data, x, y);
			my_bresenham(data);
			x[0]++;
		}
		y[0]++;
	}
}
