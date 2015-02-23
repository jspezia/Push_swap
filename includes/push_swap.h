/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:49:56 by jspezia           #+#    #+#             */
/*   Updated: 2015/02/23 16:14:32 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "dlist.h"

typedef struct		s_list_ps
{
	t_dlist		*a;
	t_dlist		*b;
}					t_list_ps;

void		sa(t_dlist *dlist);

/*
**		print.c
*/
void		ft_print_dlist(t_dlist *dlist, char *str);
void		ft_print_dlist2(t_list_ps *list);

/*
**		init.c
*/
t_dlist		*parse(char **av, t_dlist *dlist);
t_list_ps	*init_list(void);


#endif
