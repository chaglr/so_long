/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:00:53 by muhnal            #+#    #+#             */
/*   Updated: 2023/06/20 18:47:44 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** read_file_and_count_blocks - Read the content of a file and count the number
** of 'C' characters.
**
** @path: The path of the file to read.
** @map: A pointer to a t_level structure to store the count of 'C' characters.
**
** This function reads the content of the file at the specified path and
** returns it
** as a character string. At the same time, it counts the number of 'C' char.
** in the file and stores the count in the t_level structure pointed by 'map'.
**
** Return: A pointer to the character string containing the file content, or
** NULL on error.
*/

#include "so_long.h"

void	end_line(char line)
{
	if (line == '\n')
	{
		write(1, "Error\n", 6);
		write(1, "\nERROR! end_line(char line):\n", 29);
		write(1, "Map have empty line\n", 20);
		exit(1);
	}
}

char	*read_map_count_coins(char *path, t_level *map)
{
	char	*line;
	char	*content;
	int		fd;
	int		i;

	i = -1;
	fd = open(path, O_RDONLY);
	content = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		end_line(line[0]);
		while (line[++i])
		{
			if (line[i] == 'C')
				map->t_c = map->t_c + 1;
		}
		i = -1;
		str_j_f(&content, line);
		free(line);
	}
	close(fd);
	return (content);
}

t_level	*load_map(char *path)
{
	t_level	*map;
	char	*content;

	map = ft_calloc(1, sizeof(t_level));
	if (!map)
		return (NULL);
	content = read_map_count_coins(path, map);
	map->data = ft_split(content, '\n');
	while (map->data[map->h])
		map->h++;
	map->w = ft_strlen(map->data[0]);
	free(content);
	return (map);
}

void	file_control(char *path)
{
	int		fd;
	char	buffer[1];

	fd = open(path, O_RDWR);
	if (fd <= 0)
	{
		write(1, "Error\n", 6);
		write(1, "ERROR! map.c: Wrong File Path", 29);
		close(fd);
		exit(1);
	}
	if (read(fd, buffer, sizeof(buffer)) == 0)
	{
		write(1, "Error\n", 6);
		write(1, "\nERROR! map.c : Empty File\n", 27);
		close(fd);
		exit(1);
	}
	close(fd);
}
