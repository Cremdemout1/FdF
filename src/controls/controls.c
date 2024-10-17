/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:50:59 by ycantin           #+#    #+#             */
/*   Updated: 2024/10/17 20:51:28 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	change_lvl_detail(t_fdf **data)
{
	unsigned long long	max;
	unsigned long long	cur;

	max = 10000;
	cur = (*data)->height * (*data)->width;
	if (cur <= max)
		(*data)->lod_level = 1;
	else
	{
		if ((*data)->morph.zoom < 3)
			(*data)->lod_level = 1;
		else if ((*data)->morph.zoom < 6)
			(*data)->lod_level = 2;
		else if ((*data)->morph.zoom < 9)
			(*data)->lod_level = 3;
		else
			(*data)->lod_level = 4;
	}
}

void	zoom(int key, t_fdf *data)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (key == XK_M)
	{
		if (data->morph.zoom < 100)
			data->morph.zoom *= 1.1;
	}
	else if (key == XK_N)
		data->morph.zoom /= 1.1;
	change_lvl_detail(&data);
	initiate_structure(data);
}

void	translate(int key, t_fdf *data)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (key == XK_A)
		data->morph.offset_x -= 10;
	if (key == XK_D)
		data->morph.offset_x += 10;
	if (key == XK_W)
		data->morph.offset_y -= 10;
	if (key == XK_S)
		data->morph.offset_y += 10;
	initiate_structure(data);
}

void	rotate(int key, t_fdf *data)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (key == XK_P)
		data->morph.rotate_x += 0.01 * data->lod_level;
	else if (key == XK_O)
		data->morph.rotate_x -= 0.01 * data->lod_level;
	else if (key == XK_K)
		data->morph.rotate_y += 0.01 * data->lod_level;
	else if (key == XK_L)
		data->morph.rotate_y -= 0.01 * data->lod_level;
	initiate_structure(data);
}

void	reset(t_fdf *data)
{
	int	iso_center_x;
	int	iso_center_y;

	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->morph.zoom = (WIDTH / data->width) / 3;
	data->morph.rotate_x = 0;
	data->morph.rotate_y = 0;
	iso_center_x = (data->width * data->morph.zoom) / 2;
	iso_center_y = (data->height * data->morph.zoom) / 2;
	data->morph.offset_x = (WIDTH / 2) - iso_center_x;
	data->morph.offset_y = (HEIGHT / 2) - iso_center_y;
	change_lvl_detail(&data);
	initiate_structure(data);
}
