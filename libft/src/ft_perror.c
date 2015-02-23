/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 15:58:53 by jspezia           #+#    #+#             */
/*   Updated: 2015/02/23 18:14:09 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	ft_perror(const char *msg)
{
	extern const int		errno;
	extern const char		*sys_errlist[];

	if (msg)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(sys_errlist[errno], 2);
}

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
