/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:34:16 by ycribier          #+#    #+#             */
/*   Updated: 2015/03/02 16:50:07 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_mlx.h"

void			clear_image(t_img *img)
{
	ft_bzero(img->addr, W_HEIGHT * img->lsize);
}

t_img			*create_new_image(t_env *e, int width, int height)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
	{
		ft_perror("[MLX]: New image alloc failed.");
		exit(-1);
	}
	if ((img->id = mlx_new_image(e->mlx, width, height)) == NULL)
	{
		ft_perror("[MLX]: New image creation failed.");
		exit(-1);
	}
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->id, &img->bpp,
										&img->lsize, &img->endian);
	return (img);
}
