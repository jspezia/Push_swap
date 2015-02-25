#include "push_swap.h"

static	void	up(t_op ops[OPS_LEN], t_ps *ps, int min)
{
	t_dlist_node	*node_a;
	t_dlist_node	*node_b;

	node_a = ps->stack_a->first;
	node_b = ps->stack_b->first;

	if (CURR_VAL(node_a) == min)
		OP(RA);
	node_a = ps->stack_a->first;
	node_b = ps->stack_b->first;
	while (CURR_VAL(node_a) != min)
	{
		if (node_b && CURR_VAL(node_b) < CURR_VAL(node_a) && NEXT_VAL(node_a) != min)
		{
			while (node_b && CURR_VAL(node_b) < CURR_VAL(node_a) && CURR_VAL(node_a) != min)
			{
				OP(PA);
				OP(RA);
				node_b = ps->stack_b->first;
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
		node_a = ps->stack_a->first;
		node_b = ps->stack_b->first;
	}
	while (node_b)
	{
		OP(PA);
		OP(RA);
		node_b = ps->stack_b->first;
	}
	node_a = ps->stack_a->first;
	while (CURR_VAL(node_a) != min)
	{
		OP(RA);
		node_a = ps->stack_a->first;
	}
}

void			up_down(t_op ops[OPS_LEN], t_ps *ps)
{
	int				min;

	min = find_min(ps->stack_a);
	while (!is_resolved(ps) && ps->total_ops < MAX_OPS)
	{
		up(ops, ps, min);
	}
}
