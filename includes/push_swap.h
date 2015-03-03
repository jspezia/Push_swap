#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "dlist.h"
# include "ps_mlx.h"
# include "keys.h"
# include "color.h"
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

/*
**		OPTIONS
*/
# define OPT_STR		"hvcig::a:t:"
# define OPT(X)			(ps->options & X)

enum
{
	OPT_VERBOSE = 1 << 0,
	OPT_COLOR = 1 << 1,
	OPT_INTERACTIVE = 1 << 2,
	OPT_TIME = 1 << 3,
	OPT_ALGO = 1 << 4,
	OPT_GRAPHIC = 1 << 5
};

/*
**		USAGE
*/
# define USAGE			"./push_swap" USAGE_OPTS USAGE_ARGS
# define USAGE_OPTS		" [-hvci] [-g [mode]] [-a algo] [-t delay] --"
# define USAGE_ARGS		" <int> <int> <...>"

/*
**		STACK MACROS
*/
# define FIRST(X)		(X->first)
# define LAST(X)		(X->last)
# define COUNT(X)		(X->count)
# define CURR_VAL(X)	(*(int *)X->value)
# define NEXT_VAL(X)	(*(int *)X->next->value)
# define PREV_VAL(X)	(*(int *)X->prev->value)

/*
**		GRAPHIC MODE
*/
# define PALETTE_SIZE	300
# define STACK_COL1		COL_RED
# define STACK_COL2		COL_BLUE
# define G_MODE(X)		(ps->graphic_mode == X)
# define EXIT_DELAY		10
/*
**		OPS
*/

# define OP(X)			(call_op(X, ps))
# define MAX_OPS		1000000000

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

extern const t_op		g_ops[OPS_LEN];

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

typedef t_dlist			t_stack;
typedef t_dlist_node	t_stack_node;

typedef	struct		s_ps
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			*origin_data;
	int			algo;
	int			final_algo;
	char		options;
	int			total_ops;
	int			op_sleep;
	int			graphic_mode;
	int			range_min;
	int			range_max;
	int			range;
	size_t		total_elem;
}					t_ps;

/*
**		ALGO
*/
typedef struct		s_algo
{
	char		*name;
	void		(*f)(t_ps *ps);
}					t_algo;

enum
{
	BBS,
	FF,
	UP,
	SE,
	ME,
	IM,
	ALGOS_LEN
};

extern const t_algo	g_algos[ALGOS_LEN];

void			bubble_sort(t_ps *ps);
void			select_sort(t_ps *ps);
void			fifty_fifty(t_ps *ps);
void			interactive_mode(t_ps *ps);
void			merge_sort(t_ps *ps);
void			up_down(t_ps *ps);

void			up(t_ps *ps, int min);

/*
**		resolve.c
*/
t_bool			is_resolved(t_ps *ps);
int				find_min(t_stack *stack);
void			call_op(int op, t_ps *ps);
void			resolve(t_ps *ps);

/*
**		check_sort.c
*/
t_bool			is_stack_sorted(t_stack *stack);
t_bool			is_stack_reverse_sorted(t_stack *stack);

/*
**		parser.c
*/
void			parse(t_ps *ps, int ac, char *av[]);

/*
**		options.c
*/
void			set_options(t_ps *ps, char opt);

/*
**		print.c
*/
void			print_stack(t_stack *dlist);
void			display_stacks(t_ps *ps);

#endif
