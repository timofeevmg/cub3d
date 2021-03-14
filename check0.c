/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:47:25 by epilar            #+#    #+#             */
/*   Updated: 2021/03/10 12:39:32 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_link(char *arg)
{
	int		fd;
	int		i;

	i = 0;
	while (arg[i])
		i++;
	i--;
	if (!(arg[i] == 'b' && arg[i - 1] == 'u' && arg[i - 2] == 'c' &&
	arg[i - 3] == '.'))
		callerror(NO_MAP_FILE);
	if ((fd = open(arg, O_RDONLY)) == -1)
		callerror(NO_MAP_FILE);
	close(fd);
}

void	check_screen(t_all *all, t_win *win)
{
	int		screenx;
	int		screeny;

	mlx_get_screen_size(win->mlx, &screenx, &screeny);
	if (all->conf->x_win > screenx || all->conf->y_win > screeny)
	{
		all->conf->x_win = screenx;
		all->conf->y_win = screeny;
	}
	else
		all->conf->x_win = all->conf->y_win * 16 / 9;
}

void	check_junk(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && !(check_ident(str, i)))
			callerror(BAD_CONF);
		if (str[i] == '\n' && !(check_ident2(str, (i + 1))))
			callerror(BAD_CONF);
		i++;
	}
}

int		check_ident(char *str, int i)
{
	if ((str[i] == 'R' && str[i + 1] == ' ') ||
	(str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ') ||
	(str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ') ||
	(str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ') ||
	(str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ') ||
	(str[i] == 'S' && str[i + 1] == ' ') ||
	(str[i] == 'F' && str[i + 1] == ' ') ||
	(str[i] == 'C' && str[i + 1] == ' ') || str[i] == '\n')
		return (1);
	else
		return (0);
}

int		check_ident2(char *str, int i)
{
	if ((str[i] == 'R' && str[i + 1] == ' ') ||
	(str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ') ||
	(str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ') ||
	(str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ') ||
	(str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ') ||
	(str[i] == 'S' && str[i + 1] == ' ') ||
	(str[i] == 'F' && str[i + 1] == ' ') ||
	(str[i] == 'C' && str[i + 1] == ' ') || str[i] == '\n' ||
	str[i] == ' ' || str[i] == '1')
		return (1);
	else
		return (0);
}
