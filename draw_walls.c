/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:02:02 by epilar            #+#    #+#             */
/*   Updated: 2021/03/10 08:46:23 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_txtrs(t_all *all, t_txtrs *txtrs)
{
	zero_txtrs_params(txtrs);
	if (!(txtrs->no_img = mlx_xpm_file_to_image(all->win->mlx,
	all->conf->no_tex, &txtrs->noimgw, &txtrs->noimgh)))
		callerror(BAD_TEX);
	txtrs->no_addr = mlx_get_data_addr(txtrs->no_img, &txtrs->no_bpp,
	&txtrs->no_ll, &txtrs->no_en);
	if (!(txtrs->so_img = mlx_xpm_file_to_image(all->win->mlx,
	all->conf->so_tex, &txtrs->soimgw, &txtrs->soimgh)))
		callerror(BAD_TEX);
	txtrs->so_addr = mlx_get_data_addr(txtrs->so_img, &txtrs->so_bpp,
	&txtrs->so_ll, &txtrs->so_en);
	if (!(txtrs->we_img = mlx_xpm_file_to_image(all->win->mlx,
	all->conf->we_tex, &txtrs->weimgw, &txtrs->weimgh)))
		callerror(BAD_TEX);
	txtrs->we_addr = mlx_get_data_addr(txtrs->we_img, &txtrs->we_bpp,
	&txtrs->we_ll, &txtrs->we_en);
	if (!(txtrs->ea_img = mlx_xpm_file_to_image(all->win->mlx,
	all->conf->ea_tex, &txtrs->eaimgw, &txtrs->eaimgh)))
		callerror(BAD_TEX);
	txtrs->ea_addr = mlx_get_data_addr(txtrs->ea_img, &txtrs->ea_bpp,
	&txtrs->ea_ll, &txtrs->ea_en);
	init_sprt_txtr(all, txtrs);
	if (!(all->txtrs->zbuf = (float *)ft_calloc(all->conf->x_win,
	sizeof(float))))
		callerror(BAD_MALLOC);
}

float		get_wall_hit(t_all *all, t_plr *ray)
{
	while (all->conf->map[(int)(ray->y / SCALE)][(int)(ray->x / SCALE)] != '1')
	{
		ray->x += cos(ray->start);
		ray->y += sin(ray->start);
	}
	ray->x -= cos(ray->start);
	ray->y -= sin(ray->start);
	while (all->conf->map[(int)(ray->y / SCALE)][(int)(ray->x / SCALE)] != '1')
	{
		ray->x += 0.1 * cos(ray->start);
		ray->y += 0.1 * sin(ray->start);
	}
	ray->x -= 0.1 * cos(ray->start);
	ray->y -= 0.1 * sin(ray->start);
	while (all->conf->map[(int)(ray->y / SCALE)][(int)(ray->x / SCALE)] != '1')
	{
		ray->x += 0.001 * cos(ray->start);
		ray->y += 0.001 * sin(ray->start);
	}
	all->txtrs->hitx = ray->x / SCALE - floor(ray->x / SCALE);
	all->txtrs->hity = ray->y / SCALE - floor(ray->y / SCALE);
	return (cos(ray->start - ray->dir) * sqrt(powf((ray->x - all->plr->x), 2) +
	powf((ray->y - all->plr->y), 2)) / SCALE);
}

void		get_txtr_flag(t_all *all, t_plr ray)
{
	t_point	inwall;
	t_point outwall;

	inwall.x = (int)(ray.x / SCALE);
	inwall.y = (int)(ray.y / SCALE);
	outwall.x = (int)((ray.x - 0.01 * cos(ray.start)) / SCALE);
	outwall.y = (int)((ray.y - 0.01 * sin(ray.start)) / SCALE);
	if (inwall.x == outwall.x)
	{
		if (inwall.y < outwall.y)
			all->txtrs->fl = 1;
		else
			all->txtrs->fl = 2;
	}
	if (inwall.y == outwall.y)
	{
		if (inwall.x < outwall.x)
			all->txtrs->fl = 3;
		else
			all->txtrs->fl = 4;
	}
}

void		draw_vline(t_all *all, float dwall, int wincol)
{
	int		l;
	int		row;
	int		y;
	int		color;

	color = 0;
	row = 0;
	if (all->conf->x_win / dwall > all->conf->y_win)
		l = all->conf->y_win;
	else
		l = all->conf->x_win / dwall;
	while (row < l)
	{
		y = row + (all->conf->y_win - l) / 2;
		color = get_txtr_color(all, dwall, row);
		my_mlx_pixel_put(all->win, wincol, y, color);
		row++;
	}
}

void		draw_walls(t_all *all)
{
	t_plr	ray;
	int		wincol;
	float	dwall;

	wincol = 0;
	ray = *(all->plr);
	ray.start = ray.dir - M_PI_2 / 3;
	ray.end = ray.dir + M_PI_2 / 3;
	while (wincol < all->conf->x_win)
	{
		ray.x = all->plr->x;
		ray.y = all->plr->y;
		dwall = get_wall_hit(all, &ray);
		all->txtrs->zbuf[wincol] = dwall / cos(ray.start - ray.dir);
		get_txtr_flag(all, ray);
		draw_vline(all, dwall, wincol);
		ray.start += M_PI / 3 / all->conf->x_win;
		wincol++;
	}
}
