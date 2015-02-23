/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 10:53:03 by jspezia           #+#    #+#             */
/*   Updated: 2015/02/23 13:34:21 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isint(char *str)
{
	char	*max_int;
	char	*min_int;

	max_int = "2147483647";
	min_int = "2147483648";
	if (str == NULL)
		return (0);
	if (ft_str_isdigit(str) && ft_strlen(str) <= 10)
	{
		if (ft_strcmp(max_int, str) < 0 && ft_strlen(str) == 10)
			return (0);
		return (1);
	}
	else if (*str == '-' && ft_str_isdigit(++str) && ft_strlen(str) <= 10)
	{
		if (ft_strcmp(min_int, str) < 0 && ft_strlen(str) == 10)
			return (0);
		return (1);
	}
	return (0);
}
