/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/26 10:44:02 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_ESC		65307
# define KEY_SHIFT_L	65505
# define KEY_SHIFT_R	65505
# define KEY_MORE		65451
# define KEY_LESS		65453
# define KEY_SPACE		32
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_C			99
# define KEY_T			116
# define KEY_R			114
# define KEY_1			49
# define KEY_2			50
# define KEY_3			51
# define KEY_4			52
# define KEY_5			53

# define SCROLL_UP		4
# define SCROLL_DOWN	5

typedef struct s_env	t_env;

typedef struct			s_keys
{
	t_bool	up;
	t_bool	down;
	t_bool	right;
	t_bool	left;
}						t_keys;

/*
**		mlx_keys.c
*/
int						key_press(int keycode, t_env *e);
int						key_release(int keycode, t_env *e);
void					manage_keys(t_env *e);
t_keys					*init_keys(void);

#endif
