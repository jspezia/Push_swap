/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:22:33 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/26 11:14:19 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_env(t_env *e)
{
	free(e->img);
	free(e->keys);
	free(e);
}

t_env		*mlx_env_instance(t_env *env)
{
	static t_env	*e = NULL;

	if (!e)
		e = env;
	return (e);
}

t_env		*init_env(t_ps *ps)
{
	t_env	*e;

	if (!(e = malloc(sizeof(t_env))))
		exit(-1);
	if ((e->mlx = mlx_init()) == NULL)
	{
		perror("[MLX]: Connexion to server X failed.");
		exit(-1);
	}
	if (!(e->win = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, "-- TITLE --")))
	{
		perror("[MLX]: New window creation failed.");
		exit(-1);
	}
	if (!(e->img = create_new_image(e, W_WIDTH, W_HEIGHT)))
		exit(-1);
	if (!(e->keys = init_keys()))
		exit(-1);
	e->ps = ps;
	return (mlx_env_instance(e));
}
