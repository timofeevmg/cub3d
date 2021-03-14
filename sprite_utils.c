/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:22:20 by epilar            #+#    #+#             */
/*   Updated: 2021/03/04 14:44:04 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		count_sprites(t_all *all)
{
	int		n;
	int		i;
	int		j;

	n = 0;
	j = 0;
	while (all->conf->map[j])
	{
		i = 0;
		while (all->conf->map[j][i])
		{
			if (all->conf->map[j][i] == '2')
				n++;
			i++;
		}
		j++;
	}
	return (n);
}

void	init_sprts_array(t_all *all)
{
	int		i;
	int		j;
	int		n;

	j = -1;
	n = 0;
	all->txtrs->count = (size_t)count_sprites(all);
	if (all->txtrs->count)
	{
		if (!(all->txtrs->sprts = (t_sprt *)ft_calloc(sizeof(t_sprt),
		all->txtrs->count)))
			callerror(BAD_MALLOC);
		while (all->conf->map[++j])
		{
			i = -1;
			while (all->conf->map[j][++i])
			{
				if (all->conf->map[j][i] == '2')
				{
					enter_sprt_params(all, n, i, j);
					n++;
				}
			}
		}
	}
}

void	fill_sprts_array(t_all *all)
{
	int		n;

	n = 0;
	while (n < all->txtrs->count)
	{
		all->txtrs->sprts[n].dist = sqrt(powf((all->plr->x / SCALE -
		all->txtrs->sprts[n].sx), 2) + powf((all->plr->y / SCALE -
		all->txtrs->sprts[n].sy), 2));
		n++;
	}
}

void	sprite2image(t_all *all, int n, int scol)
{
	int		l;

	l = all->conf->x_win / all->txtrs->sprts[n].dist;
	draw_sprite_square(all, n, scol, l);
}

void	init_sprt_txtr(t_all *all, t_txtrs *txtrs)
{
	if (!(txtrs->s_img = mlx_xpm_file_to_image(all->win->mlx, all->conf->s_tex,
	&txtrs->simgw, &txtrs->simgh)))
		callerror(BAD_TEX);
	txtrs->s_addr = mlx_get_data_addr(txtrs->s_img, &txtrs->s_bpp, &txtrs->s_ll,
	&txtrs->s_en);
}
