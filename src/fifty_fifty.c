#include "push_swap.h"

void			fill_stack_b(t_op ops[OPS_LEN], t_ps *ps)
{
	int		count;

	count = 0;
	while (count < COUNT(ps->stack_a) / 2)
	{
		call_op(PB, ops, ps);
		count++;
	}
}

void			fifty_fifty(t_op ops[OPS_LEN], t_ps *ps)
{
	t_dlist_node	*node_a;
	t_dlist_node	*node_b;
	int				min_a;
	int				min_b;

	fill_stack_b(ops, ps);

	min_a = find_min(ps->stack_a->first);
	min_b = find_min(ps->stack_b->first);
	while (!is_stack_sorted(ps->stack_b))
	{
		node_a = FIRST(ps->stack_a);
		node_b = FIRST(ps->stack_b);
		if (NEXT_VAL(node_a) == min_a && NEXT_VAL(node_b) == min_b)
		 	call_op(RR, ops, ps);
		else if (NEXT_VAL(node_a) == min_a)
			call_op(RA, ops, ps);
		else if (NEXT_VAL(node_b) == min_b)
		 	call_op(RB, ops, ps);
		//**********
		else if (CURR_VAL(node_a) > NEXT_VAL(node_a) && CURR_VAL(node_b) > NEXT_VAL(node_b))
			call_op(SS, ops, ps);
		else if (CURR_VAL(node_a) > NEXT_VAL(node_a))
			call_op(SA, ops, ps);
		else if (CURR_VAL(node_b) > NEXT_VAL(node_b))
			call_op(SB, ops, ps);
		//**********
		else if (!is_stack_sorted(ps->stack_a))
			call_op(RR, ops, ps);
		else
			call_op(RRB, ops, ps);
	}
	ft_putendl("stack_b sorted !");
	while (!is_stack_sorted(ps->stack_a))
	{
		node_a = FIRST(ps->stack_a);
		if (NEXT_VAL(node_a) == min_a)
			call_op(RA, ops, ps);
		else if (CURR_VAL(node_a) > NEXT_VAL(node_a))
			call_op(SA, ops, ps);
		else
			call_op(RA, ops, ps);
	}
	ft_putendl("stack_a sorted !");
	node_b = FIRST(ps->stack_b);
	while (node_b)
	{
		node_a = FIRST(ps->stack_a);
		if (CURR_VAL(node_a) > CURR_VAL(node_b))
			call_op(PA, ops, ps);
		else if (CURR_VAL(node_a) < CURR_VAL(node_b))
		{
			call_op(RA, ops, ps);
			node_a = FIRST(ps->stack_a);
			min_a = find_min(ps->stack_a->first);
			if (NEXT_VAL(node_a) == min_a && !(CURR_VAL(node_a) > CURR_VAL(node_b)))
			{
				while (node_b)
				{
					call_op(RA, ops, ps);
					call_op(PA, ops, ps);
					node_b = FIRST(ps->stack_b);
				}
			}
		}
		node_b = FIRST(ps->stack_b);
	}
	while (!is_stack_sorted(ps->stack_a))
		call_op(RA, ops, ps);
}



























