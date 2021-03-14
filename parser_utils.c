/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:57:04 by epilar            #+#    #+#             */
/*   Updated: 2021/03/04 12:13:46 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		count_param(char *p)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (p[i] != '\n')
	{
		if (ft_isdigit(p[i]) && !ft_isdigit(p[i + 1]))
			num++;
		i++;
	}
	return (num);
}

void	fill_map(t_struct *conf, char *p, int lines, int maxl)
{
	int		n;
	int		i;

	n = -1;
	if (!(conf->map = (char **)ft_calloc(sizeof(char *), (lines + 1))))
		callerror(BAD_MALLOC);
	while (++n < lines)
	{
		if (!((conf->map)[n] = (char *)malloc(sizeof(char) * (maxl + 1))))
			callerror(BAD_MALLOC);
		i = 0;
		while (p[i] != '\n' && p[i] != '\0')
		{
			(conf->map)[n][i] = p[i];
			i++;
		}
		if (p[i] == '\n')
			p += i + 1;
		while (i < maxl)
		{
			(conf->map)[n][i] = ' ';
			i++;
		}
		(conf->map)[n][i] = '\0';
	}
}

int		count_lines(char *p)
{
	int		count;

	count = 0;
	while (*p != '\0')
	{
		if (*p == '\n')
			count++;
		p++;
	}
	count++;
	return (count);
}

int		get_max_length(char *p, int lines)
{
	int		len;
	int		i;

	len = 0;
	while (lines > 0)
	{
		i = 0;
		while (p[i] != '\n' && p[i] != '\0')
			i++;
		if (i == 0)
			callerror(BAD_CONF);
		if (p[i] == '\n')
			p += i + 1;
		len = (i > len) ? i : len;
		lines--;
	}
	return (len);
}

int		strlen_n(char *p)
{
	int		i;

	i = 0;
	while (p[i] != '\n')
		i++;
	return (i);
}
