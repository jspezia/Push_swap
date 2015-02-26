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
