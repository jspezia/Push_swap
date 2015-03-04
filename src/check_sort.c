#include "push_swap.h"

t_bool			is_stack_sorted(t_stack *stack)
{
	t_stack_node	*cursor;

	cursor = stack->first;
	while (cursor && cursor->next)
	{
		if (CURR_VAL(cursor) > NEXT_VAL(cursor))
			return (FALSE);
		cursor = cursor->next;
	}
	return (TRUE);
}

t_bool			is_stack_reverse_sorted(t_stack *stack)
{
	t_stack_node	*cursor;

	cursor = stack->first;
	while (cursor && cursor->next)
	{
		if (CURR_VAL(cursor) < NEXT_VAL(cursor))
			return (FALSE);
		cursor = cursor->next;
	}
	return (TRUE);
}
