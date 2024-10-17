/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:08:21 by ycantin           #+#    #+#             */
/*   Updated: 2024/10/09 14:52:54 by ycantin          ###   ########.fr       */
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
}

void zoom(int key, t_fdf *data)
{
	unsigned long long max;
	unsigned long long cur;

	max = 10000;

    if (data->img_ptr)
        mlx_destroy_image(data->mlx_ptr, data->img_ptr);
    
    // Update zoom factor
    if (key == XK_M)
        data->morph.zoom *= 1.1; // Use a slightly smaller increment for smoother zooming
    else if (key == XK_N)
	{
        data->morph.zoom /= 1.1; // Use a slightly smaller decrement for smoother zooming
	}
	
	cur = data->height * data->width;
	if (cur <= max)
		data->lod_level = 1;
	else
    {
	 	if (data->morph.zoom < 3)
    	    data->lod_level = 1;  // Render everything
    	else if (data->morph.zoom < 6)
    	    data->lod_level = 2;  // Skip some points
    	else if (data->morph.zoom < 9)
    	    data->lod_level = 3;  // Skip more points
    	else
    	    data->lod_level = 4;  // Render minimal details
	}
    initiate_structure(data);  // Re-render with updated LOD
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





//void	rotate(int key, t_fdf *data)
// {
// 	if (data->img_ptr)
// 		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
// 	if (key == XK_P)
// 		data->morph.rotate_x += 0.01;
// 	else if (key == XK_O)
// 		data->morph.rotate_x -= 0.01;
// 	else if (key == XK_K)
// 		data->morph.rotate_y += 0.01;
// 	else if (key == XK_L)
// 		data->morph.rotate_y -= 0.01;
// 	initiate_structure(data);
// }
void	rotate(int key, t_fdf *data)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);

	// Update rotation based on the key pressed
	if (key == XK_P)
		data->morph.rotate_x += 0.01 * data->lod_level;  // Adjust rotation rate by LOD
	else if (key == XK_O)
		data->morph.rotate_x -= 0.01 * data->lod_level;
	else if (key == XK_K)
		data->morph.rotate_y += 0.01 * data->lod_level;
	else if (key == XK_L)
		data->morph.rotate_y -= 0.01 * data->lod_level;

	initiate_structure(data);  // Re-render with new rotation angles
}

void	reset(t_fdf *data)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->morph.zoom = (WIDTH / data->width) / 3;  // Set default zoom
	data->morph.rotate_x = 0;  // Reset rotation on X-axis
	data->morph.rotate_y = 0;  // Reset rotation on Y-axis
	int iso_center_x = (data->width * data->morph.zoom) / 2;
	int iso_center_y = (data->height * data->morph.zoom) / 2;

	// Set initial offsets based on the isometric center
	data->morph.offset_x = (WIDTH / 2) - iso_center_x;
	data->morph.offset_y = (HEIGHT / 2) - iso_center_y;

	unsigned long long max;
	unsigned long long cur;

	max = 10000;
	cur = data->height * data->width;

	if (cur <= max)
		data->lod_level = 1;
	else
    {
	 	if (data->morph.zoom < 3)
    	    data->lod_level = 1;  // Render everything
    	else if (data->morph.zoom < 6)
    	    data->lod_level = 2;  // Skip some points
    	else if (data->morph.zoom < 9)
    	    data->lod_level = 3;  // Skip more points
    	else
    	    data->lod_level = 4;  // Render minimal details
	}
	initiate_structure(data);  // Re-render with updated settings
}

