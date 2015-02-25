#include "push_swap.h"

void			fill_stack_b(t_op ops[OPS_LEN], t_ps *ps)
{
	int		count;
	int		count_a;

	count = 0;
	count_a = COUNT(ps->stack_a);
	while (count < count_a / 2)
	{
		OP(PB);
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
	min_a = FIRST(ps->stack_a) ? find_min(ps->stack_a) : 0;
	min_b = FIRST(ps->stack_b) ? find_min(ps->stack_b) : 0;
	while (!is_stack_sorted(ps->stack_b))
	{
		node_a = FIRST(ps->stack_a);
		node_b = FIRST(ps->stack_b);
		if (NEXT_VAL(node_b) == min_b)
		{
			if (NEXT_VAL(node_a) == min_a)
				OP(RR);
			else
				OP(RB);
		}
		else if (CURR_VAL(node_b) > NEXT_VAL(node_b))
		{
			if (CURR_VAL(node_a) > NEXT_VAL(node_a))
				OP(SS);
			else
				OP(SB);
		}
		else
		{
			// if (!is_stack_sorted(ps->stack_a))
			// 	OP(RR);
			// else
				OP(RB);
		}
		// node_a = FIRST(ps->stack_a);
		// node_b = FIRST(ps->stack_b);
		// if (NEXT_VAL(node_a) == min_a && NEXT_VAL(node_b) == min_b)
		//  	OP(RR);
		// else if (NEXT_VAL(node_a) == min_a)
		// 	OP(RA);
		// else if (NEXT_VAL(node_b) == min_b)
		//  	OP(RB);
		// else if (CURR_VAL(node_a) > NEXT_VAL(node_a) && CURR_VAL(node_b) > NEXT_VAL(node_b))
		// 	OP(SS);
		// else if (CURR_VAL(node_a) > NEXT_VAL(node_a))
		// 	OP(SA);
		// else if (CURR_VAL(node_b) > NEXT_VAL(node_b))
		// 	OP(SB);
		// else if (!is_stack_sorted(ps->stack_a))
		// 	OP(RR);
		// else
		// 	OP(RRs);
	}
	ft_putendl("stack_b sorted !");
	while (!is_stack_sorted(ps->stack_a))
	{
		node_a = FIRST(ps->stack_a);
		if (NEXT_VAL(node_a) == min_a)
			OP(RA);
		else if (CURR_VAL(node_a) > NEXT_VAL(node_a))
			OP(SA);
		else
			OP(RA);
	}
	ft_putendl("stack_a sorted !");
	node_b = FIRST(ps->stack_b);
	while (node_b)
	{
		node_a = FIRST(ps->stack_a);
		if (CURR_VAL(node_a) > CURR_VAL(node_b))
			OP(PA);
		else if (CURR_VAL(node_a) < CURR_VAL(node_b))
		{
			OP(RA);
			node_a = FIRST(ps->stack_a);
			min_a = find_min(ps->stack_a);
			if (NEXT_VAL(node_a) == min_a && !(CURR_VAL(node_a) > CURR_VAL(node_b)))
			{
				while (node_b)
				{
					OP(RA);
					OP(PA);
					node_b = FIRST(ps->stack_b);
				}
			}
		}
		node_b = FIRST(ps->stack_b);
	}
	while (!is_stack_sorted(ps->stack_a))
		OP(RA);
}



























