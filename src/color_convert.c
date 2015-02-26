/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/09 17:53:42 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	hex_to_rgb(int hex)
{
	t_color	col;

	col.r = (double)((hex & 0xFF0000) >> 16) / 255;
	col.g = (double)((hex & 0x00FF00) >> 8) / 255;
	col.b = (double)((hex & 0x0000FF)) / 255;
	return (col);
}

int		rgb_to_hex(double r, double g, double b)
{
	int		col;

	r = r > 1.0 ? 1.0 : r;
	r = r < 0.0 ? 0.0 : r;
	g = g > 1.0 ? 1.0 : g;
	g = g < 0.0 ? 0.0 : g;
	b = b > 1.0 ? 1.0 : b;
	b = b < 0.0 ? 0.0 : b;
	col = 0x000000;
	col += (int)(r * 0xFF) << 16;
	col += (int)(g * 0xFF) << 8;
	col += (int)(b * 0xFF);
	return (col);
}
