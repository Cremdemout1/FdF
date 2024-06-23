/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:08:21 by ycantin           #+#    #+#             */
/*   Updated: 2024/06/23 11:38:48 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	write_menu(t_fdf *data)
{
	int	c;

	c = 0xafafad;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 30, c, "CONTROL MENU:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 60, c,
		"START:           enter");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 90, c,
		"TRANSLATE MODEL: w   a   s   d");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 120, c,
		"ROTATE MODEL:    o   p   k   l");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 150, c,
		"ZOOM IN/OUT:     m  n");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 180, c,
		"ISOMETRIC:       i");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 210, c,
		"NATURAL VIEW:    r");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 240, c,
		"ENDLESS ROT:     t");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 270, c,
		"ESCAPE ROT:      y");
}

void	zoom(int key, t_fdf *data)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (key == XK_M && data->morph.zoom < 1000)
		data->morph.zoom *= 1.2;
	if (key == XK_N && data->morph.zoom / 1.2 > 4)
		data->morph.zoom /= 1.2;
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
		data->morph.rotate_x += 0.01;
	else if (key == XK_O)
		data->morph.rotate_x -= 0.01;
	else if (key == XK_K)
		data->morph.rotate_y += 0.01;
	else if (key == XK_L)
		data->morph.rotate_y -= 0.01;
	initiate_structure(data);
}

void	reset(t_fdf *data)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->morph.zoom = (WIDTH / data->width) / 4;
	data->morph.rotate_x = 0;
	data->morph.rotate_y = 0;
	data->morph.offset_x = (WIDTH - data->width) / 2;
	data->morph.offset_y = (HEIGHT - data->height) / 2;
	initiate_structure(data);
}
