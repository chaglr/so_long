/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_windows_checker1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:34:48 by muhnal            #+#    #+#             */
/*   Updated: 2023/06/20 18:48:21 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map_characters(t_win *d)
{
	int	row;
	int	col;

	row = -1;
	col = -1;
	while (d->level->data[++row])
	{
		while (d->level->data[row][++col])
		{
			if (d->level->data[row][col] != '1'
				&& d->level->data[row][col] != '0'
				&& d->level->data[row][col] != 'C'
				&& d->level->data[row][col] != 'E'
				&& d->level->data[row][col] != 'P')
			{
				write(1, "Error\n", 6);
				write(1, "\nError in validate_map_characters(t_win *d):", 43);
				write(1, "\nInvalid character in map\n", 26);
				close_frame(d);
			}
		}
		col = 0;
	}
}

int	str_len_so(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
