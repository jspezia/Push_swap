/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:22:33 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/25 18:56:44 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <sys/ipc.h>
// #include <sys/shm.h>
// #include <X11/extensions/XShm.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "ps_mlx.h"
#include "libft.h"

// static int		pointer_motion_hook(int x, int y, void *param)
// {
// 	t_env	*e;

// 	e = (t_env *)param;
// 	printf("Mouse at %d, %d\n", x, y);
// }

// static int		loop_hook(t_env *e)
// {
// 	// clear_img(e->img);
// 	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
// 	return (0);
// }

// static int		expose_hook(t_env *e)
// {
// 	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
// 	return (0);
// }

// static int		key_hook(int keycode, void *param)
// {
// 	t_env	*e;

// 	e = (t_env *)param;
// 	printf("Key (released) code: [%d]\n", keycode);
// 	if (keycode == 65307)
// 		exit(0);
// 	return (0);
// }

// static int		mouse_hook(int button, int x, int y, void *param)
// {
// 	t_env	*e;

// 	e = (t_env *)param;
// 	// mlx_string_put(e->mlx, e->win, 10, 10, 0xAAAAAA, "hello");
// 	printf("Mouse code: [%d]\n", button);
// 	return (0);
// }

t_env		*mlx_env_instance(t_env *env)
{
	static t_env	*e = NULL;

	if (!e)
		e = env;
	return (e);
}

t_env		*init_env(void)
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
	return (mlx_env_instance(e));
}
