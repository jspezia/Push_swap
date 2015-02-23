/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 11:27:47 by jspezia           #+#    #+#             */
/*   Updated: 2014/03/01 11:29:22 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

float		ft_fmin(float x, float y)
{
	if (x < y)
		return (x);
	return (y);
}

double		ft_dmin(double x, double y)
{
	if (x < y)
		return (x);
	return (y);
}
