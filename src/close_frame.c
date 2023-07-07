/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:06:32 by muhnal            #+#    #+#             */
/*   Updated: 2023/06/19 19:43:14 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_frame(void *param)
{
	int		i;
	t_win	*d;

	i = 0;
	d = (t_win *)param;
	mlx_destroy_image(d->mlx, d->bg);
	mlx_destroy_image(d->mlx, d->w_i);
	mlx_destroy_image(d->mlx, d->c_i);
	mlx_destroy_image(d->mlx, d->e_i);
	mlx_destroy_image(d->mlx, d->player->ply_down);
	mlx_destroy_image(d->mlx, d->player->ply_left);
	mlx_destroy_image(d->mlx, d->player->ply_right);
	mlx_destroy_image(d->mlx, d->player->ply_up);
	free(d->player);
	while (d->level->data[i])
		free(d->level->data[i++]);
	free(d->level->data);
	free(d->level);
	mlx_destroy_window(d->mlx, d->win);
	exit(1);
	return (1);
}

void	free_flood_map(t_win *d)
{
	int	i;

	i = 0;
	while (d->level->flood_map[i])
		free(d->level->flood_map[i++]);
	free(d->level->flood_map);
}
