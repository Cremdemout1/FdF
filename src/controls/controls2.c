/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:43:51 by ycantin           #+#    #+#             */
/*   Updated: 2024/10/17 20:25:27 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	destroy(t_fdf *data)
{
	int	i;

	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	if (data->z_matrix)
	{
		i = 0;
		while (i < data->height)
		{
			free(data->z_matrix[i]);
			i++;
		}
		free(data->z_matrix);
	}
	exit(0);
}

void	independent(t_fdf *data, int key)
{
	int	i;

	i = 0;
	if (key == XK_T)
	{
		while (i < 500)
		{
			data->morph.rotate_x += 0.005;
			data->morph.offset_x += 1;
			data->morph.rotate_y += 0.004;
			data->morph.offset_x -= 1;
			data->morph.offset_y -= 1;
			if (data->img_ptr)
				mlx_destroy_image(data->mlx_ptr, data->img_ptr);
			initiate_structure(data);
			i++;
		}
	}
}

void	themes(t_fdf *data, int key)
{
	if (key == XK_G)
	{
		if (data->img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		data->theme.base = Y_BASE;
		data->theme.add_on = Y_ADD;
		initiate_structure(data);
	}
	else if (key == XK_H)
	{
		if (data->img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		data->theme.base = B_BASE;
		data->theme.add_on = B_ADD;
		initiate_structure(data);
	}
	else if (key == XK_J)
	{
		if (data->img_ptr)
			mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		data->theme.base = R_BASE;
		data->theme.add_on = R_ADD;
		initiate_structure(data);
	}
}

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
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 210, c,
		"RESET:    r");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 240, c,
		"ENDLESS ROT:     t");
}
