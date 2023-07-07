/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:07:08 by muhnal            #+#    #+#             */
/*   Updated: 2023/07/07 16:51:17 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_win *d, int x, int y)
{
	d->dis_height = d->level->h * 70;
	d->dis_width = d->level->w * 70;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->dis_width, d->dis_height, "Thiller_42");
	d->player = ft_calloc(1, sizeof(t_player));
	d->player->left_y = 0;
	d->player->left_x = 0;
	d->player->score = 0;
	d->player->ply_down = mlx_xpm_file_to_image(d->mlx, "./xpm/down.xpm", &x,
			&y);
	d->player->ply_left = mlx_xpm_file_to_image(d->mlx, "./xpm/left.xpm", &x,
			&y);
	d->player->ply_right = mlx_xpm_file_to_image(d->mlx, "./xpm/right.xpm", &x,
			&y);
	d->player->ply_up = mlx_xpm_file_to_image(d->mlx, "./xpm/up.xpm", &x, &y);
	d->player->ply_now = d->player->ply_down;
	d->bg = mlx_xpm_file_to_image(d->mlx, "./xpm/bg.xpm", &x, &y);
	d->w_i = mlx_xpm_file_to_image(d->mlx, "./xpm/barrel.xpm", &x, &y);
	d->c_i = mlx_xpm_file_to_image(d->mlx, "./xpm/coin.xpm", &x, &y);
	d->e_i = mlx_xpm_file_to_image(d->mlx, "./xpm/exit.xpm", &x, &y);
}

void	open_window(t_win *d, char *path)
{
	int	x;
	int	y;
	int	fd_map;

	x = 0;
	y = 0;
	d->level = load_map(path);
	load_images(d, x, y);
	validate_single_player(d);
	mapsize_check(d);
	wall_check(d);
	one_exit_checker(d);
	validate_map_characters(d);
	coin_check(d);
	find_exit_position(d->level);
	find_start_position(d->level, d->player);
	fd_map = open(path, O_RDONLY);
	valid_path(d, fd_map);
	close(fd_map);
}

void	check_xpm_file(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		write(1, "XPM file not found\n", 19);
		exit(1);
	}
	close(fd);
}

void	xpm_validation(void)
{
	check_xpm_file("./xpm/down.xpm");
	check_xpm_file("./xpm/left.xpm");
	check_xpm_file("./xpm/right.xpm");
	check_xpm_file("./xpm/up.xpm");
	check_xpm_file("./xpm/barrel.xpm");
	check_xpm_file("./xpm/bg.xpm");
	check_xpm_file("./xpm/exit.xpm");
	check_xpm_file("./xpm/coin.xpm");
}

int	main2(int argc, char **argv)
{
	t_win	d;

	if (argc == 2)
	{
		xpm_validation();
		validate_ber_file_path(argv[1]);
		file_control(argv[1]);
		open_window(&d, argv[1]);
		draw_map(&d);
		mlx_hook(d.win, 2, (1L << 0), walk, &d);
		mlx_hook(d.win, 17, 0, close_frame, &d);
		mlx_loop(d.mlx);
	}
	else
	{
		write(1, "Error\n", 6);
		write(1, "Missing argument\n", 17);
		return (1);
	}
	return (0);
}

void checkleaks(void)
{
	system("leaks so_long");
}

int main(int argc, char **argv)
{
	atexit(checkleaks);
	main2(argc, argv);
	system("leaks so_long");
	return (0);
}
