/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:12:08 by epilar            #+#    #+#             */
/*   Updated: 2021/03/04 12:14:27 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	callerror(char error_code)
{
	write(1, "Error\n", 6);
	if (error_code == BAD_CONF)
		write(1, "Invalid input parameters\n", 25);
	if (error_code == BAD_MALLOC)
		write(1, "Failed to allocate memory\n", 26);
	if (error_code == BAD_FD)
		write(1, "Could not find file\n", 20);
	if (error_code == NO_MAP_FILE)
		write(1, "Could not find map file\n", 24);
	if (error_code == BAD_COMMAND)
		write(1, "Invalid command\n", 16);
	if (error_code == BAD_ARGS)
		write(1, "Too many arguments\n", 19);
	if (error_code == NO_BMP)
		write(1, "Unable to create bmp file\n", 26);
	if (error_code == BAD_WIN)
		write(1, "Unable to create window\n", 24);
	if (error_code == BAD_IMG)
		write(1, "Unable to allocate image\n", 25);
	if (error_code == BAD_TEX)
		write(1, "Unable to allocate image from texture\n", 38);
	exit(0);
}
