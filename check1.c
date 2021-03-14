/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:16:24 by epilar            #+#    #+#             */
/*   Updated: 2021/03/10 08:46:15 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_isparam_copy(char *str)
{
	t_flags		fl;
	int			i;

	ft_bzero(&fl, sizeof(t_flags));
	i = 0;
	while (str[i])
	{
		(str[i] == 'R' && str[i + 1] == ' ') ? fl.r++ : 0;
		(str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ') ? fl.no++ : 0;
		(str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ') ? fl.so++ : 0;
		(str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ') ? fl.we++ : 0;
		(str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ') ? fl.ea++ : 0;
		(str[i] == 'S' && str[i + 1] == ' ') ? fl.s++ : 0;
		(str[i] == 'F' && str[i + 1] == ' ') ? fl.f++ : 0;
		(str[i] == 'C' && str[i + 1] == ' ') ? fl.c++ : 0;
		i++;
	}
	if (fl.r != 1 || fl.no != 1 || fl.so != 1 || fl.we != 1 || fl.ea != 1 ||
	fl.s != 1 || fl.f != 1 || fl.c != 1)
		callerror(BAD_CONF);
}

void	check_col_param(char *p)
{
	int		i;

	if (count_param(p) != 3)
		callerror(BAD_CONF);
	i = 0;
	while (p[i] != '\n')
	{
		if (!(ft_strchr(" ,0123456789", p[i])))
			callerror(BAD_CONF);
		i++;
	}
}

void	check_txtr_junk_b(char *p)
{
	int		i;

	i = 0;
	while (p[i] != '.')
	{
		if (p[i] != ' ')
			callerror(BAD_CONF);
		i++;
	}
}

void	check_txtr_junk_e(char *p)
{
	int		i;

	i = 0;
	while (p[i] != '\n')
	{
		if (p[i] != ' ')
			callerror(BAD_CONF);
		i++;
	}
}

void	check_conf(t_struct *conf)
{
	if (!(conf->x_win) || !(conf->y_win))
		callerror(BAD_CONF);
	if (conf->y_win < 480)
		conf->y_win = 480;
	if (conf->x_win < 854)
		conf->x_win = 854;
	check_links(conf);
	check_openzeros(conf);
	check_plrsprpos(conf);
	check_validsym(conf);
	check_playernum(conf);
}
