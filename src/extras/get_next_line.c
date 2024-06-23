/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:05:00 by ycantin           #+#    #+#             */
/*   Updated: 2024/06/23 11:35:58 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

char	*static_fix(char *line)
{
	char	*temp;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (*line == '\0')
		return (NULL);
	temp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*temp == '\0')
	{
		free(temp);
		temp = NULL;
	}
	else
		line[i + 1] = '\0';
	return (temp);
}

char	*read_file(int fd, char *buffer, char *held)
{
	char	*temp;
	int		readed;

	readed = 1;
	while (readed != '\0')
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
			return (NULL);
		if (readed == 0)
			break ;
		buffer[readed] = '\0';
		if (held == NULL)
			held = ft_strdup("");
		temp = held;
		held = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (held);
}

char	*get_next_line(int fd)
{
	static char	*held;
	char		*buffer;
	char		*line;

	if (BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	line = read_file(fd, buffer, held);
	free(buffer);
	if (line == NULL)
	{
		free(held);
		held = NULL;
		return (NULL);
	}
	held = static_fix(line);
	return (line);
}
