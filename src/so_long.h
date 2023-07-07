/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:57:57 by muhnal            #+#    #+#             */
/*   Updated: 2023/06/20 12:13:26 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include <stdbool.h>
# include <string.h>
# include <unistd.h>

typedef struct s_player
{
	int			left_y;
	int			left_x;
	int			score;
	void		*ply_down;
	void		*ply_up;
	void		*ply_left;
	void		*ply_right;
	void		*ply_now;
	int			start_x;
	int			start_y;
}	t_player;

// t_c total coin
// e_x exit x pos
// e_y exit y pos
// p_c player_count
// e_c exit_count
// t_c total coin
// c_c coin_check
// en_x enemy x pos
// en_y enemy y pos
typedef struct s_level
{
	char	**data;
	int		w;
	int		h;
	int		cs;
	int		e_x;
	int		e_y;
	int		p_c;
	int		e_c;
	int		t_c;
	int		c_c;
	int		en_x;
	int		en_y;
	char	**flood_map;
}	t_level;

/*
** typedef struct s_enemy
** {
** 	int			x;
** 	int			y;
** 	int			w;
** 	int			h;
** }	t_enemy;
*/

typedef struct s_win
{
	t_level		*level;
	t_player	*player;
	void		*win;
	void		*mlx;
	void		*bg;
	void		*w_i;
	void		*c_i;
	void		*en_i;
	void		*e_i;
	int			dis_height;
	int			dis_width;
	bool		exit;
	int			f_coin;
}	t_win;

int		close_frame(void *param);
void	draw_map(t_win *d);

void	one_exit_checker(t_win *d);
void	validate_single_player(t_win *d);
void	wall_check(t_win *d);
void	mapsize_check(t_win *d);
void	coin_check(t_win *d);

void	validate_map_characters(t_win *d);
t_level	*load_map(char *path);
void	validate_ber_file_path(char *path);
int		walk(int keycode, void *par);
int		str_len_so(char *str);
void	file_control(char *path);
char	*str_j_f(char **str, char *str2);
size_t	f_strlen(const char *str);

void	malloc_flood_map(t_win *d, int fd);
bool	fill(t_win *d, char c, int line, int col);
int		flood_fill(t_win *d);
void	valid_path(t_win *d, int fd);
void	free_flood_map(t_win *d);
void	find_exit_position(t_level *level);
void	find_start_position(t_level *level, t_player *player);
void	wall_check(t_win *d);
void	print_score(t_win *d);

#endif
