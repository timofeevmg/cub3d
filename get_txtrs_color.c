/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_txtrs_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:31:12 by epilar            #+#    #+#             */
/*   Updated: 2021/03/04 14:23:38 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int		get_txtr_color1(t_all *all, int row, float q)
{
	unsigned int	*color;
	int				x;
	int				y;

	x = (int)(all->txtrs->noimgw * all->txtrs->hitx);
	if (q > all->conf->y_win)
		y = ((row + (q - all->conf->y_win) / 2) * all->txtrs->noimgh) / q;
	else
		y = row * all->txtrs->noimgh / q;
	color = (unsigned int*)(all->txtrs->no_addr + (y * all->txtrs->no_ll +
	x * (all->txtrs->no_bpp / 8)));
	return (*color);
}

unsigned int		get_txtr_color2(t_all *all, int row, float q)
{
	unsigned int	*color;
	int				x;
	int				y;

	x = (int)(all->txtrs->soimgw * all->txtrs->hitx);
	if (q > all->conf->y_win)
		y = ((row + (q - all->conf->y_win) / 2) * all->txtrs->soimgh) / q;
	else
		y = row * all->txtrs->soimgh / q;
	color = (unsigned int*)(all->txtrs->so_addr + (y * all->txtrs->so_ll +
	x * (all->txtrs->so_bpp / 8)));
	return (*color);
}

unsigned int		get_txtr_color3(t_all *all, int row, float q)
{
	unsigned int	*color;
	int				x;
	int				y;

	x = (int)(all->txtrs->weimgw * all->txtrs->hity);
	if (q > all->conf->y_win)
		y = ((row + (q - all->conf->y_win) / 2) * all->txtrs->eaimgh) / q;
	else
		y = row * all->txtrs->eaimgh / q;
	color = (unsigned int*)(all->txtrs->we_addr + (y * all->txtrs->we_ll +
	x * (all->txtrs->we_bpp / 8)));
	return (*color);
}

unsigned int		get_txtr_color4(t_all *all, int row, float q)
{
	unsigned int	*color;
	int				x;
	int				y;

	x = (int)(all->txtrs->eaimgw * all->txtrs->hity);
	if (q > all->conf->y_win)
		y = ((row + (q - all->conf->y_win) / 2) * all->txtrs->weimgh) / q;
	else
		y = row * all->txtrs->weimgh / q;
	color = (unsigned int*)(all->txtrs->ea_addr + (y * all->txtrs->ea_ll +
	x * (all->txtrs->ea_bpp / 8)));
	return (*color);
}
