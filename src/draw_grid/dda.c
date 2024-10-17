/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:00:01 by ycantin           #+#    #+#             */
/*   Updated: 2024/06/23 11:37:58 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	absolute(int i)
{
	if (i >= 0)
		return (i);
	else
		return (i *= -1);
}

float	bigger(float dx, float dy)
{
	if (dx > dy)
		return (dx);
	else
		return (dy);
}

// void	dda(t_fdf *data)
// {
// 	int		steps;
// 	int		i;
// 	float	x;
// 	float	y;
// 	float	incx;
// 	float	incy;

// 	steps = bigger(fabs(data->line.dx), fabs(data->line.dy));
// 	x = data->line.x;
// 	y = data->line.y;
// 	incx = data->line.dx / steps;
// 	incy = data->line.dy / steps;
// 	i = 0;
// 	while (i < steps)
// 	{
// 		image_pixel_placement(data, x, y, data->line.color);
// 		x += incx;
// 		y += incy;
// 		i++;
// 	}
// }
