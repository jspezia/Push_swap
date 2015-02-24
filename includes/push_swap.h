/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:49:56 by jspezia           #+#    #+#             */
/*   Updated: 2015/02/24 11:49:59 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "dlist.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h> // !!!

/*
**		COLOR
*/
# define RED		"31"
# define GREEN		"32"
# define YELLOW		"33"
# define BLUE		"34"
# define PINK		"35"
# define GRBL		"36"
# define GREY		"37"
# define NO			"0"
# define C(X)		"\033["X"m"
# define CC(X)		"\033[3"X"m"
# define CB(X)		"\x1B[48;1;"X"m"
# define CBNO		"\x1B[0m"

enum				opts
{
	OPT_VERBOSE = 1 << 0,
	OPT_COLOR = 1 << 1,
	OPT_INTERACTIVE = 1 << 2
};

void		*g_last1;
void		*g_last2;

typedef	struct		s_ps
{
	t_dlist		*stack_a;
	t_dlist		*stack_b;
	char		options;
}					t_ps;

typedef struct		s_op
{
	char		*name;
	void		(*f)(t_ps *ps);
}					t_op;

/*
**		ops
*/
void			sa(t_ps *ps);
void			sb(t_ps *ps);
void			ss(t_ps *ps);
void			pa(t_ps *ps);
void			pb(t_ps *ps);
void			ra(t_ps *ps);
void			rb(t_ps *ps);
void			rr(t_ps *ps);
void			rra(t_ps *ps);
void			rrb(t_ps *ps);
void			rrr(t_ps *ps);

/*
**		parser.c
*/
void			parse(t_ps *ps, int ac, char *av[]);

/*
**		print.c
*/
void			print_stack(t_dlist *dlist);
void			display_stacks(t_ps *ps);


#endif
