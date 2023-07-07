/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:01:42 by muhnal            #+#    #+#             */
/*   Updated: 2023/06/19 19:43:08 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	f_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}

char	*f_strjoin(char *str, char *str2)
{
	char	*ret;
	int		sayac;

	sayac = 0;
	ret = (char *)malloc(sizeof(char) * (f_strlen(str) + f_strlen(str2) + 1));
	if (!ret)
		return (0);
	while (str && *str)
		ret[sayac++] = *str++;
	while (str2 && *str2)
		ret[sayac++] = *str2++;
	ret[sayac] = '\0';
	return (ret);
}

char	*str_j_f(char **str, char *str2)
{
	char	*old;

	old = *str;
	*str = f_strjoin(old, str2);
	if (old)
		free(old);
	return (0);
}

void	print_score(t_win *d)
{
	ft_printf("Score: %d\n", d->player->score);
}
