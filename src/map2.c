/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:07:58 by muhnal            #+#    #+#             */
/*   Updated: 2023/07/07 17:57:13 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	scoreboard(t_win *d)
{
	char	*score;

	score = ft_itoa(d->player->score);
	mlx_string_put(d->mlx, d->win, 20, 20, 0xFFFFFFFF, score);
	free(score);
}
//P=player, 1=wall, C=collectible, E=exit N=enemy

void	put_map_elem(char c, t_win *d, int x, int y)
{
	mlx_put_image_to_window(d->mlx, d->win, d->bg, x, y);
	if (c == 'P')
	{
		mlx_put_image_to_window(d->mlx, d->win, d->bg, x, y);
		d->player->left_x = x;
		d->player->left_y = y;
		mlx_put_image_to_window(d->mlx, d->win, d->player->ply_now, x, y);
	}
	if (c == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->w_i, x, y);
	if (c == 'C')
		mlx_put_image_to_window(d->mlx, d->win, d->c_i, x, y);
	if (c == 'E')
	{
		d->level->e_x = x;
		d->level->e_y = y;
		mlx_put_image_to_window(d->mlx, d->win, d->e_i, x, y);
	}
}

void	draw_map(t_win *d)
{
	int	row;
	int	col;
	int	pos_x;
	int	pos_y;

	row = 0;
	col = 0;
	pos_x = 0;
	pos_y = 0;
	while (d->level->data[row])
	{
		col = 0;
		pos_x = 0;
		while (d->level->data[row][col])
		{
			put_map_elem(d->level->data[row][col++], d, pos_x, pos_y);
			scoreboard(d);
			pos_x += 70;
		}
		row++;
		pos_y += 70;
	}
}
