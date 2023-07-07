/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:44:28 by muhnal            #+#    #+#             */
/*   Updated: 2023/06/20 18:46:21 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_columns(t_win *d)
{
	int		col;
	char	**map;

	map = d->level->data;
	col = 0;
	while (col < d->level->w)
	{
		if (map[0][col] != '1' || map[d->level->h - 1][col] != '1')
		{
			write(1, "Error\n", 6);
			write(1, "Error in check_columns:", 24);
			write(1, "Map is not enclosed by (1) walls\n", 33);
			close_frame(d);
		}
		col++;
	}
}

void	check_rows(t_win *d)
{
	int		row;
	char	**map;

	map = d->level->data;
	row = 0;
	while (row < d->level->h)
	{
		if (map[row][0] != '1' || map[row][d->level->w - 1] != '1')
		{
			write(1, "Error\n", 6);
			write(1, "\nError in check_rows:\n", 23);
			write(1, "Map is not enclosed by (1) walls\n", 33);
			close_frame(d);
		}
		row++;
	}
}

void	wall_check(t_win *d)
{
	check_columns(d);
	check_rows(d);
}
