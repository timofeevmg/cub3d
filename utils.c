/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:42:33 by epilar            #+#    #+#             */
/*   Updated: 2021/03/04 15:21:51 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	enter_sprt_params(t_all *all, int n, int i, int j)
{
	all->txtrs->sprts[n].i = i;
	all->txtrs->sprts[n].j = j;
	all->txtrs->sprts[n].sx = i + 0.5;
	all->txtrs->sprts[n].sy = j + 0.5;
	all->txtrs->sprts[n].dist = 0;
}

int		quit(void)
{
	exit(0);
	return (0);
}

int		set_mvfl(int key, t_all *all)
{
	if (key == 13)
		all->mvfl.mvf = 1;
	if (key == 1)
		all->mvfl.mvb = 1;
	if (key == 0)
		all->mvfl.mvl = 1;
	if (key == 2)
		all->mvfl.mvr = 1;
	if (key == 123)
		all->mvfl.tnl = 1;
	if (key == 124)
		all->mvfl.tnr = 1;
	if (key == 53)
		exit(0);
	return (0);
}

int		unset_mvfl(int key, t_all *all)
{
	if (key == 13)
		all->mvfl.mvf = 0;
	else if (key == 1)
		all->mvfl.mvb = 0;
	else if (key == 0)
		all->mvfl.mvl = 0;
	else if (key == 2)
		all->mvfl.mvr = 0;
	else if (key == 123)
		all->mvfl.tnl = 0;
	else if (key == 124)
		all->mvfl.tnr = 0;
	return (0);
}
