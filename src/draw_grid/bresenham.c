/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:04:59 by ycantin           #+#    #+#             */
/*   Updated: 2024/06/19 19:33:02 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	mod(int diff)
{
	if (diff < 0)
		return (-diff);
	else
		return (diff);
}

int	compare(int c, int c1)
{
	if (c < c1)
		return (1);
	else
		return (-1);
}

void	give_breseham(t_fdf *data)
{
	data->b.modified_dx = mod(data->line.dx);
	data->b.modified_dy = mod(data->line.dy);
	data->b.mv_dir_x = compare(data->line.x, data->line.x1);
	data->b.mv_dir_y = compare(data->line.y, data->line.y1);
	if (data->b.modified_dx > data->b.modified_dy)
		data->b.dtrmd = data->b.modified_dx / 2;
	else
		data->b.dtrmd = -data->b.modified_dy / 2;
}

void	my_bresenham(t_fdf *data)
{
	int	x;
	int	y;

	give_breseham(data);
	x = data->line.x;
	y = data->line.y;
	while (x < WIDTH && y < HEIGHT)
	{
		image_pixel_placement(data, x, y, data->line.color);
		if (x == data->line.x1 && y == data->line.y1)
			break ;
		data->b.holder = data->b.dtrmd;
		if (data->b.holder > -(data->b.modified_dx))
		{
			data->b.dtrmd -= data->b.modified_dy;
			x += data->b.mv_dir_x;
		}
		if (data->b.holder < data->b.modified_dy)
		{
			data->b.dtrmd += data->b.modified_dx;
			y += data->b.mv_dir_y;
		}
	}
}
