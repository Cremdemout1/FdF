/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:44:46 by ycantin           #+#    #+#             */
/*   Updated: 2024/06/23 11:39:47 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_window(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fil de fer");
	data->morph.zoom = (WIDTH / data->width) / 3;
	data->morph.offset_x = (WIDTH - data->width) / 2;
	data->morph.offset_y = (HEIGHT - data->width) / 2;
	data->morph.rotate_x = 1.5;
	data->morph.rotate_y = 1.5;
	data->morph.rotate_z = M_PI;
	data->angle = 0.5;
	data->theme.base = 0xffffff;
	data->theme.add_on = 0x000000;
}

int	destroy_data(t_fdf *data)
{
	destroy(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	data;
	int		fd;

	if (argc != 2)
		return (1);
	data.key = 0;
	fd = open(argv[1], O_RDONLY);
	if (arg_validity(argv[1]) == 0 || fd < 1)
	{
		write(1, "file not found\n", 16);
		exit(1);
	}
	close(fd);
	read_map(&data, argv[1]);
	init_window(&data);
	mlx_hook(data.win_ptr, 2, (1L << 0), hook, &data);
	mlx_hook(data.win_ptr, 17, 0, destroy_data, &data);
	mlx_loop(data.mlx_ptr);
}
