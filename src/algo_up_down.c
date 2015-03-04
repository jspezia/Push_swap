#include "push_swap.h"

static void		loop(t_ps *ps, int min, t_stack_node *n_a, t_stack_node *n_b)
{
	if (n_b && CURR_VAL(n_b) < CURR_VAL(n_a) && NEXT_VAL(n_a) != min)
	{
		while (n_b && CURR_VAL(n_b) < CURR_VAL(n_a) && CURR_VAL(n_a) != min
			&& ps->total_ops < MAX_OPS)
		{
			OP(PA);
			OP(RA);
			n_b = FIRST(ps->stack_b);
		}
	}
	else if (n_b && CURR_VAL(n_b) > CURR_VAL(n_a) && NEXT_VAL(n_a)
		&& NEXT_VAL(n_a) != min && CURR_VAL(n_a) > NEXT_VAL(n_a))
		OP(PB);
	else if (n_a->next && NEXT_VAL(n_a) != min
		&& (CURR_VAL(n_a) > NEXT_VAL(n_a)))
	{
		if (!n_b || CURR_VAL(n_a) > CURR_VAL(n_b))
			OP(PB);
		else
			OP(RA);
	}
	else
		OP(RA);
}

static void		ran_b(t_ps *ps)
{
	t_stack_node	*node_b;

	node_b = FIRST(ps->stack_b);
	while (node_b && ps->total_ops < MAX_OPS)
	{
		OP(PA);
		OP(RA);
		node_b = FIRST(ps->stack_b);
	}
}

void			up(t_ps *ps, int min)
{
	t_stack_node	*node_a;
	t_stack_node	*node_b;

	node_a = FIRST(ps->stack_a);
	node_b = FIRST(ps->stack_b);
	if (CURR_VAL(node_a) == min)
		OP(RA);
	node_a = FIRST(ps->stack_a);
	node_b = FIRST(ps->stack_b);
	while (CURR_VAL(node_a) != min && ps->total_ops < MAX_OPS)
	{
		loop(ps, min, node_a, node_b);
		node_a = FIRST(ps->stack_a);
		node_b = FIRST(ps->stack_b);
	}
	ran_b(ps);
	node_a = FIRST(ps->stack_a);
	while (CURR_VAL(node_a) != min && ps->total_ops < MAX_OPS)
	{
		OP(RA);
		node_a = FIRST(ps->stack_a);
	}
}

void			up_down(t_ps *ps)
{
	int		min;

	min = find_min(ps->stack_a);
	while (!is_resolved(ps) && ps->total_ops < MAX_OPS)
		up(ps, min);
}
