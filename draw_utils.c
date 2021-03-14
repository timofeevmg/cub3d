/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:46:23 by epilar            #+#    #+#             */
/*   Updated: 2021/03/04 13:59:54 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char			*dst;

	dst = win->addr + (y * win->ll + x * (win->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int		get_txtr_color(t_all *all, float dwall, int row)
{
	unsigned int	color;
	float			q;

	q = all->conf->x_win / dwall;
	if (all->txtrs->fl == 1)
		color = get_txtr_color1(all, row, q);
	if (all->txtrs->fl == 2)
		color = get_txtr_color2(all, row, q);
	if (all->txtrs->fl == 3)
		color = get_txtr_color3(all, row, q);
	if (all->txtrs->fl == 4)
		color = get_txtr_color4(all, row, q);
	return (color);
}

int					get_sprite_color(t_all *all, int row, int col, int l)
{
	unsigned int	*color;
	int				y;
	int				x;

	y = all->txtrs->simgh * row / l;
	x = all->txtrs->simgw * col / l;
	color = (unsigned int*)(all->txtrs->s_addr + (y * all->txtrs->s_ll +
	x * (all->txtrs->s_bpp / 8)));
	return (*color);
}

void				draw_updown(t_all *all)
{
	t_point			point;

	ft_bzero(&point, sizeof(t_point));
	while (point.x < all->conf->x_win)
	{
		point.y = 0;
		while (point.y < all->conf->y_win / 2)
		{
			my_mlx_pixel_put(all->win, point.x, point.y, all->conf->ceil_c);
			point.y++;
		}
		while (point.y < all->conf->y_win)
		{
			my_mlx_pixel_put(all->win, point.x, point.y, all->conf->fl_c);
			point.y++;
		}
		point.x++;
	}
}
