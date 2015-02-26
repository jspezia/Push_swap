/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/11 15:28:46 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		*gen_bw_gradient_palette(t_color col1, t_color col2, int size)
{
	int			*palette;
	int			i;
	t_color		col;

	col = hex_to_rgb(COL_BLACK);
	i = 0;
	if (!(palette = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		if (i < size * 1 / 4)
			col = color_add(col, color_div(col1, size / 4));
		else if (i < size * 2 / 4)
			col = color_add(col,
				color_div(color_sub(hex_to_rgb(COL_WHITE), col1), size / 4));
		else if (i < size * 3 / 4)
			col = color_sub(col,
				color_div(color_sub(hex_to_rgb(COL_WHITE), col2), size / 4));
		else
			col = color_sub(col, color_div(col2, size / 4));
		palette[i] = rgb_to_hex(col.r, col.g, col.b);
		i++;
	}
	return (palette);
}

int		*gen_gradient_palette(t_color col1, t_color col2, int size)
{
	int			*palette;
	int			i;
	t_color		offset_col;
	t_color		col;

	offset_col.r = (col2.r - col1.r) / size;
	offset_col.g = (col2.g - col1.g) / size;
	offset_col.b = (col2.b - col1.b) / size;
	col = col1;
	i = 0;
	if ((palette = (int *)malloc(sizeof(int) * size)))
	{
		while (i < size)
		{
			col.r += offset_col.r;
			col.g += offset_col.g;
			col.b += offset_col.b;
			palette[i] = rgb_to_hex(col.r, col.g, col.b);
			i++;
		}
	}
	return (palette);
}
