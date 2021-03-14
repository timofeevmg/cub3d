/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:02:23 by epilar            #+#    #+#             */
/*   Updated: 2021/03/04 14:22:50 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_r_param(char *p, t_struct *conf)
{
	int		fl;

	fl = 1;
	if (count_param(p) != 2)
		callerror(BAD_CONF);
	while (*p != '\n')
	{
		if (!(ft_strchr(" 0123456789", *p)))
			callerror(BAD_CONF);
		if ((ft_isdigit(*p)))
		{
			while (ft_isdigit(*p))
			{
				if (fl)
					conf->x_win = conf->x_win * 10 + *(p++) - 48;
				else
					conf->y_win = conf->y_win * 10 + *(p++) - 48;
			}
			fl = 0;
		}
		else
			p++;
	}
}

char	*get_txtr_param(char *p)
{
	char	*start;
	char	*end;
	char	*str;
	int		len;
	int		i;

	check_txtr_junk_b(p);
	len = strlen_n(p);
	start = ft_strnstr(p, ".", len);
	if (!(end = ft_strnstr(p, ".xpm\n", (len + 1))))
	{
		if (!(end = ft_strnstr(p, ".xpm ", (len + 1))))
			callerror(BAD_CONF);
	}
	end += 4;
	check_txtr_junk_e(end);
	len = end - start;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		callerror(BAD_MALLOC);
	i = -1;
	while (++i < len)
		str[i] = start[i];
	str[i] = '\0';
	return (str);
}

int		get_col_param(char *p)
{
	t_color	rgb;
	int		fl;
	int		i;

	check_col_param(p);
	ft_bzero(&rgb, sizeof(t_color));
	fl = 1;
	i = -1;
	while (p[++i] != '\n')
	{
		if ((p[i] == ' ' || p[i] == ',') && ft_isdigit(p[i - 1]))
			fl++;
		if (ft_isdigit(p[i]))
		{
			if (fl == 1)
				rgb.r = rgb.r * 10 + p[i] - 48;
			if (fl == 2)
				rgb.g = rgb.g * 10 + p[i] - 48;
			if (fl == 3)
				rgb.b = rgb.b * 10 + p[i] - 48;
		}
	}
	if (rgb.r > 255 || rgb.g > 255 || rgb.b > 255)
		callerror(BAD_CONF);
	return (0 << 24 | rgb.r << 16 | rgb.g << 8 | rgb.b);
}

void	get_map(t_struct *conf, char *str)
{
	char	*p;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i + 1] == ' ' || str[i + 1] == '1'))
			break ;
		i++;
	}
	p = str + i + 1;
	conf->maph = count_lines(p);
	conf->mapw = get_max_length(p, conf->maph);
	fill_map(conf, p, conf->maph, conf->mapw);
}
