/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:49:56 by jspezia           #+#    #+#             */
/*   Updated: 2015/02/23 19:11:07 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "dlist.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h> //

typedef	struct		s_ps
{
	t_dlist		*stack_a;
	t_dlist		*stack_b;
}					t_ps;

typedef struct		s_op
{
	char		*name;
	void		(*f)(t_ps *ps);
}					t_op;

/*
**		ops
*/
void		sa(t_ps *ps);
void		sb(t_ps *ps);
void		ss(t_ps *ps);
void		pa(t_ps *ps);
void		pb(t_ps *ps);
void		ra(t_ps *ps);
void		rb(t_ps *ps);
void		rr(t_ps *ps);
void		rra(t_ps *ps);
void		rrb(t_ps *ps);
void		rrr(t_ps *ps);

/*
**		print.c
*/
void		ft_print_dlist(t_dlist *dlist);

/*
**		parser.c
*/
void		fill_stack(t_dlist *stack, char *av[]);

#endif
