/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_my_pixel_put_to_image.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:27:00 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/25 18:33:50 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_mlx.h"

void	my_pixel_put_to_image(t_img *img, int x, int y, int color)
{
	int				i;
	int				mask;
	char			tmp_color;
	int				offset;

	i = 0;
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		while (i < (img->bpp / 8))
		{
			if (img->endian == 1)
				offset = img->bpp - 8 * (i + 1);
			else
				offset = 8 * i;
			mask = 0xFF << offset;
			tmp_color = (color & mask) >> offset;
			img->addr[y * (img->lsize) + x * (img->bpp / 8) + i] = tmp_color;
			i++;
		}
	}
}

void	my_pixel_put_to_image_osx(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		ft_memcpy(&img->addr[y * (img->lsize) + x * 4], &color, sizeof(int));
	}
}
