/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:52:05 by ycantin           #+#    #+#             */
/*   Updated: 2024/07/12 13:59:13 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric(t_fdf *data, int *x, int *y, int z)
{
	double	tx;
	double	ty;

	rotate_z(data, x, y, &z);
	rotate_x(data, x, y, &z);
	rotate_y(data, x, y, &z);
	tx = (*x - *y) * cos(data->angle);
	ty = (*x + *y) * sin(data->angle) - z;
	*x = (int)tx;
	*y = (int)ty;
}

void	rotate_x(t_fdf *data, int *x, int *y, int *z)
{
	int	temp_y;
	int	temp_z;

	temp_y = *y;
	temp_z = *z;
	*x = *x;
	*y = temp_y * cos(data->morph.rotate_x) - temp_z
		* sin(data->morph.rotate_x);
	*z = temp_y * sin(data->morph.rotate_x) + temp_z
		* cos(data->morph.rotate_x);
}

void	rotate_y(t_fdf *data, int *x, int *y, int *z)
{
	int	temp_x;
	int	temp_z;

	temp_x = *x;
	temp_z = *z;
	*x = temp_x * cos(data->morph.rotate_y) + temp_z
		* sin(data->morph.rotate_y);
	*y = *y;
	*z = temp_x * -sin(data->morph.rotate_y) + temp_z
		* cos(data->morph.rotate_y);
}

void	rotate_z(t_fdf *data, int *x, int *y, int *z)
{
	int	temp_x;
	int	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = temp_x * cos(data->morph.rotate_z) - temp_y
		* sin(data->morph.rotate_z);
	*y = temp_x * sin(data->morph.rotate_z) + temp_y
		* cos(data->morph.rotate_z);
	*z = *z;
}
