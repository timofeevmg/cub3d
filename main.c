/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:52:11 by epilar            #+#    #+#             */
/*   Updated: 2021/03/10 08:46:25 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_structs(t_all *all, char *arg)
{
	t_txtrs		*txtrs;

	init_conf(all, arg);
	init_player(all);
	init_mlx(all);
	if (!(txtrs = (t_txtrs *)malloc(sizeof(t_txtrs))))
		callerror(BAD_MALLOC);
	ft_bzero(txtrs, sizeof(t_txtrs));
	all->txtrs = txtrs;
	all->mvfl.mvf = 0;
	all->mvfl.mvb = 0;
	all->mvfl.mvl = 0;
	all->mvfl.mvr = 0;
	all->mvfl.tnl = 0;
	all->mvfl.tnr = 0;
	init_txtrs(all, txtrs);
	init_sprts_array(all);
}

void	play(t_all *all, char *arg)
{
	init_structs(all, arg);
	draw_updown(all);
	draw_walls(all);
	draw_sprites(all);
	draw_map(all);
	draw_rays(all);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	mlx_do_sync(all->win->mlx);
	mlx_hook(all->win->win, 3, 1L << 1, unset_mvfl, all);
	mlx_hook(all->win->win, 2, 1L << 0, set_mvfl, all);
	mlx_hook(all->win->win, 17, 1, quit, all->win->win);
	mlx_loop_hook(all->win->mlx, key_move, all);
	mlx_loop(all->win->mlx);
}

void	get_screenshot(t_all *all, char *arg)
{
	init_structs(all, arg);
	draw_updown(all);
	draw_walls(all);
	draw_sprites(all);
	draw_map(all);
	draw_rays(all);
	image2bmp(all);
}

int		main(int argc, char **argv)
{
	t_all		all;

	if (argc == 1)
		callerror(NO_MAP_FILE);
	else
	{
		check_map_link(argv[1]);
		if (argc == 2)
			play(&all, argv[1]);
		else if (argc == 3)
		{
			if (!ft_strncmp(argv[2], "--save", ft_strlen(argv[2])))
				get_screenshot(&all, argv[1]);
			else
				callerror(BAD_COMMAND);
		}
		else
			callerror(BAD_ARGS);
	}
}
