/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_coords.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:28:55 by ycantin           #+#    #+#             */
/*   Updated: 2024/10/09 14:44:52 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	img_placeholder(t_fdf *data)
{
	data->image.bits_per_pixel = 32;
	data->image.line_len = WIDTH * 4;
	data->image.endian = 0;
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->image.img_pixel_ptr = mlx_get_data_addr(data->img_ptr,
			&data->image.bits_per_pixel, &data->image.line_len,
			&data->image.endian);
}

// void	transform(t_fdf *data, int *x, int *y)
// {
// 	int	iso_x;
// 	int	iso_y;
// 	int	iso_x1;
// 	int	iso_y1;

// 	iso_x = x[0] * data->morph.zoom;
// 	iso_x1 = x[1] * data->morph.zoom;
// 	iso_y = y[0] * data->morph.zoom;
// 	iso_y1 = y[1] * data->morph.zoom;
// 	isometric(data, &iso_x, &iso_y, data->z_matrix[y[0]][x[0]]);
// 	isometric(data, &iso_x1, &iso_y1, data->z_matrix[y[1]][x[1]]);
// 	data->line.x = iso_x + data->morph.offset_x;
// 	data->line.x1 = iso_x1 + data->morph.offset_x;
// 	data->line.y = iso_y + data->morph.offset_y;
// 	data->line.y1 = iso_y1 + data->morph.offset_y;
// 	data->line.dx = (iso_x1 - iso_x);
// 	data->line.dy = (iso_y1 - iso_y);
// 	data->line.color = data->theme.base + data->theme.add_on
// 		* data->z_matrix[y[0]][x[0]];
// }

void	transform(t_fdf *data, int *x, int *y)
{
	int	iso_x;
	int	iso_y;
	int	iso_x1;
	int	iso_y1;

	// Apply zoom and isometric transformations
	iso_x = x[0] * data->morph.zoom;
	iso_x1 = x[1] * data->morph.zoom;
	iso_y = y[0] * data->morph.zoom;
	iso_y1 = y[1] * data->morph.zoom;

	// Apply isometric projection
	isometric(data, &iso_x, &iso_y, data->z_matrix[y[0]][x[0]]);
	isometric(data, &iso_x1, &iso_y1, data->z_matrix[y[1]][x[1]]);

	// Apply offsets after transformations
	data->line.x = iso_x + data->morph.offset_x;
	data->line.x1 = iso_x1 + data->morph.offset_x;
	data->line.y = iso_y + data->morph.offset_y;
	data->line.y1 = iso_y1 + data->morph.offset_y;

	// Calculate deltas for drawing
	data->line.dx = (iso_x1 - iso_x);
	data->line.dy = (iso_y1 - iso_y);

	// Adjust color based on height
	data->line.color = data->theme.base + data->theme.add_on
		* data->z_matrix[y[0]][x[0]];
}

