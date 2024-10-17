/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:39:22 by ycantin           #+#    #+#             */
/*   Updated: 2024/10/17 20:51:51 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	initiate_structure(t_fdf *data)
{
	img_placeholder(data);
	grid(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	write_menu(data);
}

int	escape_hook(int key, t_fdf *data)
{
	if (key == XK_ESCAPE)
	{
		if (!data->key)
			data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		destroy(data);
	}
	return (key);
}

int	hook(int key, t_fdf *data)
{
	if (data->key == 0 && key == XK_RETURN)
	{
		data->key = 1;
		initiate_structure(data);
	}
	if (data->height && data->width)
	{
		if (data->key == 1 && (key == XK_A || key == XK_D || key == XK_W
				|| key == XK_S))
			translate(key, data);
		else if (data->key == 1 && (key == XK_N || key == XK_M))
			zoom(key, data);
		else if (data->key == 1 && (key == XK_P || key == XK_O || key == XK_K
				|| key == XK_L || key == XK_I))
			rotate(key, data);
		else if (data->key == 1 && key == XK_R)
			reset(data);
		else if (data->key == 1 && key == XK_T)
			independent(data, key);
		else if (data->key == 1 && (key == XK_G || key == XK_H || key == XK_J))
			themes(data, key);
	}
	escape_hook(key, data);
	return (key);
}
