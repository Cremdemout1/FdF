/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:46:00 by ycantin           #+#    #+#             */
/*   Updated: 2024/06/23 11:47:49 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// int separate_color(t_fdf *data, char *str, int y, int x)
// {
//     int i;
//     char **separated;
//     int new;

//     i = 0;
//     while (str[i])
//     {
//         if (str[i] == ',')
//         {
//             separated = ft_split(str, ',');
//             data->colors[y][x] = ft_atoi_basesixteen(separated[1]);
//             new = ft_atoi(separated[0]);
//             free_str_array(separated);
//             return (new);
//         }
//         i++;
//     }
//     data->colors[y][x] = 0xffffff;
//     return (ft_atoi(str));
// }

void	find_dimensions(t_fdf *data, char *file)
{
	int		fd;
	int		x;
	int		y;
	char	*line;

	fd = open(file, O_RDONLY);
	x = 0;
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (y == 0)
		{
			x = ft_count_words(line, ' ');
			data->width = x;
		}
		free(line);
		y++;
	}
	close(fd);
	data->height = y;
}

void	assign_z(t_fdf *data, char *file)
{
	int		fd;
	int		x;
	int		i;
	char	*line;
	char	**array;

	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		x = 0;
		array = ft_split(line, ' ');
		free(line);
		while (array[x] && x < data->width)
		{
			data->z_matrix[i][x] = ft_atoi(array[x]);
			x++;
		}
		free_str_array(array);
		i++;
	}
}
			/* separate_color(data, array[x], i, x) */
			// if (data->z_matrix[i][x] > data->max)
			//     data->max = data->z_matrix[i][x];
			// if (data->z_matrix[i][x] < data->min)
			//     data->min = data->z_matrix[i][x];

void	read_map(t_fdf *data, char *filename)
{
	int	i;

	i = 0;
	find_dimensions(data, filename);
	data->z_matrix = malloc(sizeof(int *) * data->height);
	while (i < data->height)
	{
		data->z_matrix[i] = malloc(sizeof(int) * data->width);
		i++;
	}
	assign_z(data, filename);
}
// data->colors = malloc (sizeof (int*) * data->height);
// data->colors[i] = malloc (sizeof(int) * data->width);
