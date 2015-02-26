/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/09 17:53:41 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color_add(t_color col1, t_color col2)
{
	t_color	result;

	result = col1;
	result.r += col2.r;
	result.g += col2.g;
	result.b += col2.b;
	return (result);
}

t_color	color_sub(t_color col1, t_color col2)
{
	t_color	result;

	result = col1;
	result.r -= col2.r;
	result.g -= col2.g;
	result.b -= col2.b;
	return (result);
}

t_color	color_mul(t_color col, double factor)
{
	t_color	result;

	result = col;
	result.r *= factor;
	result.g *= factor;
	result.b *= factor;
	return (result);
}

t_color	color_div(t_color col, double factor)
{
	t_color	result;

	result = col;
	result.r /= factor;
	result.g /= factor;
	result.b /= factor;
	return (result);
}
