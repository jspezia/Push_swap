#include "push_swap.h"

static int		compt_waves(t_stack *stack)
{
	t_stack_node	*cursor;
	int				i;

	cursor = stack->first;
	i = 0;
	while (cursor->next)
	{
		if (CURR_VAL(cursor) > NEXT_VAL(cursor))
			i++;
		cursor = cursor->next;
	}
	return (i);
}

static int		compt_waves_reverse(t_stack *stack)
{
	t_stack_node	*cursor;
	int				i;

	i = 0;
	if (!(cursor = stack->first))
		return (i);
	i++;
	while (cursor->next)
	{
		if (CURR_VAL(cursor) < NEXT_VAL(cursor))
			i++;
		cursor = cursor->next;
	}
	return (i);
}

static void		fill_stack_a(t_ps *ps)
{
	t_stack_node	*node_a;
	t_stack_node	*node_a_last;
	t_stack_node	*node_b;

	node_a = FIRST(ps->stack_a);
	node_a_last = LAST(ps->stack_a);
	node_b = FIRST(ps->stack_b);
	while (node_b)
	{
		if (CURR_VAL(node_b) < CURR_VAL(node_a) &&
			CURR_VAL(node_b) > CURR_VAL(node_a_last))
			OP(PA);
		else if (CURR_VAL(node_b) < CURR_VAL(node_a) &&
			CURR_VAL(node_a) < CURR_VAL(node_a_last))
			OP(PA);
		else if (CURR_VAL(node_b) > CURR_VAL(node_a) &&
			CURR_VAL(node_a) < CURR_VAL(node_a_last)
			&& CURR_VAL(node_b) > CURR_VAL(node_a_last))
			OP(PA);
		else
			OP(RRA);
		node_b = FIRST(ps->stack_b);
		node_a = FIRST(ps->stack_a);
		node_a_last = LAST(ps->stack_a);
	}
}

void			merge_sort(t_ps *ps)
{
	t_stack_node	*node_a;
	int				waves_a;
	int				waves_b;

	waves_b = 0;
	while (!is_resolved(ps) && ps->total_ops < MAX_OPS)
	{
		waves_a = compt_waves(ps->stack_a);
		while (waves_a + 1 > waves_b)
		{
			OP(PB);
			waves_a = compt_waves(ps->stack_a);
			waves_b = compt_waves_reverse(ps->stack_b);
		}
		fill_stack_a(ps);
		node_a = FIRST(ps->stack_a);
		while (CURR_VAL(node_a) > CURR_VAL(ps->stack_a->last))
		{
			OP(RRA);
			node_a = FIRST(ps->stack_a);
		}
		waves_a = compt_waves(ps->stack_a);
		waves_b = compt_waves_reverse(ps->stack_b);
	}
}
