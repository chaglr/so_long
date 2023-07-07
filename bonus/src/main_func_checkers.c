/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:56:32 by muhnal            #+#    #+#             */
/*   Updated: 2023/06/20 18:41:39 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	validate_ber_file_path(char *path)
{
	int	len;

	len = f_strlen(path);
	if (path[len - 1] != 'r' || path[len - 2] != 'e'
		|| path[len - 3] != 'b' || path[len - 4] != '.')
	{
		write(1, "Error\n", 6);
		write(1, "\nvalidate_ber_file_path(char *path)\n", 37);
		write(1, "Incorrect file extension\n", 25);
		exit(1);
	}
}
