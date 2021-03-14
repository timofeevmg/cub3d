/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:50:31 by epilar            #+#    #+#             */
/*   Updated: 2021/03/10 08:46:21 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_conf(t_all *all, char *arg)
{
	t_struct	*conf;

	if (!(conf = (t_struct *)malloc(sizeof(t_struct))))
		callerror(BAD_MALLOC);
	ft_bzero(conf, sizeof(t_struct));
	parser(arg, conf);
	all->conf = conf;
}

void	init_player(t_all *all)
{
	int		i;
	int		j;

	i = -1;
	if (!(all->plr = (t_plr *)malloc(sizeof(t_plr))))
		callerror(BAD_MALLOC);
	while (all->conf->map[++i])
	{
		j = -1;
		while (all->conf->map[i][++j])
		{
			if (ft_strchr("NSWE", all->conf->map[i][j]))
			{
				init_plr_dir(all, all->conf->map[i][j]);
				all->plr->x = (j + 0.5) * SCALE;
				all->plr->y = (i + 0.5) * SCALE;
				all->conf->map[i][j] = '0';
			}
		}
	}
	all->plr->start = all->plr->dir - M_PI_2 / 3;
	all->plr->end = all->plr->dir + M_PI_2 / 3;
}

void	init_plr_dir(t_all *all, char c)
{
	if (c == 'N')
		all->plr->dir = 3 * M_PI_2;
	if (c == 'S')
		all->plr->dir = M_PI_2;
	if (c == 'W')
		all->plr->dir = M_PI;
	if (c == 'E')
		all->plr->dir = 0;
}

void	init_mlx(t_all *all)
{
	t_win		*win;

	if (!(win = (t_win *)malloc(sizeof(t_win))))
		callerror(BAD_MALLOC);
	win->mlx = mlx_init();
	check_screen(all, win);
	if (!(win->win = mlx_new_window(win->mlx, all->conf->x_win,
	all->conf->y_win, "Cub3d by epilar")))
		callerror(BAD_WIN);
	if (!(win->img = mlx_new_image(win->mlx, all->conf->x_win,
	all->conf->y_win)))
		callerror(BAD_IMG);
	win->addr = mlx_get_data_addr(win->img, &(win->bpp), &(win->ll),
	&(win->en));
	all->win = win;
}

void	zero_txtrs_params(t_txtrs *txtrs)
{
	txtrs->fl = 0;
	txtrs->count = 0;
	txtrs->sprts = NULL;
	txtrs->zbuf = NULL;
}
