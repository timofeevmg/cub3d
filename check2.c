/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:01:40 by epilar            #+#    #+#             */
/*   Updated: 2021/03/10 08:46:18 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_links(t_struct *conf)
{
	int		fd;

	if ((fd = open(conf->no_tex, O_RDONLY)) == -1)
		callerror(BAD_FD);
	close(fd);
	if ((fd = open(conf->so_tex, O_RDONLY)) == -1)
		callerror(BAD_FD);
	close(fd);
	if ((fd = open(conf->we_tex, O_RDONLY)) == -1)
		callerror(BAD_FD);
	close(fd);
	if ((fd = open(conf->ea_tex, O_RDONLY)) == -1)
		callerror(BAD_FD);
	close(fd);
	if ((fd = open(conf->s_tex, O_RDONLY)) == -1)
		callerror(BAD_FD);
	close(fd);
}

void	check_playernum(t_struct *conf)
{
	int		i;
	int		j;
	int		gp;

	i = 0;
	gp = 0;
	while (conf->map[i])
	{
		j = 0;
		while (conf->map[i][j])
		{
			if (ft_strchr("NSWE", conf->map[i][j]))
				gp++;
			j++;
		}
		i++;
	}
	if (gp != 1)
		callerror(BAD_CONF);
}

void	check_validsym(t_struct *conf)
{
	int		i;
	int		j;

	i = 0;
	while (conf->map[i])
	{
		j = 0;
		while (conf->map[i][j])
		{
			if (!(ft_strchr(" 012NSWE", conf->map[i][j])))
				callerror(BAD_CONF);
			j++;
		}
		i++;
	}
}

void	check_plrsprpos(t_struct *conf)
{
	int		i;
	int		j;

	i = -1;
	while (conf->map[++i])
	{
		j = 0;
		while (conf->map[i][j])
		{
			if (ft_strchr("2NSWE", conf->map[i][j]))
			{
				if (conf->map[i][j + 1] == '\0' || conf->map[i][j - 1] == ' ' ||
				conf->map[i][j + 1] == ' ' || i == 0 || j == 0 ||
				conf->map[i + 1] == NULL || (i > 0 && j > 0 &&
				conf->map[i + 1] != NULL && conf->map[i][j + 1] != '\0' &&
				(conf->map[i - 1][j] == ' ' || conf->map[i - 1][j + 1] == ' ' ||
				conf->map[i][j + 1] == ' ' || conf->map[i + 1][j + 1] == ' ' ||
				conf->map[i + 1][j] == ' ' || conf->map[i + 1][j - 1] == ' ' ||
				conf->map[i][j - 1] == ' ' || conf->map[i][j - 1] == ' ' ||
				conf->map[i - 1][j - 1] == ' ')))
					callerror(BAD_CONF);
			}
			j++;
		}
	}
}

void	check_openzeros(t_struct *conf)
{
	int		i;
	int		j;

	i = 0;
	while (conf->map[i])
	{
		j = 0;
		while (conf->map[i][j])
		{
			if (conf->map[i][0] == '0' || conf->map[0][j] == '0' ||
			(conf->map[i][j] == '0' && (conf->map[i][j + 1] == '\0' ||
			conf->map[i + 1] == NULL ||
			(i > 0 && conf->map[i + 1] != NULL && (conf->map[i - 1][j] == ' ' ||
			conf->map[i - 1][j + 1] == ' ' || conf->map[i][j + 1] == ' ' ||
			conf->map[i + 1][j + 1] == ' ' || conf->map[i + 1][j] == ' ' ||
			conf->map[i + 1][j - 1] == ' ' || conf->map[i][j - 1] == ' ' ||
			conf->map[i - 1][j - 1] == ' ')))))
				callerror(BAD_CONF);
			j++;
		}
		i++;
	}
}
