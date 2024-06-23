/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:52:57 by ycantin           #+#    #+#             */
/*   Updated: 2024/06/23 11:36:33 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	free_str_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	arg_validity(char *argv)
{
	char	**file;
	int		i;

	file = ft_split(argv, '.');
	i = 0;
	while (file[i])
		i++;
	if (!file[1] || i > 2)
		return (free_str_array(file), 0);
	if (ft_strcmp(file[1], "fdf") == 0)
		return (free_str_array(file), 1);
	return (free_str_array(file), 0);
}

int	ft_count_words(const char *str, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	if (!str || !*str)
		return (0);
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] != c)
		{
			word_count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else if (str[i] == c)
			i++;
	}
	return (word_count);
}

int	ft_atoi_basesixteen(char *str)
{
	int	i;
	int	temp;
	int	result;

	i = 2;
	result = 0;
	while (str[i])
	{
		temp = 0;
		if (str[i] <= 'F' && str[i] >= 'A')
			temp = str[i] - 'A' + 10;
		else if (str[i] <= 'f' && str[i] >= 'a')
			temp = str[i] - 'a' + 10;
		else if (str[i] <= '9' && str[i] >= '0')
			temp = str[i] - '0';
		result *= 16;
		result += temp;
		i++;
	}
	return (result);
}
