/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 15:58:53 by jspezia           #+#    #+#             */
/*   Updated: 2015/02/23 13:47:42 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	error_msg(char *msg)
{
	if (msg)
		ft_putendl_fd(msg, 2);
}

void	error_msg_exit(char *msg)
{
	error_msg(msg);
	exit(-1);
}
