/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:02:16 by jspezia           #+#    #+#             */
/*   Updated: 2013/12/29 20:30:36 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcat(char *dest, char const *src)
{
	size_t	len;

	len = ft_strlen(dest);
	ft_strcpy(&dest[len], src);
	return (dest);
}
