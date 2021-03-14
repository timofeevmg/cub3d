/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:07:19 by epilar            #+#    #+#             */
/*   Updated: 2021/03/04 16:39:24 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprites(t_all *all)
{
	if (all->txtrs->sprts != NULL)
	{
		fill_sprts_array(all);
		sort_sprts_array(all);
		analyze_sprts(all);
	}
}

void	sort_sprts_array(t_all *all)
{
	int		i;
	int		j;
	t_sprt	tmp;

	i = 0;
	while (i < all->txtrs->count - 1)
	{
		j = all->txtrs->count - 1;
		while (j > i)
		{
			if (all->txtrs->sprts[j - 1].dist < all->txtrs->sprts[j].dist)
			{
				tmp = all->txtrs->sprts[j - 1];
				all->txtrs->sprts[j - 1] = all->txtrs->sprts[j];
				all->txtrs->sprts[j] = tmp;
			}
			j--;
		}
		i++;
	}
}

void	analyze_sprts(t_all *all)
{
	int		n;
	float	sang;
	float	pang;
	float	ang;

	n = 0;
	while (n < all->txtrs->count)
	{
		sang = atan2f((all->txtrs->sprts[n].sy - all->plr->y / SCALE),
		(all->txtrs->sprts[n].sx - all->plr->x / SCALE));
		pang = all->plr->dir - floor(all->plr->dir / (2 * M_PI)) * 2 * M_PI;
		if (sang - pang > M_PI)
			sang -= 2 * M_PI;
		if (sang - pang < -M_PI)
			sang += 2 * M_PI;
		ang = sang - pang;
		if (ang <= M_PI_2 || ang >= -M_PI_2)
		{
			if (all->txtrs->sprts[n].dist > 1)
				place_sprts(all, n, ang);
		}
		n++;
	}
}

void	place_sprts(t_all *all, int n, float ang)
{
	float	step;
	int		scol;

	step = M_PI / 3 / all->conf->x_win;
	scol = (int)((ang + M_PI / 3 / 2) / step);
	sprite2image(all, n, scol);
}

void	draw_sprite_square(t_all *all, int n, int scol, int l)
{
	int		x;
	int		y;
	int		col;
	int		row;
	int		color;

	row = -1;
	while (++row < l)
	{
		col = -1;
		while (++col < l)
		{
			y = row + (all->conf->y_win - l) / 2;
			x = col + scol - l / 2;
			if (x >= 0 && x < all->conf->x_win)
			{
				if (all->txtrs->zbuf[x] > all->txtrs->sprts[n].dist)
				{
					if ((color = get_sprite_color(all, row, col, l)) && y >= 0
					&& y < all->conf->y_win)
						my_mlx_pixel_put(all->win, x, y, color);
				}
			}
		}
	}
}
