#include "push_swap.h"

void			fifty_fifty(t_op ops[11], t_ps *ps)
{
	t_dlist_node	*node_a;
	t_dlist_node	*node_b;
	int				min_a;
	int				min_b;
	int				count;

	count = 0;
	while (count <= ps->stack_a->count / 2)
	{
		call_op(PB, ops, ps);
		count++;
	}
	min_a = find_min(ps->stack_a->first);
	min_b = find_min(ps->stack_b->first);
	while (!is_stack_reverse_sorted(ps->stack_b))
	{
		node_a = ps->stack_a->first;
		node_b = ps->stack_b->first;
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
			call_op(RB, ops, ps);
	}
	ft_putendl("stack_b sorted !");
	while (!is_stack_sorted(ps->stack_a))
	{
		node_a = ps->stack_a->first;
		if (NEXT_VAL(node_a) == min_a)
			call_op(RA, ops, ps);
		else if (CURR_VAL(node_a) > NEXT_VAL(node_a))
			call_op(SA, ops, ps);
		else
			call_op(RA, ops, ps);
	}
	ft_putendl("stack_a sorted !");
	node_b = ps->stack_b->first;
	while (node_b)
	{
		node_a = ps->stack_a->first;
		if (CURR_VAL(node_a) > CURR_VAL(node_b))
			call_op(PA, ops, ps);
		else
			call_op(RA, ops, ps);
		node_b = ps->stack_b->first;
	}
}



























