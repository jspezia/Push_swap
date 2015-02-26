#include "push_swap.h"

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
	while (CURR_VAL(node_a) != min)
	{
		if (node_b && CURR_VAL(node_b) < CURR_VAL(node_a) && NEXT_VAL(node_a) != min)
		{
			while (node_b && CURR_VAL(node_b) < CURR_VAL(node_a) && CURR_VAL(node_a) != min)
			{
				OP(PA);
				OP(RA);
				node_b = FIRST(ps->stack_b);
			}
		}
		else if (node_b && CURR_VAL(node_b) > CURR_VAL(node_a) && NEXT_VAL(node_a) && NEXT_VAL(node_a) != min && CURR_VAL(node_a) > NEXT_VAL(node_a))
			OP(PB);
		else if (node_a->next && NEXT_VAL(node_a) != min && (CURR_VAL(node_a) > NEXT_VAL(node_a)))
		{
			if (!node_b || CURR_VAL(node_a) > CURR_VAL(node_b))
				OP(PB);
			else
				OP(RA);
		}
		else
			OP(RA);
		node_a = FIRST(ps->stack_a);
		node_b = FIRST(ps->stack_b);
	}
	while (node_b)
	{
		OP(PA);
		OP(RA);
		node_b = FIRST(ps->stack_b);
	}
	node_a = FIRST(ps->stack_a);
	while (CURR_VAL(node_a) != min)
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
