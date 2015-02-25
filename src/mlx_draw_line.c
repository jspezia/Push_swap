/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/25 18:40:20 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_mlx.h"

static void		draw_line_1(int color, t_pt *pt1, t_pt *pt2, t_img *img)
{
	int	x;
	int	y;

	x = pt1->x;
	while (x <= pt2->x)
	{
		y = pt1->y + ((pt2->y - pt1->y) * (x - pt1->x)) / (pt2->x - pt1->x);
		my_pixel_put_to_image(img, x, y, color);
		x++;
	}
}

static void		draw_line_2(int color, t_pt *pt1, t_pt *pt2, t_img *img)
{
	int	x;
	int	y;

	y = pt1->y;
	if (pt1->x == pt2->x && pt1->y == pt2->y)
	{
		my_pixel_put_to_image(img, pt1->x, pt1->y, color);
		return ;
	}
	while (y <= pt2->y)
	{
		x = pt1->x + ((pt2->x - pt1->x) * (y - pt1->y)) / (pt2->y - pt1->y);
		my_pixel_put_to_image(img, x, y, color);
		y++;
	}
}

void			draw_line(int color, t_pt *pt1, t_pt *pt2, t_img *img)
{
	if ((ft_abs(pt1->x - pt2->x) > ft_abs(pt1->y - pt2->y)))
	{
		if (pt1->x < pt2->x)
			draw_line_1(color, pt1, pt2, img);
		else
			draw_line_1(color, pt2, pt1, img);
	}
	else
	{
		if (pt1->y < pt2->y)
			draw_line_2(color, pt1, pt2, img);
		else
			draw_line_2(color, pt2, pt1, img);
	}
}
