/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:11:59 by epilar            #+#    #+#             */
/*   Updated: 2021/02/17 16:08:38 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_bmpfh(t_all *all, int fd)
{
	char	bmpfh[14];
	int		fsize;

	fsize = 54 + all->conf->x_win * all->conf->y_win * all->win->bpp / 8;
	ft_bzero(&bmpfh, 14);
	bmpfh[0] = (unsigned char)'B';
	bmpfh[1] = (unsigned char)'M';
	bmpfh[2] = (unsigned char)fsize;
	bmpfh[3] = (unsigned char)(fsize >> 8);
	bmpfh[4] = (unsigned char)(fsize >> 16);
	bmpfh[5] = (unsigned char)(fsize >> 24);
	bmpfh[10] = (unsigned char)54;
	write(fd, &bmpfh, 14);
}

void	write_bmpih(t_all *all, int fd)
{
	char	bmpih[40];

	ft_bzero(&bmpih, 40);
	bmpih[0] = (unsigned char)40;
	bmpih[4] = (unsigned char)all->conf->x_win;
	bmpih[5] = (unsigned char)(all->conf->x_win >> 8);
	bmpih[6] = (unsigned char)(all->conf->x_win >> 16);
	bmpih[7] = (unsigned char)(all->conf->x_win >> 24);
	bmpih[8] = (unsigned char)all->conf->y_win;
	bmpih[9] = (unsigned char)(all->conf->y_win >> 8);
	bmpih[10] = (unsigned char)(all->conf->y_win >> 16);
	bmpih[11] = (unsigned char)(all->conf->y_win >> 24);
	bmpih[12] = (unsigned char)1;
	bmpih[14] = (unsigned char)all->win->bpp;
	write(fd, &bmpih, 40);
}

void	image2bmp(t_all *all)
{
	int		fd;
	char	*s;
	int		y;

	if ((fd = open("frame.bmp", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND,
	0666)) == -1)
		callerror(NO_BMP);
	write_bmpfh(all, fd);
	write_bmpih(all, fd);
	y = all->conf->y_win;
	s = all->win->addr + all->win->ll * (y - 1);
	while (y > 0)
	{
		write(fd, s, all->conf->x_win * all->win->bpp / 8);
		s -= all->win->ll;
		y--;
	}
	close(fd);
	exit(0);
}
