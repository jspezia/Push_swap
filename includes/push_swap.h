#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "dlist.h"
# include "ps_mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include <stdio.h> // !!!

/*
**		COLOR
*/
# define RED			"31"
# define GREEN			"32"
# define YELLOW			"33"
# define BLUE			"34"
# define PINK			"35"
# define GRBL			"36"
# define GREY			"37"
# define NO				"0"
# define C(X)			"\033["X"m"
# define CC(X)			"\033[3"X"m"
# define CB(X)			"\x1B[48;1;"X"m"
# define CBNO			"\x1B[0m"

enum
{
	OPT_VERBOSE = 1 << 0,
	OPT_COLOR = 1 << 1,
	OPT_INTERACTIVE = 1 << 2,
	OPT_TIME = 1 << 3,
	OPT_ALGO = 1 << 4
};

# define USAGE			"./push_swap" USAGE_OPTS USAGE_ARGS
# define USAGE_OPTS		" [-hvci] [-a algo] [-t delay] --"
# define USAGE_ARGS		" <int> <int> <...>"

# define MAX_OPS		10000000
# define OP_SLEEP		1

# define FIRST(X)		(X->first)
# define LAST(X)		(X->last)
# define COUNT(X)		(X->count)
# define CURR_VAL(X)	(*(int *)X->value)
# define NEXT_VAL(X)	(*(int *)X->next->value)
# define PREV_VAL(X)	(*(int *)X->prev->value)

# define OP(X)			(call_op(X, ops, ps))

# define OPT_STR		"hvcia:t:"

typedef	struct		s_ps
{
	t_dlist		*stack_a;
	t_dlist		*stack_b;
	int			algo;
	char		options;
	int			total_ops;
	int			op_sleep;
}					t_ps;

/*
**		ops
*/
typedef struct		s_op
{
	char		*name;
	void		(*f)(t_ps *ps);
}					t_op;

enum
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OPS_LEN
};

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
**		algos
*/
typedef struct		s_algo
{
	char		*name;
	void		(*f)(t_op ops[OPS_LEN], t_ps *ps);
}					t_algo;

enum
{
	BBS,
	FF,
	UP,
	IM,
	ALGOS_LEN
};

void			bubble_sort(t_op ops[OPS_LEN], t_ps *ps);
void			fifty_fifty(t_op ops[OPS_LEN], t_ps *ps);
void			interactive_mode(t_op ops[OPS_LEN], t_ps *ps);
void			up_down(t_op ops[OPS_LEN], t_ps *ps);

/*
**		resolve.c
*/
t_bool			is_resolved(t_ps *ps);
int				find_min(t_dlist *stack);
void			resolve(t_op ops[OPS_LEN], t_ps *ps, t_algo *algo);
void			call_op(int op, t_op ops[OPS_LEN], t_ps *ps);

/*
**		check_sort.c
*/
t_bool			is_stack_sorted(t_dlist *stack);
t_bool			is_stack_reverse_sorted(t_dlist *stack);

/*
**		parser.c
*/
void			parse(t_ps *ps, t_algo algos[ALGOS_LEN], int ac, char *av[]);

/*
**		options.c
*/
void			set_options(t_ps *ps, t_algo algos[ALGOS_LEN], char opt);

/*
**		print.c
*/
void			print_stack(t_dlist *dlist);
void			display_stacks(t_ps *ps);

#endif
