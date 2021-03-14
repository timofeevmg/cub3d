/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:58:27 by epilar            #+#    #+#             */
/*   Updated: 2021/03/04 16:24:09 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_all *all)
{
	int		i;
	int		j;

	i = 0;
	while (all->conf->map[i])
	{
		j = 0;
		while (all->conf->map[i][j])
		{
			if (all->conf->map[i][j] == '1')
				draw_rect(all->win, j, i, 0xFFFFFF);
			if (all->conf->map[i][j] == '2')
				draw_rect(all->win, j, i, 0x0000FF);
			if (all->conf->map[i][j] == '0')
				draw_rect(all->win, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

void	draw_rect(t_win *win, int x, int y, int color)
{
	t_point		end;

	end.x = (x + 1) * SCALE;
	end.y = (y + 1) * SCALE;
	x *= SCALE;
	y *= SCALE;
	while (y < end.y)
	{
		while (x < end.x)
		{
			my_mlx_pixel_put(win, x, y, color);
			x++;
		}
		x -= SCALE;
		y++;
	}
}

void	draw_player(t_all *all)
{
	t_point		end;
	t_point		start;

	start.x = all->plr->x - 3;
	start.y = all->plr->y - 3;
	end.x = start.x + 6;
	end.y = start.y + 6;
	while (start.y < end.y)
	{
		while (start.x < end.x)
		{
			my_mlx_pixel_put(all->win, start.x, start.y, 0xFF0000);
			start.x++;
		}
		start.x -= 6;
		start.y++;
	}
}

void	draw_rays(t_all *all)
{
	t_plr	ray;

	ray = *(all->plr);
	ray.start = ray.dir - M_PI_2 / 3;
	ray.end = ray.dir + M_PI_2 / 3;
	while (ray.start <= ray.end)
	{
		ray.x = all->plr->x;
		ray.y = all->plr->y;
		while (all->conf->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)]
		!= '1')
		{
			ray.x += cos(ray.start);
			ray.y += sin(ray.start);
			my_mlx_pixel_put(all->win, ray.x, ray.y, 0xFF0000);
		}
		ray.start += M_PI_2 / 3;
	}
}
