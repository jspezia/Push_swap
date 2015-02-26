#include "push_swap.h"

void			bubble_sort(t_ps *ps)
{
	t_dlist_node	*cursor;
	int				min;

	min = find_min(ps->stack_a);
	while (!is_resolved(ps) && ps->total_ops < MAX_OPS)
	{
		cursor = ps->stack_a->first;
		if (NEXT_VAL(cursor) == min || !(CURR_VAL(cursor) > NEXT_VAL(cursor)))
			OP(RA);
		else
			OP(SA);
	}
}

void			select_sort(t_ps *ps)
{
	t_dlist_node	*cursor_a;
	t_dlist_node	*cursor_b;
	int				min;

	min = find_min(ps->stack_a);
	while (!is_resolved(ps) && ps->total_ops < MAX_OPS)
	{
		cursor_a = ps->stack_a->first;
		cursor_b = ps->stack_b->first;
		if (cursor_b && ((CURR_VAL(cursor_b) < CURR_VAL(cursor_a)) || CURR_VAL(cursor_a) == min))
		{
			OP(PA);
			OP(RA);
		}
		else if (cursor_b && (CURR_VAL(cursor_b) > CURR_VAL(cursor_a)))
			OP(RA);
		else if (CURR_VAL(cursor_a) > NEXT_VAL(cursor_a))
			OP(PB);
		else
			OP(RA);
	}
}
