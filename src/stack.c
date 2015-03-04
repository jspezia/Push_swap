#include "push_swap.h"

int				find_min(t_stack *stack)
{
	int				min;
	t_stack_node	*cursor;

	cursor = FIRST(stack);
	min = cursor ? CURR_VAL(cursor) : 0;
	while (cursor)
	{
		min = fmin(min, CURR_VAL(cursor));
		cursor = cursor->next;
	}
	return (min);
}

void			push_stack(t_ps *ps)
{
	size_t	i;

	if (ps->stack_a)
		dlist_destroy(ps->stack_a);
	if (ps->stack_b)
		dlist_destroy(ps->stack_b);
	ps->stack_a = dlist_create();
	ps->stack_b = dlist_create();
	i = 0;
	while (i < ps->total_elem)
	{
		dlist_push_back(ps->stack_a, &(ps->origin_data[i]));
		i++;
	}
}
