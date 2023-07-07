/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:48:53 by muhnal            #+#    #+#             */
/*   Updated: 2023/06/20 13:26:24 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_ply(t_win *d, int keycode)
{
	if (keycode == 2 || keycode == 124)
		d->player->ply_now = d->player->ply_right;
	if (keycode == 0 || keycode == 123)
		d->player->ply_now = d->player->ply_left;
	if (keycode == 1 || keycode == 125)
		d->player->ply_now = d->player->ply_down;
	if (keycode == 13 || keycode == 126)
		d->player->ply_now = d->player->ply_up;
}

void	find_exit_position(t_level *level)
{
	int	x;
	int	y;

	level->e_x = -1;
	level->e_y = -1;
	y = 0;
	while (y < level->h)
	{
		x = 0;
		while (x < level->w)
		{
			if (level->data[y][x] == 'E')
			{
				level->e_x = x;
				level->e_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	find_start_position(t_level *level, t_player *player)
{
	int	y;
	int	x;

	y = 0;
	while (y < level->h)
	{
		x = 0;
		while (x < level->w)
		{
			if (level->data[y][x] == 'P')
			{
				player->start_x = x;
				player->start_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	walk(int keycode, void *par)
{
	t_win	*d;

	d = par;
	mlx_clear_window(d->mlx, d->win);
	if (keycode == 2 || keycode == 124)
		ply_move(d, keycode, d->player->left_x + 70, d->player->left_y);
	if (keycode == 0 || keycode == 123)
		ply_move(d, keycode, d->player->left_x - 70, d->player->left_y);
	if (keycode == 1 || keycode == 125)
		ply_move(d, keycode, d->player->left_x, d->player->left_y + 70);
	if (keycode == 13 || keycode == 126)
		ply_move(d, keycode, d->player->left_x, d->player->left_y - 70);
	if (keycode == 53)
		close_frame(d);
	draw_map(d);
	return (keycode);
}
