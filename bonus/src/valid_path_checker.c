/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:13:44 by muhnal            #+#    #+#             */
/*   Updated: 2023/07/07 18:02:43 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	malloc_flood_map(t_win *d, int fd)
{
	int		i;
	int		row;
	char	*line;

	i = 0;
	row = d->level->h + 1;
	d->level->flood_map = (char **)malloc(sizeof(char *) * row);
	if (!d->level->flood_map)
	{
		write(1, "Error\n", 6);
		write(1, "floormap Malloc error\n", 22);
		close_frame(d);
	}
	while (i < row)
	{
		line = get_next_line(fd);
		d->level->flood_map[i] = ft_strtrim(line, "\n");
		i++;
		free(line);
	}
}

bool	fill(t_win *d, char c, int line, int col)
{
	static bool	exit;
	static int	coin;

	if (line < 0 || col < 0 || line >= d->level->h || col >= d->level->w)
		return (false);
	else if (d->level->flood_map[line][col] == 'X')
		return (true);
	else if (d->level->flood_map[line][col] == '1' ||
			d->level->flood_map[line][col] == 'N')
		return (false);
	else if (d->level->flood_map[line][col] == 'E')
		exit = true;
	if (d->level->flood_map[line][col] == 'C')
		coin++;
	d->level->flood_map[line][col] = 'X';
	fill(d, c, line + 1, col);
	fill(d, c, line, col + 1);
	fill(d, c, line - 1, col);
	fill(d, c, line, col - 1);
	return (coin == d->level->t_c && exit);
}

int	flood_fill(t_win *d)
{
	int		line;
	int		column;
	bool	valid;
	char	start;

	start = d->level->data[d->player->start_y][d->player->start_x];
	line = d->player->start_y;
	column = d->player->start_x;
	valid = fill(d, start, line, column);
	return (valid);
}

void	valid_path(t_win *d, int fd)
{
	malloc_flood_map(d, fd);
	if (!flood_fill(d))
	{
		write(1, "\nValid_path_checker.c,\t", 23);
		write(1, "valid_path() stopped,\n", 23);
		write(1, "There is no valid road to exit on the map \n", 43);
		free_flood_map(d);
		close_frame(d);
		close(fd);
	}
	free_flood_map(d);
}
