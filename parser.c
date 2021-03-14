/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:53:37 by epilar            #+#    #+#             */
/*   Updated: 2021/03/10 11:56:23 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*strjoinfree(char *str, char *buf)
{
	char	*new;
	int		i;
	int		j;

	if (!str && !buf)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) *
	(ft_strlen(str) + ft_strlen(buf) + 1))))
		callerror(BAD_MALLOC);
	i = 0;
	j = 0;
	if (str)
	{
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
	}
	while (buf[j])
		new[i++] = buf[j++];
	new[i] = '\0';
	free(str);
	return (new);
}

char	*read_cub(char *argv)
{
	int		fd;
	char	*buf;
	char	*s;
	int		rd;

	fd = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		callerror(BAD_FD);
	if (!(buf = (char *)malloc(sizeof(char) * 2)))
		callerror(BAD_MALLOC);
	buf[1] = '\0';
	if (!(s = (char *)malloc(sizeof(char) * 1)))
		callerror(BAD_MALLOC);
	s[0] = '\0';
	while ((rd = read(fd, &buf[0], 1)))
	{
		if (rd == -1)
			callerror(BAD_FD);
		s = strjoinfree(s, buf);
	}
	free(buf);
	close(fd);
	check_isparam_copy(s);
	check_junk(s);
	return (s);
}

void	parser(char *arg, t_struct *conf)
{
	int		len;
	char	*p;
	char	*str;

	str = read_cub(arg);
	len = ft_strlen(str);
	if ((p = ft_strnstr(str, "R ", len)))
		get_r_param((p + 2), conf);
	if ((p = ft_strnstr(str, "NO ", len)))
		conf->no_tex = get_txtr_param(p + 3);
	if ((p = ft_strnstr(str, "SO ", len)))
		conf->so_tex = get_txtr_param(p + 3);
	if ((p = ft_strnstr(str, "WE ", len)))
		conf->we_tex = get_txtr_param(p + 3);
	if ((p = ft_strnstr(str, "EA ", len)))
		conf->ea_tex = get_txtr_param(p + 3);
	if ((p = ft_strnstr(str, "S ", len)))
		conf->s_tex = get_txtr_param(p + 2);
	if ((p = ft_strnstr(str, "F ", len)))
		conf->fl_c = get_col_param(p + 2);
	if ((p = ft_strnstr(str, "C ", len)))
		conf->ceil_c = get_col_param(p + 2);
	get_map(conf, str);
	free(str);
	check_conf(conf);
}
