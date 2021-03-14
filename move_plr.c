/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_plr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:51:32 by epilar            #+#    #+#             */
/*   Updated: 2021/03/04 14:45:57 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_move(t_all *all)
{
	if (all->mvfl.mvf)
		move_forward(all);
	if (all->mvfl.mvb)
		move_backward(all);
	if (all->mvfl.mvl)
		move_left(all);
	if (all->mvfl.mvr)
		move_right(all);
	if (all->mvfl.tnl)
		all->plr->dir -= 0.02;
	if (all->mvfl.tnr)
		all->plr->dir += 0.02;
	draw_updown(all);
	draw_walls(all);
	draw_map(all);
	draw_rays(all);
	draw_sprites(all);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	mlx_do_sync(all->win->mlx);
	return (0);
}

void	move_forward(t_all *all)
{
	t_plr	plr;

	all->plr->y += sin(all->plr->dir);
	all->plr->x += cos(all->plr->dir);
	plr.x = all->plr->x;
	plr.y = all->plr->y;
	if (all->conf->map[(int)(plr.y / SCALE)][(int)(plr.x / SCALE)] == '1')
	{
		all->plr->y -= sin(all->plr->dir);
		all->plr->x -= cos(all->plr->dir);
	}
}

void	move_backward(t_all *all)
{
	t_plr	plr;

	all->plr->y += sin(all->plr->dir - M_PI);
	all->plr->x += cos(all->plr->dir - M_PI);
	plr.x = all->plr->x;
	plr.y = all->plr->y;
	if (all->conf->map[(int)(plr.y / SCALE)][(int)(plr.x / SCALE)] == '1')
	{
		all->plr->y -= sin(all->plr->dir - M_PI);
		all->plr->x -= cos(all->plr->dir - M_PI);
	}
}

void	move_left(t_all *all)
{
	t_plr	plr;

	all->plr->y += sin(all->plr->dir - M_PI_2);
	all->plr->x += cos(all->plr->dir - M_PI_2);
	plr.x = all->plr->x;
	plr.y = all->plr->y;
	if (all->conf->map[(int)(plr.y / SCALE)][(int)(plr.x / SCALE)] == '1')
	{
		all->plr->y -= sin(all->plr->dir - M_PI_2);
		all->plr->x -= cos(all->plr->dir - M_PI_2);
	}
}

void	move_right(t_all *all)
{
	t_plr	plr;

	all->plr->y += sin(all->plr->dir + M_PI_2);
	all->plr->x += cos(all->plr->dir + M_PI_2);
	plr.x = all->plr->x;
	plr.y = all->plr->y;
	if (all->conf->map[(int)(plr.y / SCALE)][(int)(plr.x / SCALE)] == '1')
	{
		all->plr->y -= sin(all->plr->dir + M_PI_2);
		all->plr->x -= cos(all->plr->dir + M_PI_2);
	}
}
