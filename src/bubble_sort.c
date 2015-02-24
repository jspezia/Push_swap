#include "push_swap.h"

void			bubble_sort(t_op ops[OPS_LEN], t_ps *ps)
{
	t_dlist_node	*cursor;
	int				min;

	min = 1;
	while (!is_sort(ps->stack_a) && ps->total_ops < MAX_OPS)
	{
		cursor = ps->stack_a->first;
		if (NEXT_VAL(cursor) == min)
			call_op(RA, ops, ps);
		else if (CURR_VAL(cursor) > NEXT_VAL(cursor))
			call_op(SA, ops, ps);
		else
			call_op(RA, ops, ps);
	}
}
