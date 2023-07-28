/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:26:42 by muhnal            #+#    #+#             */
/*   Updated: 2023/06/20 13:27:07 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_win_or_lose(t_win *d, int x, int y)
{
	if (d->level->t_c == 0 && d->level->data[y / 70][x / 70] == 'E')
	{
		d->player->score += 1;
		print_score(d);
		ft_printf("you WIN !!");
		close_frame(d);
	}
	else if (d->level->data[y / 70][x / 70] == 'N')
	{
		ft_printf("You LOSE!!");
		close_frame(d);
	}
}

void	update_player_position(t_win *d, int keycode, int x, int y)
{
	if (d->level->data[y / 70][x / 70] != '1')
	{
		put_ply(d, keycode);
		d->player->score += 1;
		if (d->level->data[y / 70][x / 70] == 'C')
			d->level->t_c -= 1;
		d->level->data[d->player->left_y / 70][d->player->left_x / 70] = '0';
		d->level->data[d->level->e_y / 70][d->level->e_x / 70] = 'E';
		d->level->data[y / 70][x / 70] = 'P';
		if (d->level->data[d->level->e_y / 70][d->level->e_x / 70] != 'P')
			d->level->data[d->level->e_y / 70][d->level->e_x / 70] = 'E';
	}
	draw_map(d);
}

void	ply_move(t_win *d, int keycode, int x, int y)
{
	check_win_or_lose(d, x, y);
	update_player_position(d, keycode, x, y);
}
