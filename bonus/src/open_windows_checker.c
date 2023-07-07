/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_windows_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:13:56 by muhnal            #+#    #+#             */
/*   Updated: 2023/07/07 14:45:22 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	one_exit_checker(t_win *d)
{
	int	row;
	int	col;

	row = 0;
	while (d->level->data[row])
	{
		col = 0;
		while (d->level->data[row][col])
		{
			if (d->level->data[row][col] == 'E')
				d->level->e_c++;
			col++;
		}
		row++;
	}
	if (d->level->e_c != 1)
	{
		write(1, "Error\n", 6);
		write(1, "open_windows_checker.c: Only one EXIT Allowed\n", 46);
		close_frame(d);
	}
}

void	enemy_checker(t_win *d)
{
	int	row;
	int	col;

	row = 0;
	while (d->level->data[row])
	{
		col = 0;
		while (d->level->data[row][col])
		{
			if (d->level->data[row][col] == 'N')
				d->level->en_c++;
			col++;
		}
		row++;
	}
	if (d->level->en_c <= 0)
	{
		write(1, "Error\n", 6);
		write(1, "open_windows_checker.c: bonus need an enemy\n", 45);
		close_frame(d);
	}
}

void	validate_single_player(t_win *d)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (d->level->data[row])
	{
		while (d->level->data[row][col])
		{
			if (d->level->data[row][col] == 'P')
				d->level->p_c += 1;
			col++;
		}
		row++;
		col = 0;
	}
	if (d->level->p_c != 1)
	{
		write(1, "Error\n", 6);
		write(1, "open_windows_checker.c: Only one PLAYER Allowed!\n", 50);
		close_frame(d);
	}
}

void	mapsize_check(t_win *d)
{
	char	**map;
	int		len;
	int		i;

	i = 0;
	len = d->level->w;
	map = d->level->data;
	while (map[i])
	{
		if (str_len_so(map[i]) != len)
		{
			write(1, "Error\n", 6);
			write(1, "open_windows_checker.c:Line size should be equal\n", 50);
			close_frame(d);
		}
		i++;
	}
}

void	coin_check(t_win *d)
{
	int		row;
	int		col;
	char	**map;

	row = -1;
	col = -1;
	map = d->level->data;
	while (map[++row])
	{
		while (map[row][++col])
		{
			if (map[row][col] == 'C')
				d->level->c_c = d->level->c_c + 1;
		}
		col = 0;
	}
	if (d->level->c_c <= 0)
	{
		write(1, "Error\n", 6);
		write(1, "coin_check(t_win *d): No Coins\n", 32);
		write(1, "\nAdd some coins to the map\n", 27);
		close_frame(d);
	}
}
