/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/26 17:11:12 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "libft.h"
# include <stdlib.h>
# include <math.h>

# define COL_BLACK		0x000000
# define COL_WHITE		0xFFFFFF
# define COL_RED		0xFF0000
# define COL_GREEN		0x00FF00
# define COL_BLUE		0x0000FF
# define COL_CYAN		0x00FFFF
# define COL_YELLOW		0xFFFF00
# define COL_PURPLE		0xFF00FF

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

/*
**	color_convert.c
*/
t_color			hex_to_rgb(int hex);
int				rgb_to_hex(double r, double g, double b);

/*
**	color_gradient.c
*/
int				*gen_bw_gradient_palette(t_color c1, t_color c2, int size);
int				*gen_gradient_palette(t_color c1, t_color c2, int size);

/*
**	color_calc.c
*/
t_color			color_add(t_color col1, t_color col2);
t_color			color_sub(t_color col1, t_color col2);
t_color			color_mul(t_color col, double factor);
t_color			color_div(t_color col, double factor);

#endif
